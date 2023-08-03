cmake_minimum_required(VERSION 3.24)

project(ftCadTest)

# Locate Google Test
find_package(GTest REQUIRED)

# Add a test executable
add_executable(tests
        gtest_main.cpp gtest_Vect3d.cpp gtest_GeneralCircle.cpp gtest_Circle.cpp gtest_GeneralEllipse.cpp gtest_Ellipse.cpp gtest_Helix.cpp)

# Link the test executable with Google Test
target_compile_options(tests PRIVATE --coverage)
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main --coverage)

# Register your test executable with CTest
include(GoogleTest)
gtest_discover_tests(tests)

target_link_libraries(tests PRIVATE ftCad)

# Configure CTest for coverage reports
set(CMAKE_CXX_FLAGS "--coverage")