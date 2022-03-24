cmake_minimum_required(VERSION 3.20)
project(Pong)

set(CMAKE_CXX_STANDARD 23)

add_executable(Pong main.cpp Ball.cpp Ball.h Field.cpp Field.h Drawing.cpp Drawing.h ConsoleObject.h Player.cpp Player.h Utils/Converter.h Utils/Toolbox.h Game.cpp Game.h Utils/Toolbox.cpp Scoreboard.cpp Scoreboard.h Utils/Converter.cpp)
