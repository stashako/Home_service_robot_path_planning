#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

float x;
float y;
int state; // 0:pickup  1:moving   2:dropoff
float dis;

void odomCallback(const nav_msgs::OdometryConstPtr& odomMsgs)
{
    x = odomMsgs->pose.pose.position.x;
    y = odomMsgs->pose.pose.position.y;
}


float distance_points(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2,2));
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_marker_node");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("odom", 10,odomCallback);
  visualization_msgs::Marker marker;
  uint32_t shape = visualization_msgs::Marker::CUBE;

  float pickupX = 0;
  float pickupY = -2;

  float dropoffX = -2; 
  float dropoffY = 2;

  float distance;

  state = 0; //pickup

  while (ros::ok())
  {

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.ns = "add_marker_node";
    marker.id = 0;
    marker.type = shape;
    marker.action = visualization_msgs::Marker::ADD;

    if(state == 0){
    marker.pose.position.x = pickupX;
    marker.pose.position.y = pickupY;

    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    dis = distance_points(x, y, pickupX, pickupY);

      if(dis <0.1)
      {
         state = 1;
         ROS_INFO("pickup point");
      }
      marker_pub.publish(marker);
      marker.lifetime = ros::Duration();
    } 
    else if(state == 1)
    {
      dis = distance_points(x, y, dropoffX, dropoffY);
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
      marker.lifetime = ros::Duration();

      if(dis < 0.2)
        state = 2;
    }
    else 
    {
      marker.pose.position.x = dropoffX;
      marker.pose.position.y = dropoffY;
    
      marker.pose.position.z = 0;
      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;

      marker.scale.x = 0.3;
      marker.scale.y = 0.3;
      marker.scale.z = 0.3;

      marker.color.r = 0.0f;
      marker.color.g = 0.0f;
      marker.color.b = 1.0f;
      marker.color.a = 1.0;
    
      marker_pub.publish(marker);

      marker.lifetime = ros::Duration();


    }
    ros::spinOnce();
    r.sleep();
  }
}
