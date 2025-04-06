cmake_minimum_required(VERSION 3.30)
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
        #calculator2.cpp
        #math_expression_evaluator.cpp
        #helper2.h
        calculator.cpp
        calculator.h
)
target_link_libraries(QT_GUI_project
  Qt::Core
  Qt::Gui
  Qt::Widgets
)

