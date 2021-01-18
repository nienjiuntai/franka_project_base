#include <iostream>
#include <fstream>
#include <franka/exception.h>
#include <franka/robot.h>
#include <franka/gripper.h>
#include <franka/duration.h>
#include <thread>
#include <vector>
#include <array>
#include <getopt.h>
#include <regex>
#include <unistd.h>
#include <string>
#include <cstdlib>

#include "franka_util.hpp"

namespace FrankaControl {
void FrankaControl::setJoints(std::array<double, 7> joints)
{
    MotionGenerator motion_generator(0.5, joints);
    try {
        robot.control(motion_generator);
    } catch (franka::Exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

bool FrankaControl::grasp(double width)
{
    if(!endpoint(width)) {
        return false;
    }
    franka::GripperState state = gripper.readOnce();
    if(!state.is_grasped) {
        std::cout << "Object lost." << std::endl;
        return false;
    } else {
        std::cout << "Grasped." << std::endl;
        return true;
    }
}
std::array<double, 7> FrankaControl::getJoints()
{
    franka::RobotState state = robot.readOnce();
    return state.q; // or use theta?
}
bool FrankaControl::endpoint(double width)
{
    franka::GripperState state = gripper.readOnce();
    if(state.max_width < width) {
        std::cout << "Object too long (" << width << " > " << state.max_width << std::endl;
        return false;
    }
    if(!gripper.grasp(width, 0.1, 60, 0.1, 0.1)) {
        std::cout << "Failed to grasp." << std::endl;
        return false;
    }
}
std::string FrankaControl::readOnce()
{
    franka::RobotState state = robot.readOnce();
    std::ostringstream ss;
    ss << state;
    return ss.str();
    // return robot.readOnce();
}
bool FrankaControl::homing()
{
    setJoints({{0.0, -0.2, 0.0, -2.9, 0.0, 2.7, 0.8}});
}
void FrankaControl::setPos(std::array<double, 3> pos)
{
    fprintf(stderr, "Not Implement yet");
}

}

