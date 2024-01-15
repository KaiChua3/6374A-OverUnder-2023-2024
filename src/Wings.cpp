#include "pros/adi.hpp"
#include "Wings.hpp"

Wings::Wings(uint8_t const wingsPort1, uint8_t const wingsPort2) 
: wings1 {wingsPort1} 
, wings2 {wingsPort2} {}

void Wings::activateWings (bool wingsActive) {
    wings1.set_value(wingsActive);
    wings2.set_value(wingsActive);
}