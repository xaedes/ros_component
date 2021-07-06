#pragma once

#include <nodelet/nodelet.h>
#include <nodelet/NodeletUnload.h>
#include <pluginlib/class_list_macros.h>

namespace ros_component {

    template<typename TRosComponent>
    class RosNodelet : public nodelet::Nodelet, public TRosComponent
    {
    public:
        RosNodelet(){}
        virtual ~RosNodelet(){}

        virtual void onInit()
        {
            TRosComponent::onInit();
        }

        virtual ros::NodeHandle& getNodeHandle()
        {
            return nodelet::Nodelet::getPrivateNodeHandle();
        }

        virtual void shutdown()
        {
            // https://github.com/ros/nodelet_core/issues/33
            nodelet::NodeletUnload unload_service;
            unload_service.request.name = nodelet::Nodelet::getName();
            auto res = ros::service::call(ros::this_node::getName() + "/unload_nodelet", unload_service);
            if(!res)
            {
                // unload service is unavailable when nodelet is started standalone.
                // a shutdown of the node (only containing this nodelet) should be ok
                ros::shutdown();
            }
        }
    };

} //  namespace ros_component
