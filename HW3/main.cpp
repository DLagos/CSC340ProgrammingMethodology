#include <iostream>
#include <vector>
#include "triangle.h"

using namespace std;

int main() {

    Triangle<float> t1;
    Triangle<float> t2(4, 5, 6);
    Triangle<int> t3(2, 3, 400);
    vector<int> vec = t3.getSides();
    for (auto v:vec)
    std::cout << v << ' ';

    return 0;
}