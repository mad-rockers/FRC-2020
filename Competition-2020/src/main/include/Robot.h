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
#include "rev/CANSparkMax.h"

//our custom controller
#include "CustomController.h"

using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  CustomController xbox;
  //RobotDrive driveTrain;
  rev::CANSparkMax testNeoL;
  rev::CANSparkMax testNeoR;
  rev::CANEncoder testNeoEncoder;
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  Robot() : xbox(0), /*driveTrain(0, 1),*/ testNeoL(1, rev::CANSparkMax::MotorType::kBrushless), testNeoR(9, rev::CANSparkMax::MotorType::kBrushless), testNeoEncoder(testNeoL) {
    
  }
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
