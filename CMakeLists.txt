cmake_minimum_required(VERSION 3.15)
project(ConsoleCasino LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(consolecasino
    main.cpp
    inputcasino.cpp
    blackjack.cpp
    roulette.cpp
    videopoker.cpp
    baccarat.cpp
    cardwalk.cpp
    guessnumber.cpp
)

if(MSVC)
    target_compile_options(consolecasino PRIVATE /W4)
else()
    target_compile_options(consolecasino PRIVATE -Wall -Wextra)
endif()