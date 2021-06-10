/*
    Author: AJ Blooi 
    File: Rectangle.cpp
    Date: June, 09 , 2021
    purpose: create a 2D axis-aligned Rectangle with floating point coordinates
    check if two rectangles intersect
    Note: I made the rectangles have coordinates for each corner but the 
    top right and bottom left are not needed in this code.
*/
#include <iostream>
#include <vector>
#include "Rectangle.h"


using namespace std;  

// method for constructing a rectangle using width and height, with start
// point at bottom left at x, y. 
Rectangle::Rectangle(float w, float h, float x, float y)
{
    width = w;
    height = h;
    bottomRight = Point2D(x+w, y);
    topRight = Point2D(x+w, y+h);
    bottomLeft = Point2D(x, y);
    topLeft = Point2D(x, y+h);
}

// method for constructing a rectanlge using only 2 coordinates, 
// either point can be a start point.
Rectangle::Rectangle(Point2D& pOne, Point2D& pTwo)
{    
    topLeft = pOne;
    bottomRight = pTwo;
    bottomLeft = Point2D(0,0);
    topRight = Point2D(0,0);
}

void Rectangle::printC()
{
    //  topLeft-----------topRight
    //     |                |
    //     |                |
    //  bottomLeft-------bottomRight
	cout << "(" <<  topLeft.getX() << ", " << topLeft.getY() << "), (" <<
    topRight.getX() << ", " << topRight.getY() << "), (" <<
    bottomLeft.getX() << ", " << bottomLeft.getY() << "), (" <<
    bottomRight.getX() << ", " << bottomRight.getY() << ")" << endl;
}

// method for checking if rectanlges intersect.
bool Rectangle::intersect(Rectangle b)
{ 
    Point2D tl1 = topLeft;
    Point2D tl2 = b.topLeft;
    Point2D br1 = bottomRight;
    Point2D br2 = b.bottomRight;

    //check for if the rectangles are overlaping.
    if (tl1.getX() > br2.getX() || tl2.getX() > br1.getX()) 
    {
        cout << "They do not intersect" << endl;
        return(0);
    }
    if (tl1.getY() < br2.getY() || tl2.getY() < br1.getY()) 
    {
        cout << "They do not intersect" << endl;
        return(0);
    }

    cout << "They intersect" << endl;
    return(1);
    
}

// method for checking if a rectangle intersects with a coordinate.
bool Rectangle::intersect(Point2D p)
{
	if ((bottomLeft.getX() <= p.getX() && bottomRight.getX() >= p.getX()) &&
		(bottomLeft.getY() <= p.getY() && topLeft.getY() >= p.getY()))
	{
        cout << "They intersect" << endl;
		return(1);
	} 
    else 
    {
        cout << "They do not intersect" << endl;
		return(0);
	}
}

int main()
{
    cout << "Creating 2 rectangles using size and coordinate start postion " 
    << "then checking their intersection." << endl;
    Rectangle rec1 = Rectangle(5.2, 3.3, 2, 2);
    Rectangle rec2 = Rectangle(10, 10, 10, 10);
    rec1.printC();
    rec2.printC();
    rec1.intersect(rec2);

    cout << "\nChecking if rec2 intersects with a point." << endl;
    rec2.intersect(Point2D(11,10));

    cout << "\nChecking if rec1 intersects with a point." << endl;
    rec1.intersect(Point2D(11,10));


    cout << "\nCreating 2 rectangles using the method that only uses 2 " << 
    "coordinates for each rectangle, then checking their intersection." << endl;
    Point2D p1 = Point2D(0,5);
    Point2D p2 = Point2D(5,0);
    Point2D p3 = Point2D(1,6);
    Point2D p4 = Point2D(6,1);
    Rectangle rec3 = Rectangle(p1, p2);
    Rectangle rec4 = Rectangle(p3, p4);
    rec3.printC();
    rec4.printC();
    rec3.intersect(rec4);

    cout << "\nreassigning rec1 and rec2 and checking if they intersect." << endl;
    rec1 = Rectangle(5.2, 3.3, 2, 2);
    rec2 = Rectangle(10, 10, 0, 0);
    rec1.printC();
    rec2.printC();
    rec1.intersect(rec2);
    
    cout << "\nChecking if rec2 intersects with rec4." << endl;
    rec2.intersect(rec4);
}