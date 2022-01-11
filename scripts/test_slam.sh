#!/bin/sh
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch my_robot world.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch my_robot my_robot_gmapping.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm  -e  "source /home/workspace/catkin_ws/devel/setup.bash; rosrun teleop_twist_keyboard teleop_twist_keyboard.py" 
