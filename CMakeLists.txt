cmake_minimum_required(VERSION 3.11)

project(space_invaders)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

# Add SFML library
add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

# Custom target to copy resources (this should copy the res/ directory)
add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/res"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res"
)

# Add the executable for game
add_executable(space_invaders main.cpp "game_system.cpp" "ship.cpp")

add_dependencies(space_invaders copy_resources)

# Include the SFML headers
target_include_directories(space_invaders PRIVATE ${SFML_INCS})

# Link SFML libraries
target_link_libraries(space_invaders sfml-graphics)