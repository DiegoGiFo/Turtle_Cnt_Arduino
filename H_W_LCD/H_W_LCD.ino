/*
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */

/*
void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
*/

// include the library code:
#include <LiquidCrystal.h>
#include <ros.h>
#include <turtlesim/Pose.h>

ros::NodeHandle  nh; // allows to create publisher/subscriber
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char LCD_msg[16];
float var;

void turt_cb( const turtlesim::Pose &turt_msg){
  lcd.setCursor(0,0);
  lcd.print("X position :");
  lcd.print(turt_msg.x);

  lcd.setCursor(0,1);
  lcd.print("Y position :");
  lcd.print(turt_msg.y);
}

ros::Subscriber<turtlesim::Pose> sub("/turtle1/pose", &turt_cb);

// initialize the library with the numbers of the interface pins


void setup() {
  nh.initNode(); // initialize ROS node
  nh.subscribe(sub); // advertise that we have a publisher

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("%f %f",turtle_pos.x, turtle_pos.y);
}

void loop() {
  nh.spinOnce();
}
