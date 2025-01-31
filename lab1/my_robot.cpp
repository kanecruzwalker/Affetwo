#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

Motors motors;

MyRobot::MyRobot() {
  
}

void MyRobot::MoveForward(float distance, int speed_in){
  //Movin forward
  //Both speeds in should be equal to eachother
  //otherwise we are not moving forward 
  float actual_speed = speed_in / 1000.0;
  int time_ms = (distance / actual_speed) * 1000.0;

  motors.setSpeeds(speed_in, speed_in);
  delay(time_ms);
  Stop();
  //could create conditional logic to ensure speeds in are == before executing
}

void MyRobot::SpinLeft(int left_speed_in, int right_speed_in, int movement_duration){
  //Spining Left
  //Left should be the negative value
  //otherwise it wont spin in place 
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);

}

void MyRobot::SpinRight(int left_speed_in, int right_speed_in, int movement_duration){
  //Spining Right
  //Right should be the negative value 
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);
}

void MyRobot::MoveForwardTurnLeft(int left_speed_in, int right_speed_in, int movement_duration){
  //Right should move quicker than left
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);
}

void MyRobot::MoveForwardTurnRight(int left_speed_in, int right_speed_in, int movement_duration){
  //Left should move quicker than right
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);
}

void MyRobot::Stop(){
  motors.setSpeeds(0,0);
}


void MyRobot::MoveBackwards(float distance_in, int speed_in){
  //Both left and right should be negative numbers
  float actual_speed = speed_in / 1000.0;
  int time_ms = (distance_in / actual_speed) * 1000.0;

  motors.setSpeeds(speed_in * -1, speed_in * -1);
  delay(time_ms);
}

//Could create one move class that uses set speeds (since input values would differ it would handle all cases)
//Could set specific move parameters in already created function, making them more like halt 
//Should implement class variables and calculations in functions instead of in .ino 

