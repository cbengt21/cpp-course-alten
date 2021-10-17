#include <iostream>
#include "customer.hpp"


main(){
    
    std::cout << "Select choice: 1)Add new job, 2)get info on earlier jobs" << std::endl;
    int choice; 
    std::cin >> choice;
    if ( choice == 1){
        Customer a;
        types::customerInfo_t customer_data;
        std::cout << "Enter name" << std::endl;
        std::cin >> customer_data.types::CustomerInfo::name;
        std::cout << "Enter personal number" << std::endl;
        std::cin >> customer_data.types::CustomerInfo::personal_number;
        std::cout << "Enter date" << std::endl;
        std::cin >> customer_data.types::CustomerInfo::date;
        a.SetCustomerInfo(customer_data);
        types::workProduct_t work_product;
        std::cout << "Oil change? [y]=yes, [n]=no" << std::endl;
        char oil;
        std::cin >> oil;
        if (oil==0x79){
            work_product.oilChange = true;
        } else{
            work_product.oilChange = false;
        }
        int service;
        std::cout << "Service type? [1]=big, [2]=small, [3]=no service" << std::endl;
        std::cin >> service;
        if(service ==1){
            work_product.
        }
    }

    
}