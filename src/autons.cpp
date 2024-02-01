#include "main.h"
#include "Intake.hpp"
#include "Wings.hpp"
#include "Constants.hpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(135, 60);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 40, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 5, 0, 0, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0, 0, 0);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}
void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0, 0, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}

// Programming Skills Auton
void ProgrammingSkillsAuton() {
  
}

// Goalside Elims Auton
void GoalsideElimsAuton() {
  Intake intake(IntakePort);
  Wings wings (PistonPort1, PistonPort2, HangPort);

  wings.activateWings(false);
  //Push Alliance Preload into goal
  chassis.set_drive_pid(-72, -127, true, false);
  chassis.wait_drive();

  // Move away from goal
  chassis.set_drive_pid(24, 110, true, false);
  chassis.wait_drive();

  // Turn right 90 degrees
  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  // Move forward 1 tile to be able to face field triballs
  chassis.set_drive_pid(24, 110, true, false);
  chassis.wait_drive();

  // Turn 90 degrees to face field triballs
  chassis.set_turn_pid(90, 110);
  // Spin intake to take in triballs
  intake.spinIntake(-1 * IntakeSpeed);
  chassis.wait_drive();

  // Move forward to intake first triball
  chassis.set_drive_pid(58, 110, true, false);
  chassis.wait_drive();
  /*
  // Move backwards a bit off the barrier so PID not thrown off
  chassis.set_drive_pid(-10, -110, true, false);
  chassis.wait_drive();

  // Turn 90 degrees to the right to face remaining triballs
  chassis.set_turn_pid(-90, 110);
  wings.activateWings(true);
  chassis.wait_drive();

  chassis.set_drive_pid(18, 110, true, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, 110);
  chassis.wait_drive();

  chassis.set_drive_pid(28, 110, true, false);
  chassis.wait_drive();
*/
}

// Opposite Side Elims Auton
void OppositeSideElimsAuton() {
  Intake intake(IntakePort);

  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  intake.spinIntake(IntakeSpeed);

  chassis.set_drive_pid(36, 110, true, false);
  chassis.wait_drive();

  intake.spinIntake(0);

  chassis.set_drive_pid(36, -110, true, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 110);
  chassis.wait_drive();

  chassis.set_drive_pid(60, 110, true, false);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();
  
  intake.spinIntake(IntakeSpeed);

  chassis.set_drive_pid(36, 110, true, false);
  chassis.wait_drive();

  intake.spinIntake(0);
}

// Goalside WP auton
void GoalsideWPAuton() {
  Intake intake(IntakePort);
  Wings wings (PistonPort1, PistonPort2, HangPort);

  wings.activateWings(false);
  //Push Alliance Preload into goal
  wings.activateWings(true);
  chassis.set_drive_pid(72, 127, true, false);
  chassis.wait_drive();

  // Move away from goal
  chassis.set_drive_pid(-24, 110, true, false);
  chassis.wait_drive();

  // Turn left 90 degrees
  wings.activateWings(false);
  chassis.set_turn_pid(-90, 110);
  chassis.wait_drive();

  // Move forward 1 tile to be able to face field triballs
  chassis.set_drive_pid(24, 110, true, false);
  chassis.wait_drive();

  // Turn right 90 degrees to face field triballs
  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  // Spin intake to take in triballs
  intake.spinIntake(-1 * IntakeSpeed);
  chassis.wait_drive();
  
  // Move forward to intake first triball
  chassis.set_drive_pid(58, 110, true, false);
  chassis.wait_drive();

  // Activate wings and turn to push triballs towards goal
  wings.activateWings(true);
  chassis.set_drive_pid(24, 110, true, false);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  // Move forwards towards goal
  chassis.set_drive_pid(58, 110, true, false);
  chassis.wait_drive();

  // Spin intake outwards
  intake.spinIntake(IntakeSpeed);
  chassis.wait_drive();

  // Move backwards
  chassis.set_drive_pid(-12, -110, true, false);
  chassis.wait_drive();

  // Move forwards to push triballs into goal
  chassis.set_drive_pid(12, 110, true, false);
  chassis.wait_drive();

  // Move backwards away from goal
  chassis.set_drive_pid(-3, -110, true, false);
  chassis.wait_drive();

  // Turn off intake and wings
  intake.spinIntake(0);
  wings.activateWings(false);
}

// Oppositeside WP auton
void OppositesideWPAuton() {
  Intake intake(IntakePort);
  Wings wings (PistonPort1, PistonPort2, HangPort);

  //Initialize intake and wings
  wings.activateWings(true);
  chassis.wait_drive();
  //Moves backwards to push corner triball
  chassis.set_drive_pid(-6, 110, true, false);
  chassis.wait_drive();

  //Turns to face the direction of pole
  chassis.set_turn_pid(-45, 110);
  chassis.wait_drive();

  //Moves forward away from corner
  chassis.set_drive_pid(-16, 110);
  chassis.wait_drive();

  //Turn right to head into alley
  chassis.set_turn_pid(20, 110);
  wings.activateWings(false);
  chassis.wait_drive();

  //Moves forward into alley
  chassis.set_drive_pid(-14, 110, true, false);
  chassis.wait_drive();

  //Turns back facing the pole
  chassis.set_turn_pid(-45, 110);
  chassis.wait_drive();

  //Moves forward to touch pole
  chassis.set_drive_pid(-42.5, 110, true, false);
  chassis.wait_drive();
}

//Disrupting auton to disrupt other bots auton
void disruptAuton() {

}

//Testing drive to tune PID
void testingDriveAuton() {
  chassis.set_drive_pid(24, 110, true, false);
  chassis.wait_drive();
}

//Testing turning to tune PID
void testingTurnAuton() {
  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();
}