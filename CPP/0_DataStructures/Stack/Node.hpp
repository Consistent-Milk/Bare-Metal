#pragma once
#include "include.hpp"

/**
 * @brief Data Type Agnostic Node struct
 */
template <class T>
struct Node
{
    T data;        // Data at current node
    Node<T> *next; // Pointer to the next node
};