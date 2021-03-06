#ifndef _CHASSIS_H_
#define _CHASSIS_H_

#include "stdbool.h"

#define WHEEL_DIAMETER 4      // diameter of drive wheels
#define WHEEL_BASE 10         // wheel base in inches left to right wheel

// Sets the speeds of the left and right wheels of the chassis
void chassisSet(int left, int right);

// drive forward with PID tankControl
void drivePID();

// drive for defined distance in inches with pinMode
void driveForDistancePID(int distance, int speed);

// create pivot turn function
void pivotTurn(int direction, int speed, float angle, bool gyro);

// create swing turn function
void swingTurn(int direction, int speed, float angle, bool gyro);

#endif // _CHASSIS_H_
