#pragma once

#include "Point2D.h"
#include "CustomException.h"

template <class T>
class Circle : public Point2D<T>{
protected:
    T radius;
public:
    Circle();

    Circle(T x, T y, T radius);

    T getRadius();

    void setRadius(T newRadius);

    virtual float area() const;

    virtual float circumference() const;
};

template <class T>
Circle<T>::Circle(){

}

template <class T>
Circle<T>::Circle(T x, T y, T radius) {
    this->setX(x);
    this->setY(y);
    this->setRadius(radius);
}

template <class T>
T Circle<T>::getRadius() {
    return radius;
}

template<class T>
void Circle<T>::setRadius(T newRadius) {
    radius = newRadius;
}
template <class T>
float Circle<T>::area() const {
    return 3.14 * radius * radius;
}

template <class T>
float Circle<T>::circumference() const {
 return 2 * radius * 3.14;
}