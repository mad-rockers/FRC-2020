#include <frc/WPILib.h>
#include "CustomController.h"

using namespace frc;

CustomController::CustomController(int port) : XboxController(port) {
    scale = 1; //Initialize the scale to 1.
    square = false;
}

void CustomController::set_scale(float scale) {
    scale = abs(scale); //Make sure the scale is not negative.
}

float CustomController::get_scale() {
    if(square) {
        return 1; //If a square scale is in effect, return 1.
    }
    else {
        return scale;
    }
}

void CustomController::square_scale(float percent) {
    square = true;
    if(percent > 100) { //Ensure the scale is not above 100.
        scale = 100;
    }
    else if(percent < 0) { //Ensure the scale is not below 0.
        scale = 0;
    }
    else {
        scale = percent;
    }
}

float CustomController::get_square() {
    if(square) {
        return scale;
    }
    else {
        return -1; //If no square scale is in effect, return -1.
    }
}

double CustomController::GetRawAxis(int axis) {
    if(GenericHID::GetRawAxis(axis) > -0.1 && GenericHID::GetRawAxis(axis) < 0.1) { //If the value is between -0.1 and 0.1, return 0.
        return 0;
    }
    else if (GenericHID::GetRawAxis(axis) > 1) { //Ensure the value is not above 1.
        return 1;
    }
    else if (GenericHID::GetRawAxis(axis) < -1) { //Ensure the value is not below -1.
        return -1;
    }
    else {
        return GenericHID::GetRawAxis(axis);
    }
}