/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "portDef.h"
#include "chassis.h"
#include "lcd.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {
  // Activiate the LCD for feedback data
  lcdScriptInit(uart1); // Example LCD is in UART1
  lcdClear(uart1);
  lcdPrint(uart1, 1, "bot01 - auto");
  // drive forward a bit
  chassisSet(50,50);            // drive forward half speed
  wait(300);
  pivotTurn(0,50,90,false);     // turn 90degrees
  chassisSet(0,0);              //stop motors
}
