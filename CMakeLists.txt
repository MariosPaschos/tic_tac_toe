cmake_minimum_required(VERSION 3.12)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp Cell.cpp Cell.h Utils.cpp Utils.h Player.cpp Player.h Human.cpp Human.h Game.cpp Game.h Machine.cpp Machine.h Node.cpp Node.h Tree.cpp Tree.h Board.cpp Board.h Training.cpp Training.h AIGame.cpp AIGame.h GameServer.cpp GameServer.h Client.cpp Client.h OnlineGame.cpp OnlineGame.h)