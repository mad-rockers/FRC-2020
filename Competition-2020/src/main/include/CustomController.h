#include <frc/WPILib.h>

using namespace frc;

class CustomController : public XboxController {
  public:
    explicit CustomController(int port) : XboxController(port) {
        CustomController::scale = 1;
    }
    float scale;
    void set_scale(float s);
    double GetRawAxis(int axis) ;//: GenericHID::GetRawAxis(axis);
};