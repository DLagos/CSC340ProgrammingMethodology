#pragma once

#include "Point2D.h"
#include "Rectangle.h"

template <class T>
class Square : public Rectangle<T>{
public:
    Square(T x, T y, T side);


};
template <class T>
Square<T>::Square(T x, T y, T side) {
    this->setX(x);
    this->setY(y);
    this->setHeight(side);
    this->setWidth(side);

}