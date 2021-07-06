#include "component_example/ros_component.h"
#include "lib.h"

namespace component_example {

    ExampleComponent::ExampleComponent() : m_value(0) {}
    ExampleComponent::~ExampleComponent(){}

    void ExampleComponent::onInit()
    {
        ros::NodeHandle& nh = getNodeHandle();
        nh.getParam("value", m_value);
        m_pub = nh.advertise<std_msgs::Float64>("out", 10);
        m_sub = nh.subscribe("in", 10, &ExampleComponent::callback, this);
    }

    void ExampleComponent::callback(const std_msgs::Float64::ConstPtr& input)
    {
        std_msgs::Float64Ptr output(new std_msgs::Float64());

        // call the ros independent library
        output->data = add(input->data, m_value);
        
        m_pub.publish(output);
    }

}
