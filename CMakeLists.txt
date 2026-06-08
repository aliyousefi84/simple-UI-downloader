cmake_minimum_required(VERSION 4.2.0)
project(test11)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Network REQUIRED)
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)


add_executable(test11
    main.cpp
    ./mainwindow/mainwindow.cpp
    ./mainwindow/mainwindow.hpp
)

target_link_libraries(test11 PRIVATE Qt::Widgets Qt::Network)