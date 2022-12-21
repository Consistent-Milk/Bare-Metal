#include "Node.hpp"
#include "LinkedList.hpp"

int main(void)
{
    LinkedList<int> l;

    l.append(1);
    l.append(2);

    l.display();
}