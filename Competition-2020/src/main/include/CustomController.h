#include <frc/WPILib.h>

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
     * Get the value of an axis. A deadzone of 0.1 is implemented.
     *
     * @param axis The axis to read, starting at 0.
     * @return The value of the axis between -1 and 1.
     */
    double GetRawAxis(int axis) {
        double value = GenericHID::GetRawAxis(axis);
        if(CustomController::in_deadzone(axis)) { //If the value is between -0.1 and 0.1, return 0.
            return 0;
        }
        if(square) {
            if(value >= scale / 100) { //Perform square scaling.
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            value *= scale;
            if (value > 1) { //Ensure the value is not above 1.
                return 1;
            }
            else if (value < -1) { //Ensure the value is not below -1.
                return -1;
            }
            else {
                return value;
            }
        }
    }
    
  private:
    bool is_square;
};