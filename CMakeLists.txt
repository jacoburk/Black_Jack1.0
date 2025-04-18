cmake_minimum_required(VERSION 3.29)
project(Black_Jack1_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(Black_Jack1_0 main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Game.cpp
        Game.h)
