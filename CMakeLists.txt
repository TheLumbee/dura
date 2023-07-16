# Setup simple defaults
cmake_minimum_required(VERSION 3.17)
project(dura)

# Grab the Qt stuff
find_package(Qt6 REQUIRED COMPONENTS Core)

# Get everything together
add_executable(dura main.cpp
	project_creator.cpp)
target_link_libraries(dura PRIVATE Qt6::Core)