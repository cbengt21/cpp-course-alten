#include <iostream>


int main() {
    unsigned int input1 =0;
    unsigned int input2 =0;
    unsigned int input3 =0;
    unsigned int randomvalue = 0;


    std::cout << "Write first dimension: " << std::endl;
    std::cin >> input1;
    std::cout << "Write second dimension: " << std::endl;
    std::cin >> input2;
    std::cout << "Write third dimension: " << std::endl;
    std::cin >> input3;

    int* a = new int[input1 * input2 * input3];

    for(int first=0; first<input1; first++)
    {
        for(int second=0; second<input2 ; second++)
        {
            for(int third = 0; third<input3; third++)
            {
                randomvalue =  rand() % 100;
                *(a + (first * input2 * input3) + (second * third) + third) = randomvalue;
            }
        }
    }

    for(int first=0; first<input1; first++)
    {
        for(int second=0; second<input2 ; second++)
        {
            for(int third = 0; third<input3; third++)
            {
                std::cout << *(a + (first * input2 * input3) + (second * third) + third) << "\t";
            }
            std::cout << std::endl; 
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 

    delete[] a;
    a = nullptr;
}