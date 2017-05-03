#include "main.cpp"
#include "gtest/gtest.h"

TEST(triangle_type_test, BoundryValue){
    EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 1));
    EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 2));
    EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 199));
    EXPECT_EQ(EQUILATERAL, triangle_type(100, 100, 100));
    EXPECT_EQ(NOT_TRIANGLE, triangle_type(100, 100, 200));
    
    EXPECT_EQ(ISOSCELES, triangle_type(100, 1, 100));
    EXPECT_EQ(ISOSCELES, triangle_type(100, 2, 100));
    EXPECT_EQ(ISOSCELES, triangle_type(100, 199, 100));
    EXPECT_EQ(NOT_TRIANGLE, triangle_type(100, 200, 100));

    EXPECT_EQ(ISOSCELES, triangle_type(1, 100, 100));
    EXPECT_EQ(ISOSCELES, triangle_type(2, 100, 100));
    EXPECT_EQ(ISOSCELES, triangle_type(199, 100, 100));
    EXPECT_EQ(NOT_TRIANGLE, triangle_type(200, 100, 100));
}

TEST(triangle_type_test, Equivalence){
    EXPECT_EQ(EQUILATERAL, triangle_type(6, 6, 6));
    
    EXPECT_EQ(INVAILD, triangle_type(-1, 6, 6));
    EXPECT_EQ(INVAILD, triangle_type(6, -1, 6));
    EXPECT_EQ(INVAILD, triangle_type(6, 6, -1));
    
    EXPECT_EQ(INVAILD, triangle_type(201, 6, 6));
    EXPECT_EQ(INVAILD, triangle_type(6, 201, 6));
    EXPECT_EQ(INVAILD, triangle_type(6, 6, 201));
}

TEST(triangle_type_test, EdgeTest){
    EXPECT_EQ(INVAILD, triangle_type(0, 6, 6));
    EXPECT_EQ(INVAILD, triangle_type(201, 6, 6));
    
    EXPECT_NE(INVAILD, triangle_type(1, 6, 6));
    EXPECT_NE(INVAILD, triangle_type(2, 6, 6));
    EXPECT_NE(INVAILD, triangle_type(199, 6, 6));
    EXPECT_NE(INVAILD, triangle_type(200, 6, 6));
}    

TEST(triangle_type_test, PathTesting) {
	// c0
	EXPECT_EQ(INVAILD, triangle_type(201, 5, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, 201, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, 5, 201));
	EXPECT_EQ(NOT_TRIANGLE, triangle_type(200, 100, 100));
	EXPECT_EQ(EQUILATERAL, triangle_type(100, 100, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(2, 100, 100));
	// c1
	EXPECT_EQ(TRIANGLE, triangle_type(5, 4, 3));
}
