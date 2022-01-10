In order to run the program, you only need to:
./home_service_1.sh 

Steps:

1. At first, home_service_1.sh will lunch turtlebot_gazebo with the selected world and also determine the robot initial position.
2. amcl_demo will be lunch with the selected map.
3. view_navigation.launch from turtlebot_ rviz_ launchers package will be lunched.
4. Add_marker package will be lunch to creat a blue cube at the pickup point and when the robot picked the cube it will be deleted and when the robot get to the drop off point, the cube will be appear at the drop off point.
5. Pick_object package will send the robot to the pickup point, wait for 5 second and then send the robot to the drop off point.