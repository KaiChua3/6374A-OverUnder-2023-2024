#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "pros/rtos.hpp"

Catapult::Catapult (int8_t const cata_port) : cata_motor{cata_port} {}

void Catapult::launch (int velocity) {
    cata_motor.move_velocity(velocity);
}