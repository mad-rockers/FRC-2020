#include <frc/WPILib.h>
#include <cmath>

using namespace frc;

/**
 * Handle input from Xbox 360 or Xbox One controllers connected to the Driver
 * Station.
 *
 * This class handles Xbox input that comes from the Driver Station. Each time a
 * value is requested the most recent value is returned. There is a single class
 * instance for each controller and the mapping of ports to hardware buttons
 * depends on the code in the Driver Station.
 * 
 * This class is a modified version of XboxController.
 */
class CustomController : public XboxController {
  public:

    /**
     * Construct an instance of our custom Xbox controller.
     *
     * The controller index is the USB port on the Driver Station.
     *
     * @param port The port on the Driver Station that the controller is plugged
     *             into (0-5).
     */
    explicit CustomController(int port) : XboxController(port) {
       is_square = true;
    };
    
    /**
     * Toggles square scaling between on and off.
     */
    void toogle_square_scale() {
      is_square = !is_square;
    }

    /**
     * Returns whether the controller axis is in the deadzone. The deadzone -0.1 to 0.1.
     * 
     * @return A boolean of whether the controller axis is in the deadzone.
     */
    bool in_deadzone(int axis) {
      return GenericHID::GetRawAxis(axis) < 0.1 && GenericHID::GetRawAxis(axis) > -0.1; //If the axis is inside our deadzone(0.1), return true.
    }

    /**
     * Get the value of the axis. A deadzone is implemented.
     *
     * @param axis The axis to read, starting at 0.
     * @return The value of the axis between -1 and 1.
     */
    double GetRawAxis(int axis) {
        double value = GenericHID::GetRawAxis(axis);
        if(in_deadzone(axis)) { //If the value is in the deadzone, return 0.
            return 0;
        }
        if(is_square) {
            if(value > 0) {
              return pow((value - 0.1) / 0.9, 2); //If it's above 0, use a positive square curve.
            }
            else {
              return -pow((value + 0.1) / 0.9, 2); //If it's below 0, use a negative square curve.
            }
        }
        else {
            return value;
        }
    }
    
  private:
    bool is_square;
};