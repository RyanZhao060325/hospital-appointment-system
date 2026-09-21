#pragma once

template <class T>

class myList
{
public:
    struct Node
    {
        T data;
        Node *next;
    };

    myList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void add(T val)
    {
        Node *node = new Node;
        node->data = val;
        node->next = nullptr;

        if (this.head == nullptr)
        {
            head_ = node;
        }
        else
        {
            tail_->next = node;
            tail_ = node;
        }
    }

    Node *find(T val)
    {
        Node *cur = head_;
        while (cur != nullptr)
        {
            if (cur->data == val)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }
    
};
