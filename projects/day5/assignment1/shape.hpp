#include <iostream>
#include <cmath>

class Shape {
private:
    int area=0;
    int perimeter =0;
public:    
    Shape()=default;
    Shape(const int &p,const int &a): area(a), perimeter(p){}
    virtual ~Shape () = 0;
    bool operator == (const Shape& s);
    bool operator < (const Shape& s);
    bool operator > (const Shape& s);
    void print (){
        std::cout << perimeter << " " << area << std::endl;
    }
};

class Circle : public Shape {
public:
    ~Circle() = default;
    Circle(const int &radius):Shape((2*3*radius), std::pow(radius,2)){}    
};

class Triangle : public Shape {
public:
    ~Triangle() = default;
    Triangle(const int &width, const int &height):Shape(3*width, height*width/2){}
};
 
class Rectangle : public Shape {
public:
    ~Rectangle() = default;
    Rectangle(const int &width, const int &height):Shape((2*width) + (2*height), width*height){}
};
