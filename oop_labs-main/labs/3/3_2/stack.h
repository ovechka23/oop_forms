#pragma once
#include <iostream>

template <class T>
struct StackElem
{
    StackElem<T>* nxt = nullptr;
    T val;
};

template <class T>
class Stack
{
    StackElem<T>* head = nullptr;
public:
    Stack() : head(nullptr) {}

    ~Stack()
    {
        clear();
    }

    void append(T val)
    {
        StackElem<T>* elem = new StackElem<T>;
        elem->val = val;
        elem->nxt = head;
        head = elem;
    }

    void get_size()
    {
        int size = 0;
        for (StackElem<T>* cur = head; cur != nullptr; cur = cur->nxt)
            size++;
        return size;
    }

    StackElem<T>* get_head()
    {
        return head;
    }

    T peek(T val)
    {
        return head == nullptr ? 0 : head->val;
    }

    T pop()
    {
        if (head == nullptr)
            return 0;
        T val = head->val;
        StackElem<T>* elem = head;
        head = elem->nxt;
        delete elem;
        return val;
    }

    void print()
    {
        int i = 0;
        for (StackElem<T>* cur = head; cur != nullptr; cur = cur->nxt)
        {
            printf("[%d] ", i++);
            std::cout << cur->val << std::endl;
        }
    }

    void clear()
    {
        while (head)
        {
            StackElem<T>* elem = head;
            head = head->nxt;
            delete elem;
        }
    }
};
