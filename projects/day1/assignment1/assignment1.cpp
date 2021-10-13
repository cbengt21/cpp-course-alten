#include <iostream>


int main() {
    unsigned int a[8][9][11];
    unsigned int input =0;
    unsigned int randomvalue = 0;


    std::cout << "Write a positive number: " << std::endl;
    std::cin >> input;
    for(int first=0; first<8; first++)
    {
        for(int second=0; second<9 ; second++)
        {
            for(int third = 0; third<11; third++)
            {
                randomvalue =  rand() % input;  
                a[first][second][third] = randomvalue;
            }
        }
    }

    for(int first=0; first<8; first++)
    {
        for(int second=0; second<9 ; second++)
        {
            for(int third = 0; third<11; third++)
            {
                std::cout << a[first][second][third] << "\t";
            }
            std::cout << std::endl; 
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}