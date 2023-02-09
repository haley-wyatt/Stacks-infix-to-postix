/*
Name: Wyatt Haley
Class: CS 302 w/ Erin Keith
Date: 10/01/2022
Programming Assignment 3
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