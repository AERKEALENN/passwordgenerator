cmake_minimum_required(VERSION 3.10)
project(PasswordGeneratorQt5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(passwordgenerator
    main.cpp
    passwordgenerator.cpp
    passwordgenerator.h
)

target_link_libraries(passwordgenerator Qt5::Widgets)

set_target_properties(passwordgenerator PROPERTIES
    OUTPUT_NAME "passwordgenerator"
)
