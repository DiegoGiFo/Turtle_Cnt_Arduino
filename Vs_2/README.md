# Turtlesim Controller

This version of the project allows to:

- Controll the simulator of ROS (turtlesim) with Arduino using 4 buttons;
- Receive the position of the turtle printing it on the LCD screen.

## TOPICS

 - Use of a publisher that publishes on the topic /turtle1/cmd_vel the movements value based on the button pressed;
 - Use of a subsriber that subscribes to the topic /turtle1/pose from which receives the position of the turtle and print it on the LCD screen.

## MATERIAL

For the relization of this projects is needed:

- Arduino uno;
- LCD screen 16 x 2;
- 4 buttons;![alt text](https://github.com/DiegoGiFo/Turtle_Cnt_Arduino/blob/master/FSB5Q9PIBL628Y3.LARGE.jpg).
- breadboard.
