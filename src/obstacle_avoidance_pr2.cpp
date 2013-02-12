// Authors : Koushik Kabiraj (koushik.atti@gmail.com) and Arkapravo Bhaumik (arkapravobhaumik@gmail.com)
// Date : 12 February 2013
// Simple obstacle avoidance for the PR2 robot 


#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <geometry_msgs/Twist.h>
#include <stdio.h>

float min_range,min_range_angle;

ros::Publisher vel_pub;
geometry_msgs::Twist cmdvel;
void chatterCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
 // printf("Position: [%f] [%f]\n", msg->range_min,msg->range_max);
	min_range=msg->ranges[0];
	min_range_angle=0;
	for(int j=0;j<=360;j++) //increment by one degree
		{
		  	if(msg->ranges[j]<min_range)
			{
				min_range=msg->ranges[j];
				min_range_angle=j/2;
			}
		}
		printf("minimum range is [%f] at an angle of [%f]\n",min_range,min_range_angle);
	if(min_range<=1.2)  // min_range<=0.5 gave box pushing like behaviour, min_range<=1.2 gave obstacle avoidance
	{
		if(min_range_angle<90)
		{
			 cmdvel.angular.z=1.0;
			 cmdvel.linear.x=0;
			 printf("left\n");
		}
		else
		{
			 cmdvel.angular.z=-1.0;
			 cmdvel.linear.x=0;
			 printf("right\n");
		}
	}
	else
	{
		cmdvel.linear.x=1.0;
		cmdvel.angular.z=0;
		printf("straight\n");
	}
	 
	 vel_pub.publish(cmdvel);

}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "laser_messages");
  ros::NodeHandle n;
  ros::NodeHandle nh;
  vel_pub = nh.advertise<geometry_msgs::Twist>("base_controller/command",1);
  cmdvel.linear.x=0;
  cmdvel.linear.y=0;
  cmdvel.linear.z=0;
  cmdvel.angular.x=0;
  cmdvel.angular.y=0;
  cmdvel.angular.z=0; 

  ros::Subscriber sub = n.subscribe("base_scan", 1, chatterCallback);

  ros::spin();

  return 0;
}
