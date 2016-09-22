#HW3 Dion Matthew Lagos
TODO - Update your name in this readme.

TODO - Add a badge from travis CI here
[![Build Status](https://travis-ci.com/csc340-03-spring-2016/csc340-03-hw3-DLagos.svg?token=AE1tDQksS5syyCBFuw1p&branch=master)](https://travis-ci.com/csc340-03-spring-2016/csc340-03-hw3-DLagos)

##Problem statement:

Design and implement an ADT that represents a triangle. The data for the ADT must include the three sides of the triangle. This data must be in the private section of the class that implements the ADT.

you must write code in the class **Triangle**, inside `triangle.h` the class **Triangle** inherits from the interface **triangle_interface**
Include at least two initialization operations(constructors): 

* One that provides default values for the ADT’s data (default constructor)
* Another that sets this data to client-supplied values (parametrized constructor)

The ADT also must include operations that(look inside the `triangle_interface.h`):

* look at the values of the ADT’s data
* change the values of the ADT’s data 
* compute the triangle’s area
* determine whether the triangle is
    * a right triangle
    * an equilateral triangle
    * an isosceles triangle.
    
## Constraints
* The class should support the following types via templates:
    * int
    * Float
    * Double

## Files to work on
You are required to work on `README.md` and `/src/triangle.h`
You can also modify `main.cpp` to debug your program.
Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

## Running tests
* To run the program, select the configuration `hw3_run` from the top right and click on run
* You can run the tests using Clion: select the configuration `runMainHW3Tests` from the top right and click on run
* To use Clion's Google test configuration:
    * Goto Run->Edit Configurations..
    * Select the "+" icon on the top left to add a new configuration of type "Google Test"
    * Enter in a name, and also target configuration as "runMainHW3Tests"
    * Select Ok.
    * You can now use this configuration for better test display by CLion.

## Note
* The program would not compile at first because the class hasn't been completed in `triangle.h`
* It is required that you add your **name** and **travis ci badge** to your readme.
* Make sure your last push is before the deadline. Your last push will be considered as your final submission.
* look at this video for how to run CLion tests: https://youtu.be/8Up5eNZ0FLw
