#include "shape.h"


Shape::Shape(const int &p,const int &a){
    perimeter=p;
    area=a;
}

bool Shape::operator == (const Shape& s){
    if ((this->area == s.area)&& (this->perimeter == s.perimeter)){
        return true;
    }
    return false;
}
bool Shape::operator < (const Shape& s){
    if ((this->area < s.area) || (this->area==s.area && this->perimeter < s.perimeter)){
        return true;
    }
    return false;
}

bool Shape::operator > (const Shape& s){
    if ((this->area > s.area) || (this->area==s.area && this->perimeter > s.perimeter)){
        return true;
    }
    return false;
}