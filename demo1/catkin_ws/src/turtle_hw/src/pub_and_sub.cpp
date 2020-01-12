/*
Publish chatter msg, string type
*/

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
  // Print received info
  ROS_INFO("Turtle Pose: X-[%f]; Y-[%f]", msg->x, msg->y);
}

int main(int argc , char** argv)
{

  ros::init(argc,argv,"move_publisher");
  
  ros::NodeHandle n;

  //Create Publisher, publish turtle1/cmd-vel topic. msg type： Geometry_msgs::Twist
  ros::Publisher move_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
  //ros::Publisher pos_pub = n.advertise<turtlesim::Pose>("/turtle1/pose",1000);

  //Create Subscriber, subscribe turtle1/cmd-vel use Callback function
  ros::Subscriber pose_sub = n.subscribe<geometry_msgs::Twist>("/turtle1/pose",1000,poseCallback);

  //ros loop
  ros::Rate loop_rate(10);


  while(ros::ok())
  {

  //Initialize geometry::Twist message
  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;
  msg.angular.z = 1.0;

  move_pub.publish(msg);

  //loop wait for the callback
  ros::spinOnce();  // look up only once callback func

  // loop delay
  loop_rate.sleep(); 

  }

   return 0;
}