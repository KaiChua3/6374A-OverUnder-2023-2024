#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "pros/rtos.hpp"

Catapult::Catapult (int8_t const cata_port, int8_t const small_cata_port) : 
cata_motor{cata_port}, 
small_cata_motor{small_cata_port} {}

void Catapult::launch (int velocity) {
    cata_motor.move_velocity(velocity);
    small_cata_motor.move_velocity(-1 * velocity);
}
