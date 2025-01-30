#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

void setup() {
  Serial.begin(9600);
  delay(15);
}

void loop() {
  //Sets the speeds for motors
  //The value of the input is given in mm/s with a maximum value of 400
  MyRobot robot;
  //movement variables
  int default_speed = 50;
  int left_speed = 50;
  int right_speed = 50;
  int left_multiplier = 2;
  int right_multiplier = 2;
  int movement_duration = 3000;


  //The robots Movement functions take in 3 inputs
  //left speed, right speed, and movement duration
  //They use the setSpeeds function and delay function to execute desired movement over a desired time period
  //One can change left_speed, and right_speed values as desired to increase/decrease speed, movement tradjectory
  //One can change movement_duration to have that movement pattern execute for the desired time. 1000 miliseconds = 1 second


  //move forward
  robot.MoveForward(left_speed, right_speed, movement_duration);
  //delay(3000);


  //turn right(in place)                          //left goes forward, right goes backwards
  right_speed = right_speed * -1;
  robot.SpinRight(left_speed, right_speed, movement_duration);
  //delay(3000);
  right_speed = default_speed; //reseting right_speed to default value for next operation


  //turn left (in place)                          //left goes backwards , right goes forwards
  left_speed = left_speed * -1;
  robot.SpinLeft(left_speed, right_speed, movement_duration);
  //delay(3000);
  left_speed = default_speed; //reseting right_speed to default value for next operation


  //move forward while turning right               //left goes faster than right side, but by how much?
  left_speed = left_speed * left_multiplier;
  robot.MoveForwardTurnRight(left_speed, right_speed, movement_duration);
  //delay(3000);
  left_speed = default_speed;     //reseting right_speed to default value for next operation


  //move forward while turning left               //right  goes faster than left side, but by how much?
  right_speed = right_speed * right_multiplier;
  robot.MoveForwardTurnLeft(left_speed, right_speed, movement_duration);
  //delay(3000);
  right_speed = default_speed;    //reseting right_speed to default value for next operation


  //move backwards
  //set speeds in the negative direction to go back
  left_speed = left_speed * -1;
  right_speed = right_speed * -1;
  robot.MoveBackwards(left_speed, right_speed, movement_duration);
  //delay(3000);


  //halt
  robot.Stop();

  //The current variables here could be moved into the MyRobot private variables and the operations could take place in their functions
  //Will probably need to refactor that for post lab but for now this allows us flexibility and ease of use when wanting to change our inputs as we test
}
