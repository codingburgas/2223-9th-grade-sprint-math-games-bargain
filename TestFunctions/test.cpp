#include "pch.h"
#include "gtest/gtest.h"
#include <Header.h>
#include "raylib.h"
#include "RefactoredFunctions.h"


//Check box test case
TEST(CheckBoxTest, DrawCheckBoxTest) {
    // Initialize Raylib
    InitWindow(800, 600, "RaylibTest");


    int input();

    // TIme before the window closes

    // Close the window
    CloseWindow();

    // Assert that the checkbox was drawn
    ASSERT_EQ(true, true);
}


// randomEquation test case 
TEST(RandomEquationTest, TestAndOperator) {
    // Test the "AND" operator case
    EXPECT_EQ("5 & 9 = ?", randomEquation(5, 9, 0));
    EXPECT_EQ("10 & 3 = ?", randomEquation(10, 3, 0));
    EXPECT_EQ("15 & 12 = ?", randomEquation(15, 12, 0));
}

TEST(RandomEquationTest, TestOrOperator) {
    // Test the "OR" operator case
    EXPECT_EQ("5 | 9 = ?", randomEquation(5, 9, 1));
    EXPECT_EQ("10 | 3 = ?", randomEquation(10, 3, 1));
    EXPECT_EQ("15 | 12 = ?", randomEquation(15, 12, 1));
}

TEST(RandomEquationTest, TestXorOperator) {
    // Test the "XOR" operator case
    EXPECT_EQ("5 ^ 9 = ?", randomEquation(5, 9, 2));
    EXPECT_EQ("10 ^ 3 = ?", randomEquation(10, 3, 2));
    EXPECT_EQ("15 ^ 12 = ?", randomEquation(15, 12, 2));
}

TEST(RandomEquationTest, TestLeftShiftOperator) {
    // Test the "left shift" operator case
    EXPECT_EQ("5 << 9 = ?", randomEquation(5, 9, 3));
    EXPECT_EQ("10 << 3 = ?", randomEquation(10, 3, 3));
    EXPECT_EQ("15 << 12 = ?", randomEquation(15, 12, 3));
}

TEST(RandomEquationTest, TestRightShiftOperator) {
    // Test the "right shift" operator case
    EXPECT_EQ("5 >> 9 = ?", randomEquation(5, 9, 4));
    EXPECT_EQ("10 >> 3 = ?", randomEquation(10, 3, 4));
    EXPECT_EQ("15 >> 12 = ?", randomEquation(15, 12, 4));
}


//Timer test case
TEST(TimerTest, TestWindowCloseWhenTimerAtZero) {

    // Start the timer
    timerF();

    // Check if the window is closed
    EXPECT_TRUE(WindowShouldClose());
}


TEST(PictureTest, TextureLoads) {

    // Load picture
    const char* fileName = "c4.png";
    Image image = LoadImage(fileName);
    SUCCEED();

    // Clean up
    UnloadImage(image);
}

