cmake_minimum_required(VERSION 2.8.3)
project(component_example)

include(GenerateDependency)
set(CMAKE_CXX_STANDARD 11)

# To use non-ROS packages find them before catkin_package. later add 
# them to catkin_package DEPENDS and add generate_dependency call 
# find_package(OpenCV REQUIRED)


# catkin packages
find_package(
    catkin 
REQUIRED COMPONENTS
    ros_component
    nodelet
    roscpp
    std_msgs
)

# create catkin package for project
set(LIBRARY_NAME "${PROJECT_NAME}")
set(COMPONENT_NAME "${PROJECT_NAME}_component")
set(NODELET_NAME "${PROJECT_NAME}_nodelet")
set(NODE_NAME "${PROJECT_NAME}_node")
catkin_python_setup()
catkin_package(
LIBRARIES 
    ${LIBRARY_NAME}
    ${COMPONENT_NAME}
    ${NODELET_NAME}
CATKIN_DEPENDS 
    ros_component
    nodelet
    roscpp
    std_msgs
DEPENDS 
    # e.g. OpenCV
)

# create the library, component library, nodelet library and node
include(GenerateDependency)
add_library(${LIBRARY_NAME} src/lib.cpp)
add_library(${COMPONENT_NAME} src/lib_component.cpp)
add_library(${NODELET_NAME} src/nodelet.cpp)
add_executable(${NODE_NAME} src/node.cpp)

target_link_libraries(${LIBRARY_NAME} catkin)

target_link_libraries(${COMPONENT_NAME} catkin)
target_link_libraries(${COMPONENT_NAME} ${LIBRARY_NAME})
target_link_libraries(${NODELET_NAME} ${COMPONENT_NAME})
target_link_libraries(${NODE_NAME} ${COMPONENT_NAME})

# install library 
install(
TARGETS 
    ${LIBRARY_NAME}
    ${COMPONENT_NAME}
    ${NODELET_NAME}
    ${NODE_NAME}
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

# install other files
install(
    FILES 
    nodelet_plugins.xml 
    launch/node.launch
    launch/nodelet.launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

