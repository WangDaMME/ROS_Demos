/*
string client service, string type print
*/

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc , char** argv)
{

  ros::init(argc,argv,"birth_client");
  
  ros::NodeHandle n;

  ros::ServiceClient birth_client = n.serviceClient<turtlesim::Spawn>("spawn");

  turtlesim::Spawn srv;
  srv.request.x=2;
  srv.request.y=2;
  srv.request.theta=2;
 
  if (birth_client.call(srv))
  {
     ROS_INFO("The new turtle named %s is spawned ",   srv.response.name.c_str());

  }
  else
  {
     ROS_ERROR_STREAM("Failed to call Spawn a new Turtle");
     return 1
  }

   return 0;
}