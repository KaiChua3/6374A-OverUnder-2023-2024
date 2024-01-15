#pragma once
#include <cstdint>
#include "pros/motors.hpp"

class Intake {
    private:
        pros::Motor intake_motor;
    public:
        Intake(int8_t const intake_port);
        void spinIntake(int velocity);
};