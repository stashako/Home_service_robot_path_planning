#!/bin/sh
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; rosrun pick_objects pick_objects_node" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; rosrun add_markers add_markers_node" 
