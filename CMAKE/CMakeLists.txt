cmake_minimum_required(VERSION 3.0.0)
project(FirstProject VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(FirstProject main.cpp)
target_compile_features(FirstProject PUBLIC cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
