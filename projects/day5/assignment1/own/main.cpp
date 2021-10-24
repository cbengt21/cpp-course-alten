#include "shape.h"
#include <iostream>

int main(){

    Rectangle rec(2,2);
    Circle circ(2);

    if (rec > circ){
        std::cout << "rec is bigger than circ"<< std::endl;
    } else{
        std::cout << "rec is NOT bigger than circ"<< std::endl;
    }
    rec.print();
    circ.print();

    return 0;
}