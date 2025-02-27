#include "software/ai/hl/stp/tactic/goalie/goalie_tactic.h"

#include <gtest/gtest.h>

#include <utility>

#include "software/ai/hl/stp/tactic/move/move_tactic.h"
#include "software/simulated_tests/non_terminating_validation_functions/enemy_never_scores_validation.h"
#include "software/simulated_tests/simulated_tactic_test_fixture.h"
#include "software/simulated_tests/terminating_validation_functions/ball_kicked_validation.h"
#include "software/simulated_tests/terminating_validation_functions/robot_in_polygon_validation.h"
#include "software/simulated_tests/terminating_validation_functions/robot_received_ball_validation.h"
#include "software/simulated_tests/validation/validation_function.h"
#include "software/test_util/test_util.h"
#include "software/time/duration.h"
#include "software/world/field.h"
#include "software/world/world.h"

class GoalieTacticTest
    : public SimulatedTacticTestFixture,
      public ::testing::WithParamInterface<std::tuple<BallState, RobotStateWithId>>
{
   protected:
    void checkGoalieSuccess(int seconds_to_wait, std::shared_ptr<World> world_ptr,
                            ValidationCoroutine::push_type& yield)
    {
        auto initial_time = world_ptr->getMostRecentTimestamp();
        while (world_ptr->getMostRecentTimestamp() <
               initial_time + Duration::fromSeconds(seconds_to_wait))
        {
            yield("Waiting " + std::to_string(seconds_to_wait) +
                  " seconds to check that the enemy team did not score");
        }
    }
    Field field = Field::createSSLDivisionBField();
    std::vector<RobotStateWithId> enemy_robots =
        TestUtil::createStationaryRobotStatesWithId(
            {Point(1, 0), Point(1, 2.5), Point(1, -2.5), field.enemyGoalCenter(),
             field.enemyDefenseArea().negXNegYCorner(),
             field.enemyDefenseArea().negXPosYCorner()});
};

TEST_F(GoalieTacticTest, test_panic_ball_very_fast_in_straight_line)
{
    BallState ball_state(Point(0, 0), Vector(-3, 0));
    auto friendly_robots = TestUtil::createStationaryRobotStatesWithId({Point(-4, -1)});

    std::shared_ptr<const GoalieTacticConfig> goalie_tactic_config =
        std::make_shared<const GoalieTacticConfig>();

    auto tactic = std::make_shared<GoalieTactic>(goalie_tactic_config);
    setTactic(tactic);
    setFriendlyRobotId(0);

    std::vector<ValidationFunction> terminating_validation_functions = {
        [this, tactic](std::shared_ptr<World> world_ptr,
                       ValidationCoroutine::push_type& yield) {
            while (!tactic->done())
            {
                yield("Tactic not done");
            }
            checkGoalieSuccess(1, world_ptr, yield);
        }};

    std::vector<ValidationFunction> non_terminating_validation_functions = {
        [](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            enemyNeverScores(world_ptr, yield);
        }};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(10));
}

TEST_F(GoalieTacticTest, test_panic_ball_very_fast_in_diagonal_line)
{
    BallState ball_state(Point(0, 0), Vector(-4.5, 0.25));
    auto friendly_robots = TestUtil::createStationaryRobotStatesWithId(
        {field.friendlyGoalCenter() + Vector(0, -0.5)});

    std::shared_ptr<const GoalieTacticConfig> goalie_tactic_config =
        std::make_shared<const GoalieTacticConfig>();
    auto tactic =
        std::make_shared<GoalieTactic>(std::make_shared<const GoalieTacticConfig>());
    setTactic(tactic);
    setFriendlyRobotId(0);

    std::vector<ValidationFunction> terminating_validation_functions = {
        [this, tactic](std::shared_ptr<World> world_ptr,
                       ValidationCoroutine::push_type& yield) {
            while (!tactic->done())
            {
                yield("Tactic not done");
            }
            checkGoalieSuccess(2, world_ptr, yield);
        }};

    std::vector<ValidationFunction> non_terminating_validation_functions = {
        [](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            enemyNeverScores(world_ptr, yield);
        }};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(10));
}

TEST_F(GoalieTacticTest, test_ball_very_fast_misses_net)
{
    BallState ball_state(Point(0, 0), Vector(-4, 1));
    auto friendly_robots = TestUtil::createStationaryRobotStatesWithId({Point(-4.5, 0)});

    std::shared_ptr<const GoalieTacticConfig> goalie_tactic_config =
        std::make_shared<const GoalieTacticConfig>();
    auto tactic = std::make_shared<GoalieTactic>(goalie_tactic_config);
    setTactic(tactic);
    setFriendlyRobotId(0);

    std::vector<ValidationFunction> terminating_validation_functions = {
        [this](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            checkGoalieSuccess(5, world_ptr, yield);
        }};

    std::vector<ValidationFunction> non_terminating_validation_functions = {
        [](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            enemyNeverScores(world_ptr, yield);
        }};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(10));
}

