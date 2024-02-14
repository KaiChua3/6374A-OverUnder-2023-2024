#pragma once

#include "pros/adi.hpp"

class Wings {
    private:
        pros::ADIDigitalOut wings1;
        pros::ADIDigitalOut wings2;
        pros::ADIDigitalOut backwings1;
        pros::ADIDigitalOut backwings2;
        pros::ADIDigitalOut hang;

    public:
        Wings(uint8_t const wingsPort1, uint8_t const wingsPort2, uint8_t const hangPort, uint8_t const backwingsPort1, uint8_t const backwingsPort2);
        void activateWings(bool wingsActive);
        void activateBackWings(bool wingsActive);
        void activateHang(bool hangActive);
};