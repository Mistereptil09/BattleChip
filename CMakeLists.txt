cmake_minimum_required(VERSION 4.0)
project(BattleChip C)

set(CMAKE_C_STANDARD 11)

include_directories(code/src/board)
include_directories(code/src/game)

add_executable(BattleChip
        code/src/board/board.c
        code/src/board/board.h
        code/src/config/config.c
        code/src/display/display.c
        code/src/game/game.c
        code/src/game/game.h
        code/src/main.c)
