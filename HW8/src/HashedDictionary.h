#pragma once

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <exception>
#include <unordered_map>
#include <vector>


#define DEFAULT_SIZE 101

/**
 *
 * This Hash table is of fixed max size 101 - which is a prime number (why?)
 */
template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> **hashTable;  // Array of pointers to entries
    int itemCount;
    int hashTableSize; //Default value should be assigned to 101

    int getHashIndex(const KeyType &itemKey) const;

    void destroyDictionary();

public:


    virtual ~HashedDictionary();

    HashedDictionary();

    bool isEmpty() const override;

    int getNumberOfItems() const override;

    bool add(const KeyType &searchKey, const ItemType &newItem) override;

    bool remove(const KeyType &searchKey) override;

    void clear() override;

    ItemType getItem(const KeyType &searchKey) const override;

    bool contains(const KeyType &searchKey) const override;

    void traverse(void (*visit)(ItemType &)) const override;

    std::vector<ItemType> toVector() const override;

    HashedEntry<KeyType, ItemType> &operator[](KeyType key);


};

/**
 * DO NOT MODIFY THESE
 */
template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &key) const {
    //DO NOT MODIFY
    return static_cast<int>(key % hashTableSize);
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
        : itemCount(0), hashTableSize(DEFAULT_SIZE) {
    //DO NOT MODIFY
    hashTable = new HashedEntry<KeyType, ItemType> *[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++)
        hashTable[i] = nullptr;
}


template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void (*visit)(ItemType &)) const {
    //DO NOT MODIFY
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            visit(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
}

template<class KeyType, class ItemType>
std::vector<ItemType> HashedDictionary<KeyType, ItemType>::toVector() const {
    //DO NOT MODIFY
    std::vector<ItemType> returnVector;
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            returnVector.push_back(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
    return returnVector;
};


template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType> &HashedDictionary<KeyType, ItemType>::operator[](KeyType searchKey) {
    //DO NOT MODIFY
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *chainPtr = hashTable[itemHashIndex];

    // Short circuit evaluation is important here
    while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey())) {
        chainPtr = chainPtr->getNext();
    } // end while

    if (chainPtr == nullptr)
        throw std::exception();

    return *chainPtr;
}

/**
 * DO NOT MODIFY THE ABOVE
 */

/**
 * TODO IMPLEMENT THE REQUIRED BELOW
 */

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary() {
    //TODO
    //set all values to null
for (int i = 0; i < hashTableSize; i++){
    hashTable[i] = NULL;

}
    itemCount = 0;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    //TODO
    return itemCount == 0;
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    //TODO
    return itemCount;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType &searchKey, const ItemType &newItem) {
    //TODO


    //if the index at hashed key is already full, create linked chain of HashedEntries
    if (hashTable[getHashIndex(searchKey)] != NULL) {
        HashedEntry<KeyType, ItemType> *newEntry1 = new HashedEntry<KeyType, ItemType>(searchKey, newItem, hashTable[getHashIndex(searchKey)]);
        hashTable[getHashIndex(searchKey)] = newEntry1;
        itemCount++;
        return true;

        //otherwise, just add at that index
    } else if (hashTable[getHashIndex(searchKey)] == NULL) {
        HashedEntry<KeyType, ItemType> *newEntry = new HashedEntry<KeyType, ItemType>(searchKey, newItem);
        hashTable[getHashIndex(searchKey)] = newEntry;
        itemCount++;
        return true;
        //if unable to add
    } else {
        return false;
    }
}
template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {
    //TODO

    //if there is a linked chain at the hashed key
    if (hashTable[getHashIndex(searchKey)] != NULL && hashTable[getHashIndex(searchKey)]->getNext() != NULL) {
        hashTable[getHashIndex(searchKey)]->setNext(NULL);
        itemCount--;
        return true;

        //otherwise, just set the value at that index to null
    } else if (hashTable[getHashIndex(searchKey)] != NULL && hashTable[getHashIndex(searchKey)]->getNext() == NULL) {
        hashTable[getHashIndex(searchKey)] = NULL;
        itemCount--;
        return true;

        //if remove fails
    } else {
        return false;
    }

}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const {
    //TODO

    if (hashTable[searchKey] == NULL){
        throw std::exception();
    }

    return hashTable[getHashIndex(searchKey)]->getItem();

}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {
    //TODO

    return hashTable[searchKey] != NULL;
}


