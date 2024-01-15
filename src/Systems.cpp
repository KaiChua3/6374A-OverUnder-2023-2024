#include "pros/misc.h"
#include <iostream>
#include "Systems.hpp"
#include "autons.hpp"
#include "main.h"
#include "Constants.hpp"

bool pistonActive = true;
bool cataOn = true;

Systems::Systems (Catapult bot_cata, Intake bot_intake, Wings bot_wings) 
: bot_cata(bot_cata)
, bot_intake(bot_intake) 
, bot_wings(bot_wings) {}

//Run catapult functions
void Systems::update_catapult() {
    if (robot_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
        if (cataOn == false) {
            bot_cata.launch(CataSpeed);
        } else if (cataOn == true) {
            bot_cata.launch(0);
        }
        cataOn = !cataOn;
        std::cout<<cataOn<<std::endl;
    }
}

//Run intake functions
void Systems::update_intake() {
    if (robot_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        bot_intake.spinIntake(-1 * IntakeSpeed);
    } else if (robot_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        bot_intake.spinIntake(IntakeSpeed);
    } else {
        bot_intake.spinIntake(0);
    }
}

//Run wings/pistons functions
void Systems::update_wings() {
    if (robot_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        pistonActive = !pistonActive;
        bot_wings.activateWings(pistonActive);
    }
}

//Stores and runs all functions into a combined method
void Systems::update() {
    update_catapult();
    update_intake();
    update_wings();
}