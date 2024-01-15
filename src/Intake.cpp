#include "Intake.hpp"
#include <iostream>

Intake::Intake(int8_t const intake_port) : intake_motor{intake_port} {}

void Intake::spinIntake(int velocity) {
    intake_motor.move_velocity(velocity);
}
