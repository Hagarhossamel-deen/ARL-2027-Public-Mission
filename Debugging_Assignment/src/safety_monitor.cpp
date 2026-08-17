#include "safety_monitor.hpp"
#include <optional> // to avoid crash when use optional in the return type
#include <cmath>

namespace arl {
namespace {

bool isFinite(const Detection& detection) {
    return std::isfinite(detection.forward)
        && std::isfinite(detection.left)
        && std::isfinite(detection.confidence);
}

}  // namespace

std::vector<Obstacle> processDetections(
    const std::vector<Detection>& detections,
    const RoverPose& pose,
    const SafetyConfig& config) {
    std::vector<Obstacle> obstacles;
    const double headingRadians = pose.headingDegrees *M_PI /180; //we must convert in from degrees to radians
    const double cosine = std::cos(headingRadians);
    const double sine = std::sin(headingRadians);

    for (std::size_t index = 0; index  < detections.size(); ++index) // we must take care  of the index to avoid missing the last index 
    {
        const auto& detection = detections[index];
        const double range = std::hypot(detection.forward, detection.left);
        const bool validConfidence = detection.confidence <=1.0 // to let the validConfidence works correctly we must have the confidence <=1.0 to be in the allowed range  and to take care of the detection.confidence 
    //it must be <= config.maximumRangeMeters
            && detection.confidence >= config.minimumConfidence;
        const bool validRange = range > 0.0 && range <= config.maximumRangeMeters;

        if (!isFinite(detection) || !validConfidence || !validRange) {
            continue;
        }

        obstacles.push_back({
            detection.id,
            detection.forward,
            detection.left,
            pose.worldX + cosine * detection.forward - sine * detection.left,// the correct eq. to  a 2D rotation transforming a point from the rover's body frame into the world frame
            pose.worldY + sine * detection.forward + cosine * detection.left,
            range,
        });
    }

    return obstacles;
}

std::optional<Obstacle> findNearestObstacle(const std::vector<Obstacle>& obstacles) {
    if (obstacles.empty()) {
        return std::nullopt;
    }

    const Obstacle* nearest = &obstacles.front();
    for (const auto& obstacle : obstacles) {
        if (obstacle.range <= nearest->range)// to be the nearst obstacle it must have a range  smaller than or equal the value that is already assigned to be the nearest
        {
            nearest = &obstacle;
        }
    }

    return *nearest;
}

double calculateStoppingDistance(double speedKph, const SafetyConfig& config) {
    const double speedMps = speedKph /3.6;// to convert from kilo meter per hour to meter per sec
    const double reactionDistance = speedMps * config.reactionTimeSeconds;
    const double brakingDistance = speedMps * speedMps
        / (2.0 * config.maximumDecelerationMps2);
    return reactionDistance + brakingDistance;
}

bool shouldEmergencyBrake //  we must see what obstacles are the nearsest and we must calculate the stopping distance (reactionDistance + brakingDistance)
// to be true we must have the range smaller than or equal stopping distance 
(
    const std::vector<Obstacle>& obstacles,
    double speedKph,
    const SafetyConfig& config) {

    const auto nearest = findNearestObstacle(obstacles);

    if (!nearest.has_value()) {
        return false;
    }

    const double stoppingDistance =
        calculateStoppingDistance(speedKph, config);

    return nearest->range <= stoppingDistance;
}

}  // namespace arl
