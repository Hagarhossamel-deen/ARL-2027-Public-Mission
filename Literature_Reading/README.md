# Literature Reading Mission
You are required to read, digest and understand the paper provided, then submit a presentation that can be covered in 5-7 mins.
You will present this presentation in the interview, where it will be discussed further.
Provided below are the bare minimum guidelines to help you get an idea of what we atleast expect.

You don't necessarily have to explain all points within the 7 minute presentation, but the further discussion may cover all points and beyond.


## Guidelines

### Perception Lidar
the candidate should at least understand the following:
- the basic LiDAR perception pipeline
- understand how distortions can be caused in a single lidar point cloud frame due to vehicle movement if not accounted for (VERY IMPORTANT)
- how the cone colour can be estimated from light intensity in point cloud
- why cluster reconstruction is necessary

### Perception Camera
the candidate should at least understand the following:
- the basic camera perception pipeline
- key differences between the monocular and stereo pipelines
- how the system obtains 3D cone positions from camera data (The idea of CNNs and keypoints)
- how matching happens between the 2 frames in stereo 

### Perception Module as a Whole
- why sensor redundancy is important (both camera and lidar)
- the main perception results and what they demonstrate

### Velocity Estimation
the candidate should at least understand the following:
- why the car needs to estimate its own motion/state/velocity
- the purpose of sensor fusion/ sensor redundancy (specifically here separate to the perception one)
- the basic idea of EKF
- why sensor measurements cannot simply be trusted individually 
- outliers vs drift over time

### SLAM & Mapping
the candidate should at least understand the following:
- why SLAM is necessary when the track is initially unknown/ what SLAM is trying to solve in general
- the idea that this is a data association problem of trying to correspond observed to mapped
- the basic idea behind FastSLAM 2.0 
- idea of lap closure + what occurs after it 

### Planning
the candidate should at least understand the following:
- how to use triangulation of cones to define candidate paths
- how a cost function scores the path and depending on which variables

### Control
the candidate should at least understand the following:
- why simply following the track center is not necessarily optimal for racing
- the basic idea of MPC
- the basic idea of the bicycle model

### Testing & Simulation 
the candidate should at least understand the following:
- why simulation is used before testing on the real car 
- the purpose of the automated testing system (ATS)
- the importance of logging and analyzing large amounts of test data

## Deliverable
A `.pptx` or `.pdf` of your presentation. Feel free to add any additional documents such as your notes, hand-written or not.

Again, you may be asked and evaluated on ideas in the paper that aren't included in the guidelines, as these guidelines are the bare minimum.

## AI Usage
No causes for immediate disqualifciation here, just make sure to note down how you used it.
