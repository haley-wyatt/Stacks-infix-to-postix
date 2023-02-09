/*
Name: Wyatt Haley
Class: CS 302 w/ Erin Keith
Date: 10/01/2022
Programming Assignment 3
File name: stackinterface.h
*/

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <iostream>

template<class ItemType>
class StackInterface{
    private:
    public:
        virtual bool isEmpty() const =0;
        virtual bool push(const ItemType& newEntry) = 0;
        virtual bool pop() = 0;
        virtual ItemType peek() const = 0;
        virtual ~StackInterface() {}
};
#endif