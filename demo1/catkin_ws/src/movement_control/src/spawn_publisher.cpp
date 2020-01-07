#include "ros/ros.h"
#include <string>
#include <geometry_msgs/Twist.h>


int main(int argc , char** argv)
{

  std::string turtle_name=argv[2];

  ros::init(argc,argv,turtle_name);

  if (argc!=3 && argc!=5)
  {
    ROS_INFO("Please input the 'stop' 'the name of turtle'
                        or
              Please input the 'start' 'the name of turtle' 'linear velocity' 'angular velocity' ")
  }
  
  ros::NodeHandle n;

  std::string vel_topic=turtle_name+"/cmd_vel"


  ros::Publisher velocity_circle_pub = n.advertise<geometry_msgs::Twist>(vel_topic,1000);


  ros::Rate loop_rate(10);

  while(ros::ok())
  {
    geometry_msgs::Twist msg;
    if (!strcmp(argv[1],"start" || strcmp(argv[1],"START"))){

       msg.linear.x = atol(argv[3]);
       msg.angular.z = atol(argv[4]);
       ROS_INFO("publish velocity:\nlinear.x %lf\nangular.z %lf",msg.linear.x,msg.angular.z);
       velocity_circle_pub.publish(msg);
    }
    else if (!strcmp(argv[1],"stop" || strcmp(argv[1],"STOP"))){

       msg.linear.x = 0.0;
       msg.angular.z = 0.0;
       ROS_INFO("stop");
       velocity_circle_pub.publish(msg);

    }
    else{
       ROS_INFO("Please input the right command 'start' or 'START' and 'stop' or 'STOP'");
       return 1;
    }

    loop_rate.sleep()
  }
  
  return 0;
}

