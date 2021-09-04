#!/bin/sh
xterm  -e  'source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="$(rospack find turtlebot_gazebo)/worlds/corridor.world"' &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" 
