/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SendableChooser.h>

using namespace frc;

class XboxController2 : public XboxController {
  public:
    float scale;

    void set_scale(float s) {
      scale = abs(s);
    }

    double GetRawAxis(int axis) {
      if(GenericHID::GetRawAxis(axis) < 0.1 && GenericHID::GetRawAxis(axis) > -0.1) {
        return 0;
      }
      else {
        return scale * GenericHID::GetRawAxis(axis);
      }
    }
    explicit XboxController2(int port) : XboxController(port){
      scale = 1;
    }
};

class Robot : public frc::TimedRobot {
 public:
  XboxController2 xbox;
  RobotDrive driveTrain;
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  Robot() : xbox(0), driveTrain(0, 1) {

  }
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
