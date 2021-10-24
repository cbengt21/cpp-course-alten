#include "shape.h"
#include <iostream>

template <class myType>
void GetMax (myType a, myType b){
    
    if (a > b){
        std::cout << "a is bigger than b"<< std::endl;
    } else{
        std::cout << "a is NOT bigger than b"<< std::endl;
    }
    return;
}

int main(){

    Rectangle rec(2,2);
    Circle circ(2);

    GetMax<Shape>(rec, circ);


    /*if (rec > circ){
        std::cout << "rec is bigger than circ"<< std::endl;
    } else{
        std::cout << "rec is NOT bigger than circ"<< std::endl;
    }
    rec.print();
    circ.print();*/

    return 0;
}