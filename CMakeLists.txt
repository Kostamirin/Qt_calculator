cmake_minimum_required(VERSION 3.28)
project(QT_GUI_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(QT_GUI_project
        main.cpp
        Progressions/secondwindow.cpp
        head.cpp
        styles/resources.qrc
        Progressions/arithmetic_progression.cpp
        calculatorwindow.cpp
        calculatorwindow.cpp
        calculatorwindow.cpp
)

target_link_libraries(QT_GUI_project
  Qt::Core
  Qt::Gui
  Qt::Widgets
)
