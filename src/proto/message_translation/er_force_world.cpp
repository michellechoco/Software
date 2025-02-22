#include "proto/message_translation/er_force_world.h"

Ball createBall(world::SimBall sim_ball, Timestamp timestamp)
{
    const Point position(sim_ball.p_x(), sim_ball.p_y());
    const Vector velocity(sim_ball.v_x(), sim_ball.v_y());
    const BallState state(position, velocity);
    const Ball ball(state, timestamp);
    return ball;
}

Robot createRobot(world::SimRobot sim_robot, Timestamp timestamp)
{
    const RobotId id(sim_robot.id());
    const Point position(sim_robot.p_x(), sim_robot.p_y());
    const Vector velocity(sim_robot.v_x(), sim_robot.v_y());

    const RobotState state(position, velocity, Angle::fromRadians(sim_robot.angle()),
                           Angle::atan(sim_robot.r_y() / sim_robot.r_x()));
    const Robot robot(id, state, timestamp);
    return robot;
}
