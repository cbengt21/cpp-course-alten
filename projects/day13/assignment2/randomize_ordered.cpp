#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>

int main(){
    int v[33];
    for (int j=0; j<33; j++){
        v[j]=0;
    }
    int a=0;
    while (a!=10000){
        unsigned int randomvalue = 0;
        randomvalue =  rand() % 33 + 1;
        a++;
        v[randomvalue-1] +=1;
    }

    std::sort(std::begin(v), std::end(v));

    for (int i=0; i<33;i++){
        std::cout << i+1 <<" was randomized "<< v[i] << " times"<< std::endl;
    }
    return 0;
}
