/*
string client service, string type print
*/

#include "ros/ros.h"
#include <cstdlib>
#include <ctime>
#include <turtlesim/Spawn.h>

int main(int argc , char** argv)
{

  ros::init(argc,argv,"client_generate_turtleWithParameter");

  if (argc!=2)
  {
    ROS_INFO("Please input the turtle's name behind the command");
    return 1;
  }
  
  ros::NodeHandle n;

  ros::ServiceClient spawn_client = n.serviceClient<turtlesim::Spawn>("/spawn");

  //Create turtlesim::Spawn Srv
  turtlesim::Spawn srv;
  
  srand(static_cast<unsigned int>(time(NULL)));
  srv.request.x=float(rand())/float(RAND_MAX)*11;
  srv.request.y=float(rand())/float(RAND_MAX)*12;
  srv.request.theta=0;
  srv.request.name=argv[1];


  if (spawn_client.call(srv))
  {
     ROS_INFO_STREAM("The new turtle named %s is spawned", srv.response.name.c_str());
  }
  else
  {
     ROS_ERROR_STREAM("Failed to call Spawn a new Turtle");
     return 1;
  }

   return 0;
}