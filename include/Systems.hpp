#pragma once
#include "EZ-Template/api.hpp"
#include "Catapult.hpp"
#include "Intake.hpp"
#include "Wings.hpp"
#include "pros/misc.hpp"


class Systems {
    private:
        pros::Controller robot_controller {pros::E_CONTROLLER_MASTER};
        Catapult bot_cata;
        Intake bot_intake;
        Wings bot_wings;

        void update_catapult();
        void update_intake();
        void update_wings();
    public:
        Systems(Catapult cata, Intake intake, Wings wings);
        void update();
};