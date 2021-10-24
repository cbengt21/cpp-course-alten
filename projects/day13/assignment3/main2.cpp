#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>


int main(){

    std::set<int> s;
    std::set<int>::iterator it1, it2; 
    int rNum = 0;
    for(int i=0; i<1024; i++){
        rNum = rand() % 10000;
        s.insert(rNum);
    }
    int guess = rand() % 1000;

    //std::cout << s.size() << std::endl;
    auto a = s.lower_bound(guess);
    //auto b = s.upper_bound(500);
    std::cout << "Randomized nr to search with is: "<< guess << std::endl;
    std::cout << *a << " : " << *(--a) << std::endl;
    return 0;
}