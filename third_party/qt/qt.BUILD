load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "qt_core",
    srcs = [
        "lib/libQt5Core.so",
        "lib/libQt5Core.so.5",
    ],
    hdrs = glob(["include/QtCore/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Core",
    # ],
)

cc_library(
    name = "qt_network",
    srcs = [
        "lib/libQt5Network.so",
        "lib/libQt5Network.so.5",
    ],
    hdrs = glob(["include/QtNetwork/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Network",
    # ],
)

cc_library(
    name = "qt_widgets",
    srcs = [
        "lib/libQt5Widgets.so",
        "lib/libQt5Widgets.so.5",
    ],
    hdrs = glob(["include/QtWidgets/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Widgets",
    # ],
    deps = [
        ":qt_core",
        ":qt_gui",
    ],
)

cc_library(
    name = "qt_quick",
    srcs = [
        "lib/libQt5Quick.so",
        "lib/libQt5Quick.so.5",
    ],
    hdrs = glob(["include/QtQuick/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Quick",
    # ],
    deps = [
        ":qt_gui",
        ":qt_qml",
        ":qt_qml_models",
    ],
)

cc_library(
    name = "qt_qml",
    srcs = [
        "lib/libQt5Qml.so",
        "lib/libQt5Qml.so.5",
    ],
    hdrs = glob(["include/QtQml/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Qml",
    # ],
    deps = [
        ":qt_core",
        ":qt_network",
    ],
)

cc_library(
    name = "qt_qml_models",
    srcs = [
        "lib/libQt5QmlModels.so",
        "lib/libQt5QmlModels.so.5",
    ],
    hdrs = glob(["include/QtQmlModels/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5QmlModels",
    # ],
)

cc_library(
    name = "qt_gui",
    srcs = [
        "lib/libQt5Gui.so",
        "lib/libQt5Gui.so.5",
    ],
    hdrs = glob(["include/QtGui/**"]),
    includes = ["include"],
    # linkopts = [
    #     "-lQt5Gui",
    # ],
    deps = [":qt_core"],
)

cc_library(
    name = "qt_opengl",
    srcs = [
        "lib/libQt5OpenGL.so",
        "lib/libQt5OpenGL.so.5",
    ],
    hdrs = glob(["include/QtOpenGL/**"]),
    includes = ["include"],
    # linkopts = ["-lQt5OpenGL"],
)

cc_library(
    name = "qt_3d",
    srcs = glob([
        "lib/Qt53D*.so",
        "lib/Qt53D*.so.5",
    ]),
    hdrs = glob([
        "include/Qt3DAnimation/**",
        "include/Qt3DCore/**",
        "include/Qt3DExtras/**",
        "include/Qt3DInput/**",
        "include/Qt3DLogic/**",
        "include/Qt3DQuick/**",
        "include/Qt3DQuickAnimation/**",
        "include/Qt3DQuickExtras/**",
        "include/Qt3DQuickInput/**",
        "include/Qt3DQuickRender/**",
        "include/Qt3DQuickScene2D/**",
        "include/Qt3DRender/**",
    ]),
    includes = ["include"],
    linkopts = [
        "-lQt53DAnimation",
        "-lQt53DCore",
        "-lQt53DExtras",
        "-lQt53DInput",
        "-lQt53DLogic",
        "-lQt53DQuick",
        "-lQt53DQuickAnimation",
        "-lQt53DQuickExtras",
        "-lQt53DQuickInput",
        "-lQt53DQuickRender",
        "-lQt53DQuickScene2D",
        "-lQt53DRender",
    ],
)
