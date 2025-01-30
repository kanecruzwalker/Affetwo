#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

Motors motors;

MyRobot::MyRobot() {
  
}

void MyRobot::MoveForward(int left_speed_in, int right_speed_in, int movement_duration){
  //Movin forward
  //Both speeds in should be equal to eachother
  //otherwise we are not moving forward 
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);

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


void MyRobot::MoveBackwards(int left_speed_in, int right_speed_in, int movement_duration){
  //Both left and right should be negative numbers
  motors.setSpeeds(left_speed_in, right_speed_in);
  delay(movement_duration);
}

//Could create one move class that uses set speeds (since input values would differ it would handle all cases)
//Could set specific move parameters in already created function, making them more like halt 
//Should implement class variables and calculations in functions instead of in .ino 

