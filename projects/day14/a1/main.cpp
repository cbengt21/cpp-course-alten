#include <iostream>
#include <bitset>
#include <cstring>

void read(const uint16_t &a){
    
    std::cout << "uint16_t\t= " << std::bitset<16>(a) << std::endl;

    //belts
    uint16_t MASK = 0xF800; //1111100000000000;
    auto b = std::bitset<16>((a & MASK) >> 11);
    std::cout << "Seat Belt \t= " << b << std::endl;

    //Window
    MASK = 0x0780; //0000 0111 1000 0000;
    b = std::bitset<16>((a & MASK) >> 7);
    std::cout << "Windows \t= " << b << std::endl;

    //Door
    MASK = 0x0078; //0000 0000 0111 1000;
    b = std::bitset<16>((a & MASK)>>3);
    std::cout << "Doors \t\t= " << b << std::endl;

    //Lights
    MASK = 0x0007; //0000 0000 0000 0111;
    b = std::bitset<16>(a & MASK);
    std::cout << "Lights \t\t= " << b << std::endl;

    return;
}

int main(){              //belts    window  door lights
    uint16_t a= 0xBA5B;// 10111     0100    1011 011;

    read(a);

    return 0;
}



















