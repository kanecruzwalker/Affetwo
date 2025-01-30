#ifndef my_robot_h
#define my_robot_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

//Allowing motors to move by creating functions for specific movement with modifiable left and right speeds as well as movement duration

class MyRobot{
  public:
    MyRobot();    

    //Movement Functions  
    void MoveForward(float distance, int speed_in);
    void MoveBackwards(int left_speed_in, int right_speed_in, int movement_duration);
    void SpinLeft(int left_speed_in, int right_speed_in, int movement_duration);
    void SpinRight(int left_speed_in, int right_speed_in, int movement_duration);
    void MoveForwardTurnRight(int left_speed_in, int right_speed_in, int movement_duration);
    void MoveForwardTurnLeft(int left_speed_in, int right_speed_in, int movement_duration);
    void Stop();
    
    
  private:
    
};

#endif
