cmake_minimum_required(VERSION 3.5)
project(TestCam)

set(CMAKE_CXX_STANDARD 11)

#Qt shit !
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS
        Core
        REQUIRED)
message(STATUS "Qt Found !")
## End of those shit
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(
        ${OpenCV_INCLUDE_DIRS}
)
LIST(APPEND LINK_LIBS
        ${OpenCV_LIBS})

add_executable(TestCam main.cpp)
TARGET_LINK_LIBRARIES(TestCam ${LINK_LIBS})