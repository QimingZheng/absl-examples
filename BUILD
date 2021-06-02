cc_binary(
    name="hello_world",
    deps = ["@com_google_absl//absl/strings"],
    srcs= ["hello_world.cc"],
)

cc_binary(
    name = "main",
    deps = ["@com_google_absl//absl/strings", "@com_google_absl//absl/base", "@com_google_absl//absl/base:config",
        "@com_google_absl//absl/base:core_headers", "@com_google_absl//absl/meta:type_traits",
        "@com_google_absl//absl/algorithm:container", "@com_google_absl//absl/container:btree"],
    srcs = ["main.cc"]
)

cc_binary(
    name = "meta",
    deps = ["@com_google_absl//absl/strings", "@com_google_absl//absl/base", "@com_google_absl//absl/base:config",
        "@com_google_absl//absl/base:core_headers", "@com_google_absl//absl/meta:type_traits",
        "@com_google_absl//absl/algorithm:container", "@com_google_absl//absl/container:btree"],
    srcs = ["meta.cc"]
)

cc_binary(
    name = "status_example",
    deps = ["@com_google_absl//absl/status:status"],
    srcs = ["status_example.cc"]
)