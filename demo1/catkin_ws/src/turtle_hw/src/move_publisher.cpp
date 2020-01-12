/*
Publish chatter msg, string type
*/

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

int main(int argc , char** argv)
{

  ros::init(argc,argv,"move_publisher");
  
  ros::NodeHandle n;

  ros::Publisher move_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
  //ros::Publisher pos_pub = n.advertise<turtlesim::Pose>("/turtle1/pose",1000);

  ros::Rate loop_rate(10);

  while(ros::ok())
  {
  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;

  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 1.0;

  move_pub.publish(msg);



  loop_rate.sleep(); 

  }

   return 0;
}

