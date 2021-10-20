#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>

int main(){
    int v[1024];
    /*for (int j=0; j<1024; j++){
        v[j]=0;
    }*/
    int a=0;
    while (a!=1024){
        unsigned int randomvalue = 0;
        randomvalue =  rand() % 33 + 1;
        a++;
        v[a] = randomvalue;
    }

    std::sort(std::begin(v), std::end(v));

    for (int i=0; i<33;i++){
        std::cout << i+1 <<" was randomized "<< v[i] << " times"<< std::endl;
    }
    return 0;
}