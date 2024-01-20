#pragma once

#include "pros/adi.hpp"

class Wings {
    private:
        pros::ADIDigitalOut wings1;
        pros::ADIDigitalOut wings2;
        pros::ADIDigitalOut hang;

    public:
        Wings(uint8_t const wingsPort1, uint8_t const wingsPort2, uint8_t const hangPort);
        void activateWings(bool wingsActive);
        void activateHang(bool hangActive);
};