/*
Name: Wyatt Haley
Class: Data Structures
File name: linkedstack.h
*/

#include "linkedstack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    headPtr = nullptr;
    top = -1;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return top < 0;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    // create a new node with default constructor
    Node<ItemType>* newPtr = new Node<ItemType>();
    // set newPtr's data value to newEntry
    newPtr->setItem(newEntry);
    // set newPtr's next pointer to currentPtr
    newPtr->setNext(headPtr); 
    // set headPtr to newPtr
    headPtr = newPtr;
    // increment top
    top++;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canPop = !isEmpty();

    if(canPop){
        // create node to delete
        Node<ItemType>* deletePointer = headPtr;
        // move headPtr to next item in stack
        headPtr = headPtr->getNext();
        // delete deletePointer
        deletePointer->setNext(nullptr);
        delete deletePointer;
        deletePointer = nullptr;
        top--;
    }

    return canPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return headPtr->getItem();
    }
    
    return canPeek;
}

template<class ItemType>
void LinkedStack<ItemType>::print(){
    if(headPtr == nullptr){
        std::cout << "Nothing in stack currently!" << std::endl;
        return;
    }
    Node<ItemType>* curPtr = headPtr;
    for(int i = 1; i<top+2; i++){
        std::cout << "Position " << i << ": " << curPtr->getItem() << std::endl;
        curPtr = curPtr->getNext(); 
    }
}
