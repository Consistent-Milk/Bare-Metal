#include "Node.hpp"

using namespace ds;

Node::Node(int value) : nodeValue(value), next(nullptr) {}

int Node::value()
{
    return nodeValue;
}

std::shared_ptr<Node> &Node::nextNode()
{
    return next;
}