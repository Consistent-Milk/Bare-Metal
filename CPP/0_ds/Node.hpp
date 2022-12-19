#include "Preprocessors.hpp"

namespace ds
{
    class Node
    {
    private:
        // Value stored in the current code
        int nodeValue;
        // Pointer to the next node in the link
        std::shared_ptr<Node> next;

    public:
        // Getter
        int value();

        // Getter
        std::shared_ptr<Node> &nextNode();

        explicit Node(int value = 0);
    };
}
