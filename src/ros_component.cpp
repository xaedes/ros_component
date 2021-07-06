#include "ros_component/ros_component.h"

#include <stdexcept>

namespace ros_component {

    RosComponent::RosComponent(){}
    
    RosComponent::~RosComponent()
    {}

    ros::NodeHandle& RosComponent::getNodeHandle()
    {
        throw std::logic_error("getNodeHandle() not implemented by RosComponent. Instantiate RosNode or RosNodelet for this.");
    }

    void RosComponent::shutdown()
    {
        throw std::logic_error("shutdown() not implemented by RosComponent. Instantiate RosNode or RosNodelet for this.");
    }

} //  namespace ros_component
