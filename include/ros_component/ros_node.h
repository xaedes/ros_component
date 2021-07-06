#pragma once

#include <ros/ros.h>
#include <stdexcept>
#include <memory>
#include "ros_component/ros_component.h"

namespace ros_component {
    
    template<typename TRosComponent>
    class RosNode : public TRosComponent
    {
    public:
        RosNode()
        {}
        
        virtual ~RosNode()
        {}
        
        virtual ros::NodeHandle& getNodeHandle()
        {
            if(m_nh)
            {
                return *m_nh;
            }
            else
            {
                throw std::logic_error("node handle not instantiated.");
            }
        }

        virtual void shutdown()
        {
            ros::shutdown();
        }

        void init(const std::string& name)
        {
            // https://stackoverflow.com/a/1519997
            char  arg0[] = "";
            char* argv[] = { &arg0[0], NULL };
            int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;
            init(argc, argv, name);
        }

        void init(int argc, char* argv[], const std::string& name)
        {
            ros::init(argc, argv, name);
            if(m_nh)
            {
                ROS_WARN("Reinstantiating node handle.");
            }
            m_nh.reset(new ros::NodeHandle("~"));
            this->onInit();
        }

        void run()
        {
            ros::spin();
        }

    protected:
        std::unique_ptr<ros::NodeHandle> m_nh;
    };

} //  namespace ros_component
