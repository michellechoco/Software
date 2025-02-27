load("@rules_proto//proto:defs.bzl", "proto_library")
load("//proto:nanopb.bzl", "nanopb_proto_library")
load("@com_google_protobuf//:protobuf.bzl", "py_proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "tbots_proto",
    srcs = [
        "ball.proto",
        "game_state.proto",
        "geometry.proto",
        "primitive.proto",
        "robot_log_msg.proto",
        "robot_status_msg.proto",
        "standalone_stimulator_config.proto",
        "tbots_software_msgs.proto",
        "tbots_timestamp_msg.proto",
        "team.proto",
        "vision.proto",
        "world.proto",
    ],
    deps = [
        "@nanopb//:nanopb_options_proto",
    ],
)

cc_proto_library(
    name = "tbots_cc_proto",
    deps = [":tbots_proto"],
)

nanopb_proto_library(
    name = "tbots_nanopb_proto",
    deps = [":tbots_proto"],
)

py_proto_library(
    name = "tbots_py_proto",
    srcs = [
        "ball.proto",
        "game_state.proto",
        "geometry.proto",
        "primitive.proto",
        "robot_status_msg.proto",
        "tbots_software_msgs.proto",
        "tbots_timestamp_msg.proto",
        "team.proto",
        "vision.proto",
        "visualization.proto",
        "world.proto",
    ],
    deps = [
        "@nanopb//:nanopb_options_py_proto",
    ],
)

py_proto_library(
    name = "announcement_py_proto",
    srcs = ["announcement.proto"],
)

proto_library(
    name = "ssl_proto",
    srcs = [
        "messages_robocup_ssl_detection.proto",
        "messages_robocup_ssl_geometry.proto",
        "messages_robocup_ssl_wrapper.proto",
        "ssl_gc_common.proto",
        "ssl_gc_game_event.proto",
        "ssl_gc_geometry.proto",
        "ssl_gc_referee_message.proto",
    ],
    visibility = ["//visibility:public"],
)

# These proto files are based on the following commit:
# https://github.com/RoboCup-SSL/ssl-simulation-protocol/commit/b455b4b8a1ed6f6aebaf8e8cd3721b7e130aa9ce
proto_library(
    name = "ssl_simulation_proto",
    srcs = [
        "ssl_simulation_config.proto",
        "ssl_simulation_control.proto",
        "ssl_simulation_error.proto",
        "ssl_simulation_robot_control.proto",
        "ssl_simulation_robot_feedback.proto",
        "ssl_simulation_synchronous.proto",
    ],
    visibility = ["//visibility:private"],
    deps = [
        ":ssl_proto",
        "@com_google_protobuf//:any_proto",
    ],
)

cc_proto_library(
    name = "ssl_simulation_cc_proto",
    deps = [":ssl_simulation_proto"],
)

cc_proto_library(
    name = "any_cc_proto",
    deps = ["@com_google_protobuf//:any_proto"],
)

proto_library(
    name = "sensor_msg_proto",
    srcs = [
        "sensor_msg.proto",
    ],
    visibility = ["//visibility:private"],
    deps = [
        ":ssl_proto",
        ":tbots_proto",
    ],
)

proto_library(
    name = "replay_msg_proto",
    srcs = [
        "replay_msg.proto",
    ],
    visibility = ["//visibility:private"],
    deps = [
        ":sensor_msg_proto",
        ":ssl_proto",
        ":tbots_proto",
    ],
)

proto_library(
    name = "defending_side_msg_proto",
    srcs = [
        "defending_side_msg.proto",
    ],
    visibility = ["//visibility:private"],
)

proto_library(
    name = "repeated_any_msg_proto",
    srcs = [
        "repeated_any_msg.proto",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "@com_google_protobuf//:any_proto",
    ],
)

proto_library(
    name = "visualization_proto",
    srcs = [
        "visualization.proto",
    ],
    deps = [
        ":tbots_proto",
        "@com_google_protobuf//:any_proto",
    ],
)

proto_library(
    name = "play_info_msg_proto",
    srcs = [
        "play_info_msg.proto",
    ],
    visibility = ["//visibility:private"],
)

cc_proto_library(
    name = "ssl_cc_proto",
    deps = [":ssl_proto"],
)

cc_proto_library(
    name = "sensor_msg_cc_proto",
    deps = [":sensor_msg_proto"],
)

cc_proto_library(
    name = "replay_msg_cc_proto",
    deps = [":replay_msg_proto"],
)

cc_proto_library(
    name = "defending_side_msg_cc_proto",
    deps = [":defending_side_msg_proto"],
)

cc_proto_library(
    name = "repeated_any_msg_cc_proto",
    deps = [":repeated_any_msg_proto"],
)

cc_proto_library(
    name = "visualization_cc_proto",
    deps = [":visualization_proto"],
)

cc_proto_library(
    name = "play_info_msg_cc_proto",
    deps = [":play_info_msg_proto"],
)

py_proto_library(
    name = "software_py_proto",
    srcs = [
        "messages_robocup_ssl_detection.proto",
        "messages_robocup_ssl_geometry.proto",
        "messages_robocup_ssl_wrapper.proto",
        "play_info_msg.proto",
        "repeated_any_msg.proto",
        "replay_msg.proto",
        "robot_log_msg.proto",
        "sensor_msg.proto",
        "ssl_gc_common.proto",
        "ssl_gc_game_event.proto",
        "ssl_gc_geometry.proto",
        "ssl_gc_referee_message.proto",
    ],
    deps = [
        ":tbots_py_proto",
    ],
)
