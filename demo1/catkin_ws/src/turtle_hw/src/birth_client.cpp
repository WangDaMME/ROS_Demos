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

  turtlesim::Spawn::Request req;
  turtlesim::Spawn::Response res;

  req.x=2;
  req.y=2;
  req.theta=2;
  req.name="Turtle_Ninja";
 
  if (birth_client.call(req, res))
  {
     ROS_INFO_STREAM("The new turtle is spawned with the name : "<<req.name);
  }
  else
  {
     ROS_ERROR_STREAM("Failed to call Spawn a new Turtle");
  }

   return 0;
}

