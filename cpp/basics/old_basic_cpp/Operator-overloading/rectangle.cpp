#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle()
{
    length=0;
    width=0;
}

Rectangle::Rectangle(double l, double w)
{
    length=l;
    width=w;
}

void Rectangle::setLength(double l)
{
    length=l;
}

void Rectangle::setWidth(double w)
{
    width=w;
}

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

//copy constructor
// Rectangle::Rectangle(Rectangle &copy)
// {
//     length=copy.length;
//     width=copy.width;
// }
const Rectangle Rectangle::operator +(const Rectangle &otherRect) const
{
    Rectangle temp;
    temp.length=length+otherRect.length;
    temp.width=width+otherRect.width;

    return temp;
}

Rectangle& Rectangle:: operator=(const Rectangle &otherRect)
{
    if( this== &otherRect)
        return *this;
    this->length=otherRect.length;
    this->width=otherRect.length;
    
    return *this;
}   

const Rectangle Rectangle::operator -(const Rectangle &otherRect)const 
{
    Rectangle temp;
    temp.length=length-otherRect.length;
    temp.width=width-otherRect.width;

    return temp;
}

bool Rectangle::operator ==(const Rectangle &otherRect) const
{
    return(length==otherRect.length && width==otherRect.width);
}

bool Rectangle::operator !=(const Rectangle &otherRect) const
{
    return(length!=otherRect.length && width!= otherRect.width);
}

bool Rectangle::operator >(const Rectangle &otherRect) const
{
    //will return by area
    float area1, area2;
    area1=(length*width);
    area2=(otherRect.length* otherRect.width);
    return area1>area2;
}

std::ostream& operator<<(std::ostream& objectOut, const Rectangle& rec)
{
    objectOut<<"Length: "<<rec.length<<'\n';
    objectOut<<"Width: "<<rec.width<<'\n';
    objectOut<<"Area: "<<(rec.length*rec.width)<<'\n';
    return objectOut;
}

std::istream& operator>>(std::istream& isObject, Rectangle& rec)
{
    isObject >>rec.length>>rec.width;
    return isObject;
}