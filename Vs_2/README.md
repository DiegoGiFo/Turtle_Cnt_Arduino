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
- 4 buttons;
- breadboard.

## CIRCUIT

#### LCD
- RS pin to digital PIN 12
- Enable pin to digital PIN 11
- D4 pin to digital PIN 5
- D5 pin to digital PIN 4
- D6 pin to digital PIN 3
- D7 pin to digital PIN 2
- R/W pin to GROUND
- 10K resistor connecting LED+ to GROUND:
- LED- to GROUND
- VO to GROUND

#### BUTTONS
- Rigth button PIN 6
- Left button PIN 7
- Forward button PIN 8
- Behind button PIN 9
