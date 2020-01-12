/*
Publish chatter msg, string type
*/

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <std_msgs/String.h>

int main(int argc , char** argv)
{

  std::string inputString_Name;
  std::cout<< "Please input Name you'd operate : ";
  std::getline(std::cin, inputString_Name);

  ros::init(argc,argv,inputString_Name+"move_publisher");
  
  ros::NodeHandle n;


  ros::Publisher move_pub = n.advertise<geometry_msgs::Twist>(inputString_Name+"/cmd_vel",1000);
  //ros::Publisher pos_pub = n.advertise<turtlesim::Pose>("/turtle1/pose",1000);
  
  std::string inputString_x;
  std::cout<< "Please input lienear velocity, x : ";
  std::getline(std::cin, inputString_x);
  float f_lx=atof(inputString_x.c_str());

  std::string inputString_z;
  std::cout<< "Please input angular velocity, z : ";
  std::getline(std::cin, inputString_z);
  float f_az=atof(inputString_x.c_str());


  ros::Rate loop_rate(10);

  while(ros::ok())
  {
  geometry_msgs::Twist msg;
  msg.linear.x = f_lx;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;

  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = f_az;

  move_pub.publish(msg);



  loop_rate.sleep(); 

  }

   return 0;
}

