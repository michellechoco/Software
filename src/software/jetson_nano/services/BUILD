package(default_visibility = ["//visibility:public"])

cc_library(
    name = "service",
    hdrs = ["service.h"],
)

cc_library(
    name = "motor",
    srcs = ["motor.cpp"],
    hdrs = ["motor.h"],
    deps = [
        ":service",
        "//proto:tbots_cc_proto",
        "//shared:robot_constants",
        "//software/jetson_nano:gpio",
        "//software/logger",
        "@trinamic",
    ],
)
