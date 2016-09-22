#include <vector>
#include "Node.h"

#pragma once


using namespace std;

template<class ItemType>
class SortedDoublyLinkedList {
    //DO NOT MODIFY THIS CLASS DECLARATION. FIND T-O-D-O-S to work on.
private:
    Node<ItemType> *head;
    Node<ItemType> *tail;
    int size;
public:

    SortedDoublyLinkedList();

    SortedDoublyLinkedList(Node<ItemType> *head, Node<ItemType> *tail, int size);

    SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list);    // Copy constructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    virtual ~ SortedDoublyLinkedList();    // Destructor should be virtual

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const ItemType &newEntry);

    bool remove(const ItemType &anEntry);

    bool contains(const ItemType &anEntry) const;

    int getFrequencyOf(const ItemType &anEntry) const;

    vector<ItemType> toVector() const;

};

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList() : head(nullptr), tail(nullptr),
                                                             size(0) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(Node<ItemType> *head, Node<ItemType> *tail, int size) :
        head(head), tail(tail), size(size) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list) {
    //TODO - Implement the copy constructor

    size = list.size;
    Node<ItemType> *origChainPtr = list.head;
    if (origChainPtr == nullptr)
        head = nullptr;
    else {
        head = new Node<ItemType>();
        head->setItem(origChainPtr->getItem());
        Node<ItemType> *newChainPtr = head;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}



template<class ItemType>
Node<ItemType> *SortedDoublyLinkedList<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
    bool found = false;
    Node<ItemType> *curPtr = head;
    Node<ItemType> *pointerTo = new Node<ItemType>(target);
    while (!found && (curPtr != nullptr)) {
        if (pointerTo->getItem() == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    }

    return curPtr;
}



template<class ItemType>
SortedDoublyLinkedList<ItemType>::~SortedDoublyLinkedList() {
    //TODO - Implement the destructor
    Node<ItemType> *cur = head;
    while (cur != nullptr){
        head = head->getNext();
        cur->setNext(nullptr);
        delete cur;
        cur = head;
    }
    size = 0;
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getCurrentSize() const {
    //TODO - Return the current size

    return size;
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty

    return size == 0;
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::add(const ItemType &newEntry) {
    //TODO - Add an item to the sorted Doubly Linked list
    Node<ItemType> *newNode= new Node<ItemType>(newEntry);
    Node<ItemType> *cur = head;

    if (head == NULL){
        head = newNode;
        head->setPrev(NULL);
        head->setNext(NULL);
        size++;
        return true;
    }
    if (head->getItem() >= newNode->getItem()){

        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
        newNode->setPrev(NULL);
        size++;
        return true;
    }
    while(cur->getNext() != NULL && cur->getNext()->getItem() < newNode->getItem()){
        cur = cur->getNext();
    }
    if (cur->getNext() == NULL){
        newNode->setNext(NULL);
        newNode->setPrev(cur);
        cur->setNext(newNode);
        cur->setPrev(cur->getPrev());
        tail = newNode;
        size++;
        return true;
    } else {
        newNode->setPrev(cur);
        newNode->setNext(cur->getNext());
        newNode->getNext()->setPrev(newNode);
        cur->setNext(newNode);
        size++;
        return true;
    }
}


template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::remove(const ItemType &anEntry) {
    //TODO - Remove the Item(anEntry) from the list - Return true if successful

    Node<ItemType> *entry = getPointerTo(anEntry);

    if (entry == head){
        head = head->getNext();
        head->setPrev(NULL);
        size--;
        return true;
    } else if (entry == tail){
        tail = entry->getPrev();
        tail->setNext(NULL);
        //tail = entry->getPrev();
        size--;
        return true;
    } else {
        entry->getPrev()->setNext(entry->getNext());
        entry->getNext()->setPrev(entry->getPrev());
        size--;
        return true;
    }
}
template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::contains(const ItemType &anEntry) const {
    //TODO - Check if the List contains the Item(anEntry)- Return true if successful
    return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    //TODO - Return the frequency of the Item(anEntry) in the list
    int frequency = 0;
    int counter = 0;
    Node<ItemType> *curPtr = head;
    while ((curPtr != nullptr) && (counter < size)){
        if (anEntry == curPtr->getItem()){
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template<class ItemType>
vector<ItemType> SortedDoublyLinkedList<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector <ItemType> myVector;
    Node<ItemType> *cur;
    cur = this->head;
    while (cur != nullptr) {
        myVector.push_back(cur->getItem());
        cur = cur->getNext();
    }
    return myVector;
}
