/*
    Author: AJ Blooi 
    File: Point2D.cpp
    Date: June, 09 , 2021
*/
#include <iostream>
#include <vector>
#include "Point2D.h"

// place holder for x and y. 
Point2D::Point2D()
{
    x = 0;
    y = 0;
}

// assigns values to x and y.
Point2D::Point2D(float a, float b)
{
    x = a;
    y = b;
}

// gets x for return.
float Point2D::getX()
{
    return(x);
}

//gets y for return.
float Point2D::getY()
{
    return(y);
}