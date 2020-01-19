#include <frc/WPILib.h>
#include "CustomController.h"

using namespace frc;

void CustomController::set_scale(float s) {
    CustomController::scale = abs(s);
}

double CustomController::GetRawAxis(int axis) : GenericHID::GetRawAxis(axis) {
    if(GenericHID::GetRawAxis(axis) > -0.1 && GenericHID::GetRawAxis(axis) < 0.1) {
        return 0;
    }
    else {
        return GenericHID::GetRawAxis(axis);
    }
}