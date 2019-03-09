# Extended Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program
![result](result.png)
I use a Kalman filter, lidar measurements and radar measurements to track the bicycle's position and velocity.

To see the picture, we will find some symbols. They have their means.
Lidar measurements are red circles, radar measurements are blue circles with an arrow pointing in the direction of the observed angle, and estimation markers are green triangles.

### Files in the Github src Folder
The files you need to work with are in the src folder of the github repository.
* main.cpp - communicates with the Term 2 Simulator receiving data measurements, calls a function to run the Kalman filter, calls a function to calculate RMSE
* FusionEKF.cpp - initializes the filter, calls the predict function, calls the update function
* kalman_filter.cpp- defines the predict function, the update function for lidar, and the update function for radar
* tools.cpp- function to calculate RMSE and the Jacobian matrix
### Dependencies
* This project involve using an open source package called uWebSocketIO. We can use "install-ubuntu.sh" to install uWebSocketIO.  We recommend using the newest version of Ubunut Bash 16.04, which is able to run the "install-ubuntu.sh" script without complications.

### Extended Kalman Filter Simulator
* In the main menu screen select Project 1/2 EKF and UKF.
* Once the scene is loaded you can hit the START button to observe how the object moves and how measurement markers are positioned in the data set. Also for more experimentation, "Data set 2" is included which is a reversed version of "Data set 1", also the second data set starts with a radar measurement where the first data set starts with a lidar measurement. At any time you can press the PAUSE button, to pause the scene or hit the RESTART button to reset the scene. Also, the ARROW KEYS can be used to move the camera around, and the top left ZOOM IN/OUT buttons can be used to focus the camera. Pressing the ESCAPE KEY returns to the simulator main menu.