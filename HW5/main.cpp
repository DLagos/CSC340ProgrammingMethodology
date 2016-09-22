#include <iostream>
#include "DLinkedStack.h"

using namespace std;

int main() {
    DLinkedStack<int> basicStack;

    basicStack.push(44);
    basicStack.push(88);
    basicStack.push(55);
    basicStack.push(66);
    basicStack.push(77);
    basicStack.push(88);
    basicStack.push(99);
    basicStack.push(999);

    DLinkedStack<int> basicStack2(basicStack);
    //basicStack2.DLinkedStack(basicStack);

    //cout<<basicStack2.peek()<<endl;

    //basicStack.pop();
    //basicStack.pop();
    //basicStack.pop();
    //basicStack.pop();
   // basicStack.pop();
   // basicStack.pop();
    //basicStack.pop();
    //basicStack.pop();
    //cout << basicStack2.isEmpty() << endl;
    //cout<<basicStack.peek()<<endl;

    //cout<<"toVector:"<<endl;

    vector<int> vector1 = basicStack2.toVector();

    for (auto v : vector1) {
      cout << v << endl;
   }
    //cout << basicStack.getPointerTo(55) << endl;
    return 0;
}