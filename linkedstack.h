/*
Name: Wyatt Haley
Class: Data Structures
File name: linkedstack.h
*/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "stackinterface.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>{
    private:
        int top;
        Node<ItemType>* headPtr;
    public:
        LinkedStack();
        bool isEmpty() const;
        bool push(const ItemType& newEntry);
        bool pop();
        ItemType peek() const;
        void print();
        ~LinkedStack() {}
};
#include "linkedstack.cpp"
#endif
