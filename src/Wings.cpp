#include "pros/adi.hpp"
#include "Wings.hpp"

Wings::Wings(uint8_t const wingsPort1, uint8_t const wingsPort2, uint8_t const hangPort, uint8_t backwingsPort1, uint8_t backwingsPort2) 
: wings1 {wingsPort1} 
, wings2 {wingsPort2}
, hang(hangPort)
, backwings1(backwingsPort1)
, backwings2(backwingsPort2)
{}

void Wings::activateWings (bool wingsActive) {
    wings1.set_value(wingsActive);
    wings2.set_value(wingsActive);
}

void Wings::activateBackWings (bool wingsActive) {
    backwings1.set_value(wingsActive);
    backwings2.set_value(wingsActive);
}

void Wings::activateHang (bool hangActive) {
    hang.set_value(hangActive);
}