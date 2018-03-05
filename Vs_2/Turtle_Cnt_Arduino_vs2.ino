#include <LiquidCrystal.h>
#include <ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh; // allows to create publisher/subscriber

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
geometry_msgs::Twist movements;

char LCD_msg[16];
float var;

const int BtPin1 = 6;
const int BtPin2 = 7;
const int BtPin3 = 8;
const int BtPin4 = 9;

int RGT = 0;
int LFT = 0;
int FWD = 0;
int BEH = 0;

void turt_cb( const turtlesim::Pose &turt_msg){
  lcd.setCursor(0,0);
  lcd.print("X position :");
  lcd.print(turt_msg.x);

  lcd.setCursor(0,1);
  lcd.print("Y position :");
  lcd.print(turt_msg.y);
}

ros::Subscriber<turtlesim::Pose> sub("/turtle1/pose", &turt_cb);
ros::Publisher pub("/turtle1/cmd_vel", &movements);
// initialize the library with the numbers of the interface pins


void setup() {

  nh.initNode(); // initialize ROS node
  nh.subscribe(sub); // advertise that we have a publisher
  nh.advertise(pub);

  pinMode(BtPin1, INPUT);
  pinMode(BtPin2, INPUT);
  pinMode(BtPin3, INPUT);
  pinMode(BtPin4, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("%f %f",turtle_pos.x, turtle_pos.y);
}

void loop() {

  RGT = digitalRead(BtPin1);
  LFT = digitalRead(BtPin2);
  FWD = digitalRead(BtPin3);
  BEH = digitalRead(BtPin4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (RGT == HIGH) {
    movements.linear.x = 0;
    movements.angular.z= 1.57;
    pub.publish( &movements );
    delay(1000);
    movements.linear.x = 2;
    movements.angular.z= 0;
    pub.publish( &movements );

  }

  else if(LFT == HIGH) {
    movements.linear.x = 0;
    movements.angular.z= -1.57;
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
  nh.spinOnce();
}
