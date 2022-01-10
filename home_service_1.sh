#!/bin/sh
xterm  -e  'source /home/workspace/catkin_ws/devel/setup.bash; export ROBOT_INITIAL_POSE="-x 5 -y -5 -Y 0";roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="$(rospack find my_robot)/worlds/World-robot-building-1"' &
sleep 10
xterm  -e  'source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:="$(rospack find my_robot)/map/map.yaml"' &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; rosrun add_markers add_markers_node" &
sleep 1
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; rosrun pick_objects pick_objects_node"

 
