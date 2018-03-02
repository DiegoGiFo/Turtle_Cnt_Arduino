
#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh; // allows to create publisher/subscriber

geometry_msgs::Twist movements;
ros::Publisher pub("/turtle1/cmd_vel", &movements);

void setup()
{
  nh.initNode(); // initialize ROS node
  nh.advertise(pub); // advertise that we have a publisher
}

void loop()
{
  movements.linear.x = 2.0;
  movements.linear.y = 2.0;
  movements.angular.z = 2.0;
  pub.publish( &movements ); //publish on chatter the string hello
  nh.spinOnce(); // where all of the ROS communication callbacks are handled
  delay(1000);
}
