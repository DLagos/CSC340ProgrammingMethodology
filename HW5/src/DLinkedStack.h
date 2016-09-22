#pragma once

#include "StackInterface.h"
#include "Node.h"
#include <vector>
#include <cassert>

using namespace std;

template<class ItemType>
class DLinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType> *headPtr;    // Pointer to first node in the chain;
    Node<ItemType> *topPtr;    // Pointer to (last) node in the chain that contains the stack's top
public:

    DLinkedStack();

    DLinkedStack(const DLinkedStack<ItemType> &aStack);    // Copy constructor

    virtual ~ DLinkedStack();    // Destructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    bool isEmpty() const;

    bool push(const ItemType &newItem);

    bool pop();

    ItemType peek() const;

    vector<ItemType> toVector() const;

    Node<ItemType> *getHeadPTR() const;

    Node<ItemType> *getTopPTR() const;
};

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack() : headPtr(nullptr), topPtr(nullptr) {
}

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack(const DLinkedStack<ItemType> &aStack) {
    //TODO - Implement the copy constructor
    Node<ItemType> *cur = aStack.headPtr;
    headPtr = NULL;
    topPtr = NULL;
    while (cur != NULL){
        push(cur->getItem());
        cur = cur->getNext();
    }
}



template<class ItemType>
DLinkedStack<ItemType>::~DLinkedStack() {
    //TODO - Implement the destructor
    if (headPtr == NULL && topPtr == NULL){
        return;
    } else {
        while (!isEmpty()){
            pop();
        }
    }

}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
    Node<ItemType> *nodeToDelete = new Node<ItemType>(target);
    Node<ItemType> *cur = headPtr;
    while (cur){
        if (cur->getItem() == nodeToDelete->getItem()){
            return cur;
        }
        cur = cur->getNext();
    }
    return nullptr;
}

template<class ItemType>
bool DLinkedStack<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty

    return headPtr == NULL;
}

template<class ItemType>
bool DLinkedStack<ItemType>::push(const ItemType &newItem) {
    //TODO - Push an item on the Doubly Linked Stack
    Node<ItemType> *newNode = new Node<ItemType>(newItem);
    //if stack is empty
    if (headPtr == NULL){
        headPtr = newNode; //set newNode to head
        topPtr = newNode;  // also set as top
        //headPtr->setNext(NULL);
        //headPtr->setPrev(NULL);
        return true;
    }
    //
    Node<ItemType> *cur = headPtr;
    while(cur) {
        //if the headPtr is the only item in the stack
        if (cur->getNext() == NULL && cur->getPrev() == NULL) {
            topPtr = newNode;
            cur->setNext(newNode);
            newNode->setNext(NULL);
            newNode->setPrev(headPtr);
            return true;
        } else if (cur->getNext() == NULL){
            topPtr = newNode; //new topPtr
            newNode->setNext(NULL);
            cur->setNext(newNode); //insert newNode
            newNode->setPrev(cur);
            return true;
        }
        cur = cur->getNext(); //traverse the list
    }
    return false;
}

template<class ItemType>
bool DLinkedStack<ItemType>::pop() {
    //TODO - Pop an item from the stack - Return true if successful
    if (headPtr == NULL && topPtr == NULL){
        return false;
    }
    Node<ItemType> *pop = topPtr; //new pointer to top
    if (topPtr->getPrev() != NULL) {
        topPtr = topPtr->getPrev(); //set topPtr to prev
        delete pop; //delete allocated space
        return true;
    } else if (topPtr->getPrev() == NULL){
        topPtr = NULL;
        headPtr = NULL;
        delete pop;
        return true;
    }

}

template<class ItemType>
ItemType DLinkedStack<ItemType>::peek() const {//Assume this never fails.
    //TODO - return the element stored at the top of the stack (topPtr)
    return topPtr->getItem();//return top ptr
}

template<class ItemType>
vector<ItemType> DLinkedStack<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector<ItemType> returnVector;
    // Put stack items into a vector in top to bottom order
    Node<ItemType> *curPtr = topPtr;
    while (curPtr != nullptr) {
        returnVector.push_back(curPtr->getItem());
        curPtr = curPtr->getPrev();
    }
    return returnVector;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getHeadPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return headPtr;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getTopPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return topPtr;
}