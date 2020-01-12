/*
Subscrbe chatter msg, string type
*/

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iomanip>

void chatterCallback(const turtlesim::Pose& msg) // turtlesim:: Pose ???const turtlesim::Pose& msg  const geometry_msgs::Twist& msg
{

  ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=("<< msg.x <<","<< msg.y <<")" <<" *direction="<<msg.theta);
  //ROS_INFO_STREAM("The linear position x is : "<< msg.linear.x<< "The angular position z is :"<< msg.angular.z);
}

int main(int argc , char** argv)
{

  ros::init(argc,argv,"move_subscriber");
  
  ros::NodeHandle n;

  ros::Subscriber chatter_sub = n.subscribe("/turtle1/pose",1000, chatterCallback); 

  ros::spin();   

  return 0;
}

