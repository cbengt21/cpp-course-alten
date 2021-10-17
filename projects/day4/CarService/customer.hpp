#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <iostream>
#include <unordered_map>
#include "car_service_configurations.hpp"



class Customer{
    private:
        std::unordered_map<types::CustomerInfo, types::WorkProduct> customer_work_info_;
        
    public:
        Customer();
        void SetCustomerInfo(const types::customerInfo_t &info);
        types::customerInfo_t GetCustomerInfo();
        void SetWorkProduct(const types::workProduct_t &parts);
        types::workProduct_t GetWorkProduct();       
};

#endif  //customer.hpp