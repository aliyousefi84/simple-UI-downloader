cmake_minimum_required(VERSION 3.28.3)
project(test11)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Network REQUIRED)
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)


add_executable(test11
    main.cpp
    ./mainwindow/mainwindow.cpp
    ./mainwindow/mainwindow.hpp
    ./utils/utils.cpp
    ./utils/utils.hpp
    ./downloadwidget/downloadwidget.cpp
    ./downloadwidget/downloadwidget.hpp
    ./progressbar/progressbar.cpp
    ./progressbar/progressbar.hpp
)

target_link_libraries(test11 PRIVATE Qt::Widgets Qt::Network)