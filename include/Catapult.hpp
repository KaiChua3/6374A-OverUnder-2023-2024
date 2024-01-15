#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "pros/motors.hpp"

class Catapult {
    private:
        pros::Motor cata_motor;
    public:
        Catapult(int8_t const cata_port);
        void launch(int velocity);
};