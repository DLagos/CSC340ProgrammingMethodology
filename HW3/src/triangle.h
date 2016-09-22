//
// Created by Omar Shaikh on 2/23/16.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class T>
class Triangle : public triangleInterface<T> {
private:
    T firstSide;
    T secondSide;
    T thirdSide;
    //vector<T> sides;
public:
    Triangle();
    Triangle(T x, T y, T z);
    void setSides(T side1, T side2, T side3 );
    vector<T> getSides()const;
    T getArea() const;
    T getPerimeter() const;
    bool isRightTriangle() const;
    bool isEquilateral() const;
    bool isIsosceles()const;


};
template<class T>
Triangle<T>::Triangle(){

}
template<class T>
Triangle<T>::Triangle(T x, T y, T z){
    firstSide = x;
    secondSide = y;
    thirdSide = z;
}
template<class T>
void Triangle<T>::setSides(T side1, T side2, T side3) {
    firstSide = side1;
    secondSide = side2;
    thirdSide = side3;

}
template<class T>
vector<T> Triangle<T>::getSides() const{
    vector<T> sides;
    sides.resize(3);
    sides[0] = firstSide;
    sides[1] = secondSide;
    sides[2] = thirdSide;
    return sides;
}
template<class T>
T Triangle<T>::getArea() const{
    return sqrt((getPerimeter()/2)*((getPerimeter()/2)-firstSide)*((getPerimeter()/2)-secondSide)*((getPerimeter()/2)-thirdSide));
}
template<class T>
T Triangle<T>::getPerimeter() const {
    return firstSide + secondSide + thirdSide;
}
template<class T>
bool Triangle<T>::isRightTriangle() const{
    T a = firstSide * firstSide;
    T b = secondSide * secondSide;
    T c = thirdSide * thirdSide;
    if (a + b == c){
        return true;
    } else if (a + c == b){
        return true;
    } else if (b + c == a){
        return true;
    } else {
        return false;
    }
}
template<class T>
bool Triangle<T>::isEquilateral() const{
    if ((firstSide == secondSide) && (firstSide == thirdSide)) {
        return true;
    } else {
        return false;
    }
}
template<class T>
bool Triangle<T>::isIsosceles() const{
    return (firstSide == secondSide) || (firstSide == thirdSide) || (secondSide == thirdSide);
}
#endif //HW3_TRIANGLE_H
