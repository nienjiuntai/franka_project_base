#include <franka/control_types.h>
#include <franka/duration.h>
#include <franka/robot.h>
#include <franka/robot_state.h>
#include <franka/gripper.h>

<<<<<<< HEAD
#include "examples_common.h"
=======
#include "MotionGenerator.h"
>>>>>>> 0856c79fb0f5760b4af7d18324fe71a902877464

namespace FrankaControl {
class FrankaControl {
    public:
        FrankaControl(char *robot_ip): robot(robot_ip), gripper(robot_ip) {};
        void setJoints(std::array<double, 7> q_goal);
        std::array<double, 7> getJoints();
        bool grasp(double width);
        bool endpoint(double width);
        std::string readOnce();
        bool homing();
        void setPos(std::array<double, 3> pos);
    private:
        franka::Robot robot;
        franka::Gripper gripper;
};
}