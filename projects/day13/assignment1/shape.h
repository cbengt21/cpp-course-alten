#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>
#include <iostream> 

class Shape {
    private:
        int perimeter;
        int area;

    public:
        Shape(const int &p,const int &a);
        bool operator == (const Shape& s);
        bool operator < (const Shape& s);
        bool operator > (const Shape& s);
        void print (){
            std::cout << perimeter << " : " << area << std::endl;
        }
};

class Rectangle : public Shape{
    public:
        Rectangle(int width=0, int height=0): Shape(((width*2)+(height*2)),width*height){}
};

class Circle : public Shape{
    public:
    Circle(int radius=0): Shape(2*3*radius ,2*std::pow(radius, 2)){} 
};



#endif
