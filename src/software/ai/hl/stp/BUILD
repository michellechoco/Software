package(default_visibility = ["//visibility:public"])

cc_library(
    name = "stp",
    srcs = [
        "stp.cpp",
    ],
    hdrs = ["stp.h"],
    deps = [
        "//shared/parameter:cpp_configs",
        "//software/ai/hl",
        "//software/ai/hl/stp/play",
        "//software/ai/hl/stp/tactic",
        "//software/ai/hl/stp/tactic:all_tactics",
        "//software/ai/intent:stop_intent",
        "//software/ai/motion_constraint:motion_constraint_set_builder",
        "//software/util/generic_factory",
        "//software/util/typename",
        "@munkres_cpp",
    ],
)

cc_test(
    name = "stp_referee_command_play_selection_test",
    srcs = ["stp_referee_command_play_selection_test.cpp"],
    deps = [
        ":stp",
        "//shared/test_util:tbots_gtest_main",
        "//software/ai/hl/stp/play:all_plays",
        "//software/test_util",
        "//software/world",
    ],
)

cc_test(
    name = "stp_tactic_assignment_test",
    srcs = ["stp_tactic_assignment_test.cpp"],
    deps = [
        ":stp",
        "//shared/parameter:cpp_configs",
        "//shared/test_util:tbots_gtest_main",
        "//software/ai/hl/stp/play:halt_play",
        "//software/test_util",
    ],
)

cc_test(
    name = "stp_test",
    srcs = ["stp_test.cpp"],
    deps = [
        ":stp",
        "//shared/test_util:tbots_gtest_main",
        "//software/ai/hl/stp/play/test_plays:halt_test_play",
        "//software/ai/hl/stp/play/test_plays:move_test_play",
        "//software/test_util",
        "//software/util/generic_factory",
    ],
)
