#pragma once
#include "ros_component/ros_component.h"

#include <ros/ros.h>
#include <std_msgs/Float64.h>

namespace component_example {

    class ExampleComponent : public ros_component::RosComponent
    {
    public:
        ExampleComponent();
        virtual ~ExampleComponent();

    protected:
        virtual void onInit();

    private:
        void callback(const std_msgs::Float64::ConstPtr& input);

        double m_value;
        ros::Publisher m_pub;
        ros::Subscriber m_sub;
    };

}
