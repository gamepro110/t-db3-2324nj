include_guard(GLOBAL)

include(GoogleTest)

function(AddTest TestName src libs)
    set(fullName "${PROJECT_NAME}_${TestName}")
    set(_runtime "${fullName}_Tests")

    add_executable(
        ${_runtime}
        ${src}
    )

    set_target_properties(
        ${_runtime}
        PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        FOLDER "Tests/"
    )

    target_include_directories(
        ${_runtime}
        PUBLIC
        "${PROJECT_SOURCE_DIR}/lib/src"
        GTest::gtest_main
    )

    target_link_libraries(
        ${_runtime}
        PUBLIC
        GTest::gtest_main
        ${libs}
    )

    gtest_discover_tests("${_runtime}")
    add_test("${_runtime}" "${_runtime}")
endfunction(AddTest TestName src libs)
