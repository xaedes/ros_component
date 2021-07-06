cmake_minimum_required(VERSION 2.8.3)
project(ros_component)

set(CMAKE_CXX_STANDARD 11)

# catkin packages
find_package(
    catkin 
    REQUIRED COMPONENTS
    nodelet
    roscpp
)

# create catkin package for project
set(LIBRARY_NAME "${PROJECT_NAME}")

catkin_package(
    LIBRARIES ${LIBRARY_NAME}
    INCLUDE_DIRS include
    CATKIN_DEPENDS 
    nodelet 
    roscpp 
)

# create the component library
add_library(
    ${LIBRARY_NAME}  
    src/ros_component.cpp
)
include(GenerateDependency)
target_link_libraries(${LIBRARY_NAME} catkin)
target_include_directories(${LIBRARY_NAME} PUBLIC include)

# install library 
install(TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install header files
install(
    DIRECTORY 
    include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
    FILES_MATCHING PATTERN "*.h"
)
