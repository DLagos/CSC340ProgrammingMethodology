#include <iostream>
#include "SortedDoublyLinkedList.h"

using namespace std;


int main() {


    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(55);
    basicList.add(66);
    basicList.add(77);
    basicList.add(88);
    basicList.add(99);
    basicList.add(999);
    //basicList.remove(66);
    SortedDoublyLinkedList<int> basicList2(basicList);
    vector<int> vector1 = basicList2.toVector();
    
    for (auto v : vector1) {
        cout << v << endl;
    }


    return 0;
}