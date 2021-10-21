#include <iostream>
#include <bitset>
#include <cstring>

uint16_t read(const uint16_t &a){
    uint16_t return_value=0;
    std::cout  << std::bitset<16>(a) << "  uint16_t" << std::endl;

    //speed
    uint16_t MASK = 0xF000; //1111000000000000;
    auto b = std::bitset<16>((a & MASK) >> 12);
    
    int mybit_int;
    mybit_int = (int)(b.to_ulong());
    mybit_int = mybit_int*10/20;
    uint16_t b2 = static_cast<uint16_t>(mybit_int);
    //std::cout << b2 << std::endl;
    auto s = std::bitset<16>(b2<<12);
    std::cout << s << "  Speed (multiplied by ten, divided by 20)"<< std::endl;
    

    //Distance front:
    MASK = 0x0E00; //0000111000000000;
    b = std::bitset<16>((a & MASK) >> 9);
    mybit_int;
    mybit_int = (int)(b.to_ulong());
    mybit_int = mybit_int*100/150;
    b2 = static_cast<uint16_t>(mybit_int);
    //std::cout << b2 << std::endl;
    auto df = std::bitset<16>(b2<<9);
    std::cout << df << "  Distance front (multiplied by hundred, divided by 150)"<< std::endl;

    //Distance rear:
    MASK = 0x01C0; //0000000111000000;
    b = std::bitset<16>((a & MASK) >> 6);
    mybit_int;
    mybit_int = (int)(b.to_ulong());
    mybit_int = mybit_int*100/150;
    b2 = static_cast<uint16_t>(mybit_int);
    //std::cout << b2 << std::endl;
    auto drear = std::bitset<16>(b2<<6);
    std::cout << drear << "  Distance rear (multiplied by hundred, divided by 150)"<< std::endl;

    //Distance right:
    MASK = 0x0038; //0000000000111000;
    b = std::bitset<16>((a & MASK) >> 9);
    mybit_int;
    mybit_int = (int)(b.to_ulong());
    mybit_int = mybit_int*100/150;
    b2 = static_cast<uint16_t>(mybit_int);
    //std::cout << b2 << std::endl;
    auto dright = std::bitset<16>(b2<<9);
    std::cout << dright << "  Distance right (multiplied by hundred, divided by 150)"<< std::endl;

    //Distance left:
    MASK = 0x0007; //0000000000000111;
    b = std::bitset<16>((a & MASK));
    mybit_int;
    mybit_int = (int)(b.to_ulong());
    mybit_int = mybit_int*100/150;
    b2 = static_cast<uint16_t>(mybit_int);
    //std::cout << b2 << std::endl;
    auto dleft = std::bitset<16>(b2);
    std::cout << dleft << "  Distance left (multiplied by hundred, divided by 150)"<< std::endl;

    auto bits = std::bitset<16>(dleft | dright | drear | df | s);
    return_value = (int)(bits.to_ulong());
    return return_value;
}

int main(){              //speed    front   rear    right   left
    uint16_t a= 0xBB5B;// 1011      101     101     011     011
                        // 1011 1011 0101 1011

    a=read(a);
    std::cout << std::bitset<16>(a) << "  result" << std::endl;

    return 0;
} 



















