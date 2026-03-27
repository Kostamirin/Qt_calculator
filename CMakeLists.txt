cmake_minimum_required(VERSION 3.28)
project(QT_GUI_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Add this line


find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(QT_GUI_project
        main.cpp
        Progressions/secondwindow.cpp
        ProgramFiles/head.cpp
        Progressions/arithmetic_progression.cpp
        Progressions/geometric_progression.cpp
        mainWindow.cpp
        mainWindow.h
        Functions/functions.cpp
        Functions/functions.h
        Assets/baseWindow.cpp
        Assets/baseWindow.h
)

target_link_libraries(QT_GUI_project
  Qt::Core
  Qt::Gui
  Qt::Widgets
)
