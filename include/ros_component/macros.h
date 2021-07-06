#pragma once

#define ROS_NODE_MAIN(TRosComponentClass, NodeClassName, node_name)                      \
                                                                                         \
    class NodeClassName : public ros_component::RosNode<TRosComponentClass>         \
    {};                                                                                  \
                                                                                         \
    int main(int argc, char **argv)                                                      \
    {                                                                                    \
        NodeClassName node;                                                              \
        node.init(argc, argv, node_name);                                                \
        node.run();                                                                      \
    }                                                                                    

#define ROS_NODELET(TRosComponentClass, NodeletClassName)                              \
                                                                                       \
    class NodeletClassName : public ros_component::RosNodelet<TRosComponentClass> \
    {};                                                                                \
                                                                                       \
    PLUGINLIB_EXPORT_CLASS(NodeletClassName, nodelet::Nodelet);
