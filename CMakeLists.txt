cmake_minimum_required(VERSION 3.10)

project(DragonRage)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp)

add_executable(DragonRage ${SOURCES})
# Linka OpenGL e GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)

target_link_libraries(DragonRage OpenGL::GL glfw)