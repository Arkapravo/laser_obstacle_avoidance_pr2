laser_obstacle_avoidance_pr2
============================
Authors : Koushik Kabiraj (koushik.atti@gmail.com) and Arkapravo Bhaumik (arkapravobhaumik@gmail.com)

ROS node for laser obstacle avoidance for the PR2 robot in gazebo simulations

Running the node in Gazebo
--------------------------
pr2_gazebo package (http://ros.org/wiki/pr2_gazebo) must be installed for these simulations to run

There are 2 ways to run the simulations,

* using _launch1_pr2.launch_ 

(1) Start an instance of the master     
(2) Start the simulations with _roslaunch laser_obstacle_avoidance_pr2 launch1_pr2.launch_  
(3) Put in your own obstacles in the empty world    
(4) Start obstacle avoidance with _roslaunch laser_obstacle_avoidance_pr2 obs_pr2.launch_

![Image Alt](https://lh6.googleusercontent.com/-A7nduyn8cwg/URqCVGnHPtI/AAAAAAAACUk/vwScjbne894/s576/l.png) 

* using _launch2_pr2.launch_ 

(1) Start an instance of the master     
(2) Start the simulations with _roslaunch laser_obstacle_avoidance_pr2 launch2_pr2.launch_

![Image Alt](https://lh4.googleusercontent.com/-314C7cq5eBM/URqCVDcJqwI/AAAAAAAACUc/nFHaCWArhco/s576/j.png) 

Testing
-------
Successfully tested on ROS Fuerte 

