cmake_minimum_required(VERSION 3.24)
project(ftCad)

set(CMAKE_CXX_STANDARD 17)

add_library(ftCad STATIC Curve.cpp ConicSection.cpp GeneralCircle.cpp
        GeneralEllipse.cpp Circle.cpp Ellipse.cpp
        Helix.cpp Vect3d.cpp)

target_include_directories(ftCad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_options(ftCad PRIVATE -Werror -Wextra -Wall)

