project(Flow)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Flow_SRCS Flow.cpp main.cpp)
qt4_automoc(${Flow_SRCS})
add_executable(Flow ${Flow_SRCS})
target_link_libraries(Flow ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
