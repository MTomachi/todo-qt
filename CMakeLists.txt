cmake_minimum_required(VERSION 3.16)
project(TodoApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Let Qt's meta-object compiler (moc) run automatically on our headers
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt (tries Qt6 first, falls back to Qt5)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(TodoApp
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

target_link_libraries(TodoApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
