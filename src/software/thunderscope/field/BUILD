package(default_visibility = ["//visibility:public"])

load("@thunderscope_deps//:requirements.bzl", "requirement")

py_library(
    name = "field",
    srcs = ["field.py"],
    deps = [
        ":field_layer",
        requirement("pyqtgraph"),
    ],
)

py_library(
    name = "field_layer",
    srcs = ["field_layer.py"],
    deps = [
        requirement("pyqtgraph"),
    ],
)

py_library(
    name = "obstacle_layer",
    srcs = ["obstacle_layer.py"],
    deps = [
        ":field_layer",
        requirement("pyqtgraph"),
    ],
)

py_library(
    name = "path_layer",
    srcs = ["path_layer.py"],
    deps = [
        ":field_layer",
        requirement("pyqtgraph"),
    ],
)

py_library(
    name = "world_layer",
    srcs = ["world_layer.py"],
    deps = [
        ":field_layer",
        requirement("pyqtgraph"),
    ],
)
