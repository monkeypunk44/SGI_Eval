/*
    Author: AJ Blooi 
    File: Rectangle.h
    Date: June, 09 , 2021
    purpose: 
*/

#ifndef RECTANLE_H
#define RECTANLE_H

#include "Point2D.h"

// For constructing a rectangle, starting point is the bottem left corner.
struct Rectangle
{

    public:
    // method for making a rectangle of specifc size at a coordinate (x,y).
    Rectangle(float w, float h, float x, float y);
    
    // method for making a rectangle that spans one point to the other.
    Rectangle(Point2D& pOne, Point2D& pTwo);

    // method for printing the coordinates of the rectangle.
    void printC();

    // method for checking if rectanlges intersect.
    bool intersect(Rectangle b);

    // method for checking if a rectangle intersects with a point
    bool intersect(Point2D p);

    private:
    // size of the rectangle.
    float width;
    float height;
    // coordinates.
    Point2D bottomRight;
    Point2D topRight;
    Point2D bottomLeft;
    Point2D topLeft;
};

#endif 