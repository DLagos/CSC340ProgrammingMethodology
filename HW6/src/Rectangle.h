#pragma once

#include "Point2D.h"
#include "CustomException.h"

template <class T>
class Rectangle : public Point2D<T>{
protected:
    T width;
    T height;
public:
    Rectangle();
    Rectangle(T x, T y, T width, T height);
    T getWidth();
    T getHeight();
    void setWidth(T newWidth);
    void setHeight(T newHeight);
    virtual float area() const;
    virtual float circumference() const;
};
template<class T>
Rectangle<T>::Rectangle() {

}

template<class T>
Rectangle<T>::Rectangle(T x, T y, T width, T height) {
    this->setX(x);
    this->setY(y);
    this->setWidth(width);
    this->setHeight(height);
}

template<class T>
T Rectangle<T>::getWidth() {
    return width;
}

template<class T>
T Rectangle<T>::getHeight() {
    return height;
}

template<class T>
void Rectangle<T>::setWidth(T newWidth) {
    width = newWidth;
}

template <class T>
void Rectangle<T>::setHeight(T newHeight) {
    height = newHeight;
}

template <class T>
float Rectangle<T>::area() const {
    return width * height;
}

template<class T>
float Rectangle<T>::circumference() const{
    return 0;
}