project(Flow)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(OpenGL REQUIRED)

#set(QT_USE_QTOPENGL TRUE)


set(Flow_SRCS World.cpp Simulator.cpp FlowGLWin.cpp main.cpp)
set(Flow_SRCS_UI FlowUI.ui)
set(Flow_SRCS_MOC_HEAD FlowGLWin.h)

QT4_WRAP_CPP(Flow_SRCS_MOC_SRCS ${Flow_SRCS_MOC_HEAD})
QT4_WRAP_UI(Flow_SRCS_UI_H ${FLow_SRCS_UI})

include_directories( ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} )

#qt4_automoc(${Flow_SRCS})
add_executable(Flow ${Flow_SRCS} ${Flow_SRCS_MOC_SRCS} ${Flow_SRCS_UI_H} )
target_link_libraries(Flow ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${OPENGL_LIBRARIES} )

