#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>


int main(){

    std::set<int> s;
    std::set<int>::iterator it1, it2; 
    int rNum = 0;
    for(int i=0; i<100; i++){
        rNum = rand() % 1000;
        s.insert(rNum);
    }
    int guess = 500;

    //std::cout << s.size() << std::endl;
    auto a = s.lower_bound(500);
    //auto b = s.upper_bound(500);
    std::cout << *a << " : " << *(--a) << std::endl;
    return 0;
}