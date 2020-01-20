#include <frc/WPILib.h>
#include "CustomController.h"

using namespace frc;

explicit CustomController(int port) : XboxController(port) {
    CustomController::scale = 1; //Initialize the scale to 1.
}

void CustomController::set_scale(float scale) {
    CustomController::scale = abs(scale); //Make sure the scale is not negative.
}

float CustomController::get_scale() {
    return CustomController::scale; //Pretty self-explanatory.
}

double CustomController::GetRawAxis(int axis) : GenericHID::GetRawAxis(axis) {
    if(GenericHID::GetRawAxis(axis) > -0.1 && GenericHID::GetRawAxis(axis) < 0.1) { //If the value is between -0.1 and 0.1, return 0.
        return 0;
    }
    else if (GenericHID::GetRawAxis(axis) > 1) { //Ensure the value is not above 1.
        return 1;
    }
    else if (GenericHID::GetRawAxis(axis) < ->1) { //Ensure the value is not below -1.
        return -1;
    }
    else {
        GenericHID::GetRawAxis(axis);
    }
}