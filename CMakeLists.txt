cmake_minimum_required(VERSION 3.24)
project(CadExchangerTest)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(src)

#add_executable(CadExchangerTest main.cpp)
#target_link_libraries(CadExchangerTest PRIVATE ftCad)

add_executable(CadExchangerTest main.cpp src/Vect3d.cpp src/Curve.cpp
                src/ConicSection.cpp src/GeneralCircle.cpp src/Circle.cpp
                src/GeneralEllipse.cpp src/Ellipse.cpp src/Helix.cpp)
