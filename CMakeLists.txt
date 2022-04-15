cmake_minimum_required(VERSION 3.20)
project(Pong)

set(CMAKE_CXX_STANDARD 23)

add_executable(Pong src/main.cpp src/Ball.cpp include/Ball.h src/Field.cpp include/Field.h src/Drawing.cpp include/Drawing.h include/ConsoleObject.h src/Player.cpp include/Player.h Utils/Converter.h Utils/Toolbox.h src/Game.cpp include/Game.h Utils/Toolbox.cpp src/Scoreboard.cpp include/Scoreboard.h Utils/Converter.cpp src/StorageService.cpp include/StorageService.h src/StorageRepository.cpp include/IStorageRepository.h)
