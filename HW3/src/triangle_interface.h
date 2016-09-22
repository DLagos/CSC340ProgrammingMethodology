#pragma once

#include <vector>

/*
 * Design and implement an ADT that represents a triangle.
 * The data for the ADT should include the three sides of the triangle but could also include the triangle’s three angles.
 * This data should be in the private section of the class that implements the ADT.
 * Include at least two initialization operations: one that provides default values for the ADT’s data, and another that sets this data to client-supplied values.
 * These operations are the class’s constructors.
 * The ADT also should include operations that look at the values of the ADT’s data;
 *  - change the values of the ADT’s data;
 *  - compute the triangle’s area;
 *  - and determine whether the triangle is a right triangle, an equilateral triangle, or an isosceles triangle.
 */


template<class itemType>
class triangleInterface {
public:

    /** Sets or modifies the sides of this triangle. Ensures that the new sides form a triangle. */
    virtual void setSides(itemType newSide1, itemType newSide2, itemType newSide3) = 0;

    /** Gets the three sides of this triangle.
     * @return A vector containing the values of the sides. */
    virtual std::vector<itemType> getSides() const = 0;

    /** Computes the area of this triangle. @return This triangle's area. */
    virtual itemType getArea() const = 0;

    /** Computes the perimeter of this triangle. @return This triangle's perimeter. */
    virtual itemType getPerimeter() const = 0;

    /** @return True if this triangle is a right triangle. */
    virtual bool isRightTriangle() const = 0;

    /** @return True if this triangle is an equilateral triangle. */
    virtual bool isEquilateral() const = 0;

    /** @return True if this triangle is an isosceles triangle. */
    virtual bool isIsosceles() const = 0;
};
