// Robot DIO ports
enum DIO
{
    DIO_0 = 0,
    DIO_1 = 1,
    DIO_2 = 2,
    DIO_3 = 3,
    DIO_4 = 4,
    DIO_5 = 5,
    DIO_6 = 6,
    DIO_7 = 7,
    DIO_8 = 8,
    DIO_9 = 9,
};

// Robot PMW ports
enum PWM
{
    PWM_0 = 0,
    PWM_1 = 1,
    PWM_2 = 2,
    PWM_3 = 3,
    PWM_4 = 4,
    PWM_5 = 5,
    PWM_6 = 6,
    PWM_7 = 7,
    PWM_8 = 8,
    PWM_9 = 9,
};

// Robot analog ports
enum ANALOG
{
    ANALOG_0 = 0,
    ANALOG_1 = 1,
    ANALOG_0 = 2,
    ANALOG_3 = 3
};

// XBox controllers
enum USB
{
    USB_0 = 0,
    USB_1 = 1,
    USB_2 = 2,
    USB_3 = 3
};

const USB XBOX_DRIVER = USB::USB_0;

const PWM LEFT_DRIVE_TRAIN = PWM::PWM_0;
const PWM RIGHT_DRIVE_TRAIN = PWM::PWM_1;