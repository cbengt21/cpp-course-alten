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

    unsigned int ***Array = new unsigned int **[input1];

    for (size_t i = 0; i < input1; i++){
        *(Array+i) = new unsigned int *[input2];
    }

    return 0;
}