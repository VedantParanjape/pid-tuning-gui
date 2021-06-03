cmake_minimum_required(VERSION 3.1.0)

project(PID-Tuning-GUI VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# Set Path to Qt Cmake
# set(CMAKE_PREFIX_PATH /home/satacker/Qt/5.12.11/gcc_64/lib/cmake/Qt5)
# set(CMAKE_PREFIX_PATH QT_CMAKE_PATH)

# set(Qt5_DIR /home/satacker/Qt/5.12.11/gcc_64/lib/cmake/Qt5/Qt5Config.cmake)
# set(Qt5_DIR QT5_DIR)

find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport REQUIRED)

add_executable(${PROJECT_NAME}
    data_handler.cpp 
    graph_renderer.cpp 
    main.cpp 
    qcustomplot.cpp 
    ui.cpp
    pid_plotter_res.qrc
)

target_link_libraries(${PROJECT_NAME} 
    Qt5::Widgets
    Qt5::PrintSupport
    Qt5::Gui
    Qt5::Core
    boost_thread
    pthread
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")