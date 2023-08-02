cmake_minimum_required(VERSION 3.24)
project(CadExchangerTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(CadExchangerTest main.cpp)

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(CadExchangerTest PUBLIC OpenMP::OpenMP_CXX)
endif()


add_subdirectory(src)
target_link_libraries(CadExchangerTest PRIVATE ftCad)
