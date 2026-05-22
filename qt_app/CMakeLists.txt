cmake_minimum_required(VERSION 3.15)
project(qt_app)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.3/mingw_64")
set(CMAKE_PREFIX_PATH "C:/Qt/6.11.1/mingw_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt_standard_project_setup()

add_executable(qt_app src/main.cpp
        src/MainWindow.cpp
        src/MainWindow.h)

target_link_libraries(qt_app
        Qt::Core
        Qt::Gui
        Qt::Widgets
        translator
)