// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>

struct Node
{
    int data;
    Node *next;
};

// Function Prototypes
void insertNode(int x);
void printLinkedList();

// The pointer to the address of the head of
// the linked list is stored in global scope
// and hence can be accessed in any part of the program

Node *head;

int main(void)
{
    // Initially the list is empty
    // thus the head points to NULL
    head = NULL;
    int n{0};
    int x{0};

    std::cout << fmt::format("How many Nodes?\n");
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << fmt::format("\nEnter a number to store in a node: ");
        std::cin >> x;
        insertNode(x);
        printLinkedList();
    }
}

void insertNode(int x)
{
    Node *temp = new Node();
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}

void printLinkedList()
{
    // We don't want to modify the pointer 'head'
    // which is why we are defining a new pointer to head
    Node *traverser = head;

    std::cout << "The current linked list is: \n";
    while (traverser != NULL)
    {
        std::cout << "Data: " << traverser->data << " Address: " << traverser << "\n";
        traverser = (*traverser).next;
    }
}