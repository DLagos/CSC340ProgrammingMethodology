//
// Created by Omar Shaikh on 2/8/16.
//

#include "gtest/gtest.h"
#include <math.h>
#include "SortedDoublyLinkedList.h"

int points = 100;
int currentPoints = 0;

template<class T>
bool equalVectors(vector<T> a, vector<T> b) {
    a.shrink_to_fit();
    b.shrink_to_fit();
    if (a.size() != b.size()) return false;
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }

    }
    return true;
}


TEST(hw4Test, basicConstructorTest) {

    SortedDoublyLinkedList<int> basicList;

    if (HasFailure()) { cerr << "basicConstructorTest has failed" << endl; }

}

TEST(hw4Test, constructorTest) {

    SortedDoublyLinkedList<int> basicList;

    EXPECT_EQ(basicList.getCurrentSize(), 0) << "Expected size 0" << endl;
    EXPECT_TRUE(basicList.isEmpty()) << "Expected list empty" << endl;
    ASSERT_EQ(basicList.getPointerTo(55), nullptr) << "Expected nullptr from getPointerTo()" << endl;
    EXPECT_FALSE(basicList.contains(22)) << "Expected false form contains()" << endl;


    if (HasFailure()) { cerr << "constructorTest has failed" << endl; }

}

TEST(hw4Test, addToListTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);

    vector<int> vector1 = basicList.toVector();
    vector<int> vector2{44, 88};

    EXPECT_TRUE(equalVectors(vector1, vector2));


    if (HasFailure()) {
        points -= 15;
        cerr << "addToListTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 15;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, copyConstructorTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    vector<int> vector1 = basicList.toVector();
    vector<int> vector2{44, 88};
    EXPECT_TRUE(equalVectors(vector1, vector2));

    SortedDoublyLinkedList<int> basicList2 = basicList;

    vector<int> vector3 = basicList2.toVector();
    EXPECT_TRUE(equalVectors(vector1, vector3));


    if (HasFailure()) {
        points -= 10;
        cerr << "copyConstructorTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 10;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, emptyTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);

    EXPECT_FALSE(basicList.isEmpty());


    if (HasFailure()) {
        points -= 5;
        cerr << "emptyTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, sizeTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);

    EXPECT_GT(basicList.getCurrentSize(), 0);


    if (HasFailure()) {
        points -= 5;
        cerr << "sizeTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, removeTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);

    basicList.remove(88);
    vector<int> vector1 = basicList.toVector();
    vector<int> vector2{44};
    EXPECT_FALSE(basicList.isEmpty());
    EXPECT_TRUE(equalVectors(vector1, vector2));


    if (HasFailure()) {
        points -= 5;
        cerr << "removeTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, containsTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(66);
    basicList.add(88);
    basicList.add(88);
    basicList.remove(88);
    EXPECT_FALSE(basicList.isEmpty());
    EXPECT_TRUE(basicList.contains(88));
    EXPECT_TRUE(basicList.contains(66));
    EXPECT_FALSE(basicList.contains(77));


    if (HasFailure()) {
        points -= 5;
        cerr << "containsTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, getFrequencyTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(66);
    basicList.add(88);
    basicList.add(88);
    basicList.remove(88);
    EXPECT_FALSE(basicList.isEmpty());

    EXPECT_EQ(basicList.getFrequencyOf(44), 1);
    EXPECT_EQ(basicList.getFrequencyOf(88), 2);
    EXPECT_EQ(basicList.getFrequencyOf(77), 0);


    if (HasFailure()) {
        points -= 5;
        cerr << "getFrequencyTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, headTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(66);
    basicList.add(88);
    basicList.add(88);
    basicList.remove(88);
    EXPECT_FALSE(basicList.isEmpty());

    Node<int> *node = basicList.getPointerTo(44);
    Node<int> *node2 = basicList.getPointerTo(66);
    Node<int> *node3;
    Node<int> *node4;
    ASSERT_NE(node, nullptr);
    ASSERT_NE(node2, nullptr);
    //ASSERT_NO_FATAL_FAILURE({node3 = node->getPrev();});
    //ASSERT_NO_FATAL_FAILURE({node4 = node2->getPrev();});

    EXPECT_EQ(node->getPrev(), nullptr);
    EXPECT_EQ(node2->getPrev(), node);

    if (HasFailure()) {
        points -= 15;
        cerr << "headTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 15;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, tailTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(66);
    basicList.add(88);
    basicList.add(99);
    basicList.add(999);
    EXPECT_FALSE(basicList.isEmpty());

    Node<int> *node = basicList.getPointerTo(999);
    Node<int> *node2 = basicList.getPointerTo(99);

    ASSERT_NE(node, nullptr);
    ASSERT_NE(node2, nullptr);

    EXPECT_EQ(node->getNext(), nullptr);

    EXPECT_EQ(node2->getNext(), node);

    if (HasFailure()) {
        points -= 15;
        cerr << "tailTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 15;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw4Test, midTest) {

    SortedDoublyLinkedList<int> basicList;
    basicList.add(44);
    basicList.add(88);
    basicList.add(55);
    basicList.add(66);
    basicList.add(77);
    basicList.add(88);
    basicList.add(99);
    basicList.add(999);


    EXPECT_FALSE(basicList.isEmpty());

    Node<int> *node = basicList.getPointerTo(55);
    Node<int> *node2 = basicList.getPointerTo(66);
    Node<int> *node3 = basicList.getPointerTo(77);

    ASSERT_NE(node, nullptr);
    ASSERT_NE(node2, nullptr);
    ASSERT_NE(node3, nullptr);


    EXPECT_EQ(node->getNext(), node2);
    EXPECT_EQ(node2->getNext(), node3);
    EXPECT_EQ(node2->getPrev(), node);
    EXPECT_EQ(node3->getPrev(), node2);

    if (HasFailure()) {
        points -= 20;
        cerr << "midTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
        cout << "FINAL POINTS:" << points << endl;
    } else {
        currentPoints += 20;
        cout << "Current POINTS:" << currentPoints << endl;
    }

    cout << "FINAL POINTS:" << points << endl;

}