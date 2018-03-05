/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

#include <ros.h>
#include <geometry_msgs/Twist.h>
ros::NodeHandle  nh; // allows to create publisher/subscriber

geometry_msgs::Twist movements;
ros::Publisher pub("/turtle1/cmd_vel", &movements);

// constants won't change. They're used here to set pin numbers:
const int BtPin1 = 6;     // the number of the pushbutton pin
const int BtPin2 = 7;
const int BtPin3 = 8;
const int BtPin4 = 9;
// variables will change:
int RGT = 0;
int LFT = 0;
int FWD = 0;
int BEH = 0;


void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(BtPin1, INPUT);
  pinMode(BtPin2, INPUT);
  pinMode(BtPin3, INPUT);
  pinMode(BtPin4, INPUT);

  // initialize the ros node
  nh.initNode(); // initialize ROS node
  nh.advertise(pub); // advertise that we have a publisher
}

void loop() {
  // read the state of the pushbutton value:
  RGT = digitalRead(BtPin1);
  LFT = digitalRead(BtPin2);
  FWD = digitalRead(BtPin3);
  BEH = digitalRead(BtPin4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (RGT == HIGH) {
    movements.linear.x = 0;
    movements.angular.z= 1.52  ;
    pub.publish( &movements );
    delay(1000);
    movements.linear.x = 2;
    movements.angular.z= 0;
    pub.publish( &movements );

  }

  else if(LFT == HIGH) {
    movements.linear.x = 0;
    movements.angular.z= -1.52;
    pub.publish( &movements );
    delay(1000);
    movements.linear.x = 2.0;
    movements.angular.z= 0;
    pub.publish( &movements );

  }

  else if (FWD == HIGH){
    movements.linear.x = 2.0;
    movements.angular.z= 0;
    pub.publish( &movements );
  }

  else if (BEH == HIGH){
    movements.linear.x = -2.0;
    movements.angular.z= 0;
    pub.publish( &movements );

  }

  nh.spinOnce(); // where all of the ROS communication callbacks are handled
}
