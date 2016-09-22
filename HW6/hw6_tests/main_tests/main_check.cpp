//
// Created by Omar Shaikh on 2/8/16.
//

#include "gtest/gtest.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "CustomException.h"

using namespace std;

int currentPoints = 0;

//CONSTRUCTOR TESTS
TEST(hw6TestCircle, basicConstructorCircle) {
    Circle<int> *circleInt = new Circle<int>(2, 2, 4);
    Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, 4.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw6TestRectangle, basicConstructorRectangle) {
    Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, 6);
    Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, 5.4, 6);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestSquare, basicConstructorSquare) {
    Square<int> *squareInt = new Square<int>(3, 3, 3);
    Square<float> *squareFloat = new Square<float>(5.5, 3, 4.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

//AREA TESTS
TEST(hw6TestCircle, circleAreaTest) {
    Circle<int> *circleInt = new Circle<int>(2, 2, 4);
    Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, 4.4);
    EXPECT_FLOAT_EQ(circleInt->area(), 50.24);
    EXPECT_FLOAT_EQ(circleFloat->area(), 60.7904);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestRectangle, rectangleAreaTest) {
    Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, 6);
    Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, 5.4, 6);
    EXPECT_FLOAT_EQ(rectangleInt->area(), 30);
    EXPECT_FLOAT_EQ(rectangleFloat->area(), 32.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestSquare, squareAreaTest) {
    Square<int> *squareInt = new Square<int>(3, 3, 3);
    Square<float> *squareFloat = new Square<float>(5.5, 3, 4.4);
    EXPECT_FLOAT_EQ(squareInt->area(), 9);
    EXPECT_FLOAT_EQ(squareFloat->area(), 19.36);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

//CENTER POINT TESTS
TEST(hw6TestCircle, circleCenterTest) {
    Circle<int> *circleInt = new Circle<int>(2, 2, 4);
    Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, 4.4);
    EXPECT_EQ(circleInt->getX(), 2);
    EXPECT_EQ(circleInt->getY(), 2);
    EXPECT_FLOAT_EQ(circleFloat->getX(), 4.4);
    EXPECT_FLOAT_EQ(circleFloat->getY(), 2.2);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestRectangle, rectangleCenterTest) {
    Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, 6);
    Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, 5.4, 6);
    EXPECT_EQ(rectangleInt->getX(), 4);
    EXPECT_EQ(rectangleInt->getY(), 4);
    EXPECT_FLOAT_EQ(rectangleFloat->getX(), 4.4);
    EXPECT_FLOAT_EQ(rectangleFloat->getY(), 4.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestSquare, squareCenterTest) {
    Square<int> *squareInt = new Square<int>(3, 3, 3);
    Square<float> *squareFloat = new Square<float>(5.5, 3, 4.4);
    EXPECT_EQ(squareInt->getX(), 3);
    EXPECT_EQ(squareInt->getY(), 3);
    EXPECT_FLOAT_EQ(squareFloat->getX(), 5.5);
    EXPECT_FLOAT_EQ(squareFloat->getY(), 3);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

//SHAPE ATTRIBUTE TESTS
TEST(hw6TestCircle, circleRadiusTest) {
    Circle<int> *circleInt = new Circle<int>(2, 2, 4);
    Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, 4.4);
    EXPECT_EQ(circleInt->getRadius(), 4);
    EXPECT_FLOAT_EQ(circleFloat->getRadius(), 4.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestRectangle, rectangleWHTest) {
    Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, 6);
    Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, 5.4, 6);
    EXPECT_EQ(rectangleInt->getWidth(), 5);
    EXPECT_EQ(rectangleInt->getHeight(), 6);
    EXPECT_FLOAT_EQ(rectangleFloat->getWidth(), 5.4);
    EXPECT_FLOAT_EQ(rectangleFloat->getHeight(), 6);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestSquare, squareSideTest) {
    Square<int> *squareInt = new Square<int>(3, 3, 3);
    Square<float> *squareFloat = new Square<float>(5.5, 3, 4.4);
    EXPECT_EQ(squareInt->getWidth(), 3);
    EXPECT_EQ(squareInt->getHeight(), 3);
    EXPECT_FLOAT_EQ(squareFloat->getWidth(), 4.4);
    EXPECT_FLOAT_EQ(squareFloat->getWidth(), 4.4);
    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}


//EXCEPTIONS  TESTS
TEST(hw6TestCircle, circleExceptionTest) {
    EXPECT_THROW(Circle<int> *circleInt = new Circle<int>(2, 2, -4), CustomException);
    EXPECT_THROW(Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, -4.4), CustomException);

    try {
        Circle<int> *circleInt = new Circle<int>(2, 2, -4);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 22);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }

    try {
        Circle<float> *circleFloat = new Circle<float>(4.4, 2.2, -4.4);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 22);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestRectangle, rectangleExceptionTest) {
    EXPECT_THROW(Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, -6), CustomException);
    EXPECT_THROW(Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, -5.4, 6), CustomException);

    try {
        Rectangle<int> *rectangleInt = new Rectangle<int>(4, 4, 5, -6);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 33);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }
    try {
        Rectangle<float> *rectangleFloat = new Rectangle<float>(4.4, 4.4, -5.4, 6);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 33);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw6TestSquare, squareExceptionTest) {


    EXPECT_THROW(Square<int> *squareInt = new Square<int>(3, 3, -3), CustomException);
    EXPECT_THROW(Square<float> *squareFloat = new Square<float>(5.5, 3, -4.4), CustomException);

    try {
        Square<int> *squareInt = new Square<int>(3, 3, -3);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 33);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }
    try {
        Square<float> *squareFloat = new Square<float>(5.5, 3, -4.4);
    } catch (CustomException &CE) {
        EXPECT_EQ(CE.getErrorCode(), 33);
    } catch (exception &e) {
        FAIL();
        cout << "DEFAULT EXCEPTION, THIS SHOULD NOT HAPPEN " << e.what();
    }


    if (!HasFailure())currentPoints += 10;
    cout << "FINAL POINTS:" << currentPoints << endl;
}
