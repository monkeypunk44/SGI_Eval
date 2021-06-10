/*
    Author: AJ Blooi 
    File: Point2D.h
    Date: June, 05 , 2021
    purpose: 
*/

#ifndef POINT2D_H
#define POINT2D_H

struct Point2D
{
    public:
    Point2D();
    Point2D(float a, float b);
    float getX();
    float getY();

    private:
    float x;
    float y;
};

#endif 