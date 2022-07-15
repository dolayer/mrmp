cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(robot_planner LANGUAGES  CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/) 

add_subdirectory( test )
add_subdirectory( src )



