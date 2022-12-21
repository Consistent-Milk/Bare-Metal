#include "Node.hpp"
#include "LinkedList.hpp"

int main(void)
{
    LinkedList l = LinkedList("AB");

    l.append("CD");
    l.append("EF");

    l.display();
}