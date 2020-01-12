/*
string client service, string type print
*/

#include <ros/ros.h>
#include <cstdlib>
#include <turtlesim/Spawn.h>
#include <std_msgs/String.h>

int main(int argc , char** argv)
{

  ros::init(argc,argv,"cmd_birth_client");
  
  ros::NodeHandle n;

  ros::ServiceClient cmd_birth_client = n.serviceClient<turtlesim::Spawn>("spawn");

  turtlesim::Spawn::Request req;
  turtlesim::Spawn::Response res;
  
  std::string inputString_Name;
  std::cout<< "Please input Name : ";
  std::getline(std::cin, inputString_Name);
  req.name=inputString_Name;

  std::string inputString_x;
  std::cout<< "Please input x : ";
  std::getline(std::cin, inputString_x);
  float f_x=atof(inputString_x.c_str());
  req.x=f_x;

  
  std::string inputString_y;
  std::cout<< "Please input y : ";
  std::getline(std::cin, inputString_y);
  float f_y=atof(inputString_y.c_str());
  req.y=f_y;

  std::string inputString_theta;
  std::cout<< "Please input theta : ";
  std::getline(std::cin, inputString_theta);
  float f_theta=atof(inputString_theta.c_str());
  req.theta=f_theta;

 
  if (cmd_birth_client.call(req, res))
  {
     ROS_INFO_STREAM("The new turtle is spawned with the name : "<<req.name);
  }
  else
  {
     ROS_ERROR_STREAM("Failed to call Spawn a new Turtle");
  }

   return 0;
}

