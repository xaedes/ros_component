#pragma once

#include <ros/ros.h>
#include <string>

namespace ros_component {

    class RosComponent
    {
    public:
        RosComponent();
        virtual ~RosComponent();
        virtual void onInit() = 0;
        virtual ros::NodeHandle& getNodeHandle();
        virtual void shutdown();
    };

} //  namespace ros_component