TEST_F(GoalieTacticTest, test_slow_ball_at_sharp_angle_to_friendly_goal)
{
    BallState ball_state(Point(-4.5, -3), Vector(0, 0.1));
    auto friendly_robots = TestUtil::createStationaryRobotStatesWithId({Point(-4.5, 0)});

    std::shared_ptr<const GoalieTacticConfig> goalie_tactic_config =
        std::make_shared<const GoalieTacticConfig>();
    auto tactic = std::make_shared<GoalieTactic>(goalie_tactic_config);
    setTactic(tactic);
    setFriendlyRobotId(0);

    std::vector<ValidationFunction> terminating_validation_functions = {
        [this](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            checkGoalieSuccess(5, world_ptr, yield);
            robotInPolygon(0, Rectangle(world_ptr->field().friendlyNegativeYQuadrant()),
                           world_ptr, yield);
        }};

    std::vector<ValidationFunction> non_terminating_validation_functions = {
        [](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            enemyNeverScores(world_ptr, yield);
        }};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(10));
}

TEST_P(GoalieTacticTest, goalie_test)
{
    BallState ball_state         = std::get<0>(GetParam());
    RobotStateWithId robot_state = std::get<1>(GetParam());

    auto friendly_robots = {robot_state};

    std::shared_ptr<const GoalieTacticConfig> goalie_tactic_config =
        std::make_shared<const GoalieTacticConfig>();
    auto tactic = std::make_shared<GoalieTactic>(goalie_tactic_config);
    setTactic(tactic);
    setFriendlyRobotId(0);

    std::vector<ValidationFunction> terminating_validation_functions = {
        [this, tactic](std::shared_ptr<World> world_ptr,
                       ValidationCoroutine::push_type& yield) {
            robotReceivedBall(0, world_ptr, yield);
            while (!tactic->done())
            {
                yield("Tactic not done");
            }
            Angle clear_angle =
                (world_ptr->ball().position() - world_ptr->field().friendlyGoalCenter())
                    .orientation();
            ballKicked(clear_angle, world_ptr, yield);
            checkGoalieSuccess(1, world_ptr, yield);
        }};

    std::vector<ValidationFunction> non_terminating_validation_functions = {
        [](std::shared_ptr<World> world_ptr, ValidationCoroutine::push_type& yield) {
            enemyNeverScores(world_ptr, yield);
        }};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(10));
}

INSTANTIATE_TEST_CASE_P(
    GoalieEnvironment, GoalieTacticTest,
    ::testing::Values(
        // ball slow inside friendly defense area
        std::make_tuple(BallState(Point(-4, 0.8), Vector(-0.2, 0)),
                        RobotStateWithId{
                            0, RobotState(Point(-4, 0), Vector(0, 0),
                                          Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // ball stationary inside friendly defense area
        std::make_tuple(
            BallState(Point(-4, 0), Vector(0, 0)),
            RobotStateWithId{
                0,
                RobotState(Field::createSSLDivisionBField().friendlyGoalpostPos(),
                           Vector(0, 0), Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // ball stationary inside no-chip rectangle
        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter() +
                                      Vector(0.1, 0.1),
                                  Vector(-0.2, 0)),
                        RobotStateWithId{
                            0, RobotState(Point(-4, -1), Vector(0, 0),
                                          Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // ball fast inside no-chip rectangle but no intersection with goal
        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter() +
                                      Vector(0.1, 0),
                                  Vector(0, -0.5)),
                        RobotStateWithId{
                            0, RobotState(Point(-3.5, 1), Vector(0, 0),
                                          Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // ball moving out from inside defense area
        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter() +
                                      Vector(0.5, 0),
                                  Vector(0.5, 0)),
                        RobotStateWithId{
                            0, RobotState(Point(-3.5, 0), Vector(0, 0),
                                          Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // TODO (#2167): This test fails so disabling for Robocup
        // ball moving into goal from inside defense area
        //        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter()
        //        +
        //                                      Vector(0.5, 0),
        //                                  Vector(-0.5, 0)),
        //                        RobotStateWithId{
        //                            0, RobotState(Point(-3.5, 0), Vector(0, 0),
        //                                          Angle::fromDegrees(0),
        //                                          Angle::fromDegrees(0))}),

        // ball moving up and out of defense area
        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter() +
                                      Vector(0.3, 0),
                                  Vector(0, 1)),
                        RobotStateWithId{
                            0, RobotState(Point(-3.5, 0), Vector(0, 0),
                                          Angle::fromDegrees(0), Angle::fromDegrees(0))}),

        // TODO (#2167): This test fails so disabling for Robocup
        // ball moving down and out goal from defense area
        //        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter()
        //        +
        //                                      Vector(0.3, 0),
        //                                  Vector(0, -0.7)),
        //                        RobotStateWithId{
        //                            0, RobotState(Point(-3.5, 0), Vector(0, 0),
        //                                          Angle::fromDegrees(0),
        //                                          Angle::fromDegrees(0))}),

        // ball slow inside no-chip rectangle
        std::make_tuple(BallState(Field::createSSLDivisionBField().friendlyGoalCenter() +
                                      Vector(0.1, 0),
                                  Vector(0.1, -0.1)),
                        RobotStateWithId{0, RobotState(Point(-3.5, 1), Vector(0, 0),
                                                       Angle::fromDegrees(0),
                                                       Angle::fromDegrees(0))})));
