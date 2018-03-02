
#include <ros.h>
#include <turtlesim/Pose.h>

ros::NodeHandle  nh; // allows to create publisher/subscriber

turtlesim::Pose turtle_pos;
ros::Publisher pub("/turtle1/pose", &turtle_pos);

int status = 0;
int count = 0;

void setup()
{
  nh.initNode(); // initialize ROS node
  nh.advertise(pub); // advertise that we have a publisher
}

void loop()
{
  turtle_pos.x = random(1,11);
  turtle_pos.y = random(1,11);
  turtle_pos.linear_velocity = 1.0;
  pub.publish( &turtle_pos ); //publish on chatter the string hello
  nh.spinOnce(); // where all of the ROS communication callbacks are handled
  delay(1000);
}
