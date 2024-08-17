cmake_minimum_required(VERSION 3.28)
project(learningcpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-march=native -mtune=native -g -O0 -Wall -Wextra -Wpedantic -Werror -fuse-ld=mold")
set(CMAKE_CXX_FLAGS_RELEASE "-march=x86-64-v3 -Os -Wall -Wextra -Wpedantic -Werror -fdata-sections -ffunction-sections -Wl,--gc-sections -fuse-ld=mold")

add_executable(learningcpp src/main.cpp
        src/util/util.cpp
        src/util/util.h
        src/games/games.h
        src/games/lorem_world.cpp
        src/games/calculator.cpp
)
