//
// Created by Omar Shaikh on 2/8/16.
//

#include "gtest/gtest.h"
#include "triangle.h"
#include <math.h>

int points = 100;


TEST(hw3Test, basicConstructor) {
    Triangle<float> t1;

    if (HasFailure()) { points -= 10; }

}


TEST(hw3Test, basicAccessor) {

    Triangle<int> t1(4, 5, 6);
    Triangle<float> t2(4.5, 5.5, 6.5);
    Triangle<int> t3(4.5, 5.5, 6.5);

    vector<int> v1 = t1.getSides();
    vector<float> v2 = t2.getSides();
    vector<int> v3 = t3.getSides();

    vector<int> v1Comp{4, 5, 6};
    vector<float> v2Comp{4.5, 5.5, 6.5};
    vector<int> v3Comp{4, 5, 6};

    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";
    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";
    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";

    EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v1Comp.begin())) << "Vectors are not equal";
    EXPECT_TRUE(std::equal(v2.begin(), v2.end(), v2Comp.begin())) << "Vectors are not equal";
    EXPECT_TRUE(std::equal(v3.begin(), v3.end(), v3Comp.begin())) << "Vectors are not equal";


    if (HasFailure()) { points -= 10; }
}

TEST(hw3Test, basicMutator) {

    Triangle<int> t1;
    Triangle<float> t2;
    Triangle<int> t3;

    t1.setSides(4, 5, 6);
    t2.setSides(4.5, 5.5, 6.5);
    t3.setSides(4.5, 5.5, 6.5);

    vector<int> v1 = t1.getSides();
    vector<float> v2 = t2.getSides();
    vector<int> v3 = t3.getSides();

    vector<int> v1Comp{4, 5, 6};
    vector<float> v2Comp{4.5, 5.5, 6.5};
    vector<int> v3Comp{4, 5, 6};

    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";
    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";
    ASSERT_EQ(v1.size(), v1Comp.size()) << "Vectors are of unequal size";

    EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v1Comp.begin())) << "Vectors are not equal";
    EXPECT_TRUE(std::equal(v2.begin(), v2.end(), v2Comp.begin())) << "Vectors are not equal";
    EXPECT_TRUE(std::equal(v3.begin(), v3.end(), v3Comp.begin())) << "Vectors are not equal";

    if (HasFailure()) { points -= 10; }

}

TEST(hw3Test, simpleAreaTest) {

    Triangle<int> t1(4, 5, 6);
    EXPECT_EQ(t1.getArea(), 6);


    if (HasFailure()) { points -= 10; }
}

TEST(hw3Test, generalizedAreaTest) {

    Triangle<float> t1(4.5, 5.5, 6.5);
    EXPECT_EQ((double) std::trunc(1000 * t1.getArea()) / 1000, (double) std::trunc(1000 * 12.2019) / 1000)
                        << "Area is not correct";

    Triangle<double> t2(4.5, 5.5, 6.5);
    EXPECT_EQ((double) std::trunc(1000 * t2.getArea()) / 1000, (double) std::trunc(1000 * 12.2019) / 1000)
                        << "Area is not correct";

    if (HasFailure()) { points -= 10; }
}

TEST(hw3Test, simplePerimeterTest) {

    Triangle<int> t1(4, 5, 6);
    EXPECT_EQ(t1.getPerimeter(), 15);

    if (HasFailure()) { points -= 10; }
}

TEST(hw3Test, rightTriangleTest) {

    Triangle<int> t1(4, 5, 6);
    Triangle<int> t2(8, 10, 6);

    EXPECT_FALSE(t1.isRightTriangle());
    EXPECT_TRUE(t2.isRightTriangle());

    if (HasFailure()) { points -= 10; }

}

TEST(hw3Test, equilateralTriangleTest) {

    Triangle<int> t1(4, 5, 6);
    Triangle<int> t2(8, 8, 8);

    EXPECT_FALSE(t1.isEquilateral());
    EXPECT_TRUE(t2.isEquilateral());

    if (HasFailure()) { points -= 10; }

}

TEST(hw3Test, isoscelesTriangleTest) {

    Triangle<int> t1(4, 5, 6);
    Triangle<int> t2(11, 11, 6);

    EXPECT_FALSE(t1.isIsosceles());
    EXPECT_TRUE(t2.isIsosceles());

    if (HasFailure()) { points -= 10; }

}


TEST(hw3Test, unknownTest1) {
    Triangle<int> t1(4, 5, 10);

    vector<int> v = t1.getSides();
    vector<int> vComp{4, 5, 6};

    EXPECT_FALSE(std::equal(v.begin(), v.end(), vComp.begin()));

    if (HasFailure()) { points -= 10; }

    std::cout << "Total Points:" << points<<endl;

}