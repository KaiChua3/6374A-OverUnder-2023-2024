#pragma once

#include "pros/adi.hpp"

class Wings {
    private:
        pros::ADIDigitalOut wings1;
        pros::ADIDigitalOut wings2;

    public:
        Wings(uint8_t const wingsPort1, uint8_t const wingsPort2);
        void activateWings(bool wingsActive);
};