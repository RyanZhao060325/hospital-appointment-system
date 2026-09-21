#pragma once

template <class T>

class myQueue
{
public:
    struct Node
    {
        T data;
        Node *node;
    };

    myQueue() : top_(nullptr),
};