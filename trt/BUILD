load("@org_tensorflow//tensorflow:tensorflow.bzl", "tf_cc_binary", "if_tensorrt")

tf_cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "@org_tensorflow//tensorflow/cc:cc_ops",
        "@org_tensorflow//tensorflow/cc:client_session",
        "@org_tensorflow//tensorflow/core:tensorflow",
    ] + if_tensorrt([
        "@local_config_tensorrt//:nv_infer",
    ]),
    #copts = if_tensorrt(["-DGOOGLE_TENSORRT=1", "-DGOOGLE_CUDA"]),
)
