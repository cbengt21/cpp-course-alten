#include <iostream>
#include <string.h>


int main() {
    unsigned int key = 0;
    std::cout << "Give me the Key please: " << std::endl;
    std::cin >> key;
    std::cout<<"Enter the message:\n";
    std::string msg;
    std::cin >> msg;

    char c;
    for(int i = 0; i < msg.size(); i++){
        c = msg[i];
        c = c - key;
        if ( (c< 'A')){
            c=c+ 'Z'-'A'+1;
        }
        msg[i]=c;
    }
    std::cout << "Decrypted message: " << msg  << std::endl;
}