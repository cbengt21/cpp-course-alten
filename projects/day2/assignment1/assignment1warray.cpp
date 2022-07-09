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

    for (int i = 0; i < input1; i++)
    {
        Array[i] = new unsigned int *[input2]();

        for (int j = 0; j < input2; j++)
        {
            Array[i][j] = new unsigned int [input3]();

            for(int z=0; z< input3; z++)
            {
                randomvalue =  rand() % 100;
                Array[i][j][z]=randomvalue;
                std::cout << Array[i][j][z] << "\t";  // can also be replaced by *(Array[i][j]+z) 
            }
            std::cout << std::endl; 
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 

    delete [] Array;
    return 0;
}