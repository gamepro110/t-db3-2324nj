file(
    GLOB_RECURSE
    appSrc
    "src/*.cpp"
    "src/*.h"
)

add_executable(
    app
    "${appSrc}"
)

target_link_libraries(
    app
    PUBLIC
    lib
)

target_include_directories(
    app
    PUBLIC
    "${PROJECT_SOURCE_DIR}/lib/src/"
)
