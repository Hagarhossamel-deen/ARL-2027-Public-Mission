
# perception lidar
the candidate should at least understand the following:
- the basic LiDAR perception pipeline
-  this one is very important,, understand how distortions can be caused in a single lidar point cloud frame due to vehicle movement if not accounted for
- how the cone colour can be estimated from light intensity in point cloud
- why cluster reconstruction is necessary

# perception camera
the candidate should at least understand the following:
- the basic camera perception pipeline
- key differences between the monocular and stereo pipelines
- how the system obtains 3D cone positions from camera data (The idea of CNNs and keypoints)
- how matching happens between the 2 frames in stereo 

# perception module as a whole
- why sensor redundancy is important (both camera and lidar)
- the main perception results and what they demonstrate

# velocity estimation
the candidate should at least understand the following:
- why the car needs to estimate its own motion/state/velocity
- the purpose of sensor fusion/ sensor redundancy (specifically here separate to the perception one)
- the basic idea of EKF
- why sensor measurements cannot simply be trusted individually (the idea of wheel slip/ deviation/ drift)
- outliers vs drift over time

# SLAM & mapping
the candidate should at least understand the following:
- why SLAM is necessary when the track is initially unknown/ what SLAM is trying to solve in general (build a map of cones and localize)
- the idea that this is a data association problem of trying to correspond observed to mapped
- the basic idea behind FastSLAM 2.0 (particle filter approach)
- idea of lap closure + what occurs after it (pure localization) 

# planning
the candidate should at least understand the following:
- how to use triangulation of cones to define candidate paths
- how a cost function scores the path and depending on which variables

# control
the candidate should at least understand the following:
- why simply following the track center is not necessarily optimal for racing
- the basic idea of MPC
- the basic idea of the bicycle model

# testing & simulation 
the candidate should at least understand the following:
- why simulation is used before testing on the real car (very important to us fsai in specific)
- the purpose of the automated testing system (ATS)
- the importance of logging and analyzing large amounts of test data

