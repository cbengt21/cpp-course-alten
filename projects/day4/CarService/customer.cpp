#include "customer.hpp"


    Customer::Customer(){}

    void Customer::SetCustomerInfo(const types::customerInfo_t &info){
        customer_info_ = info;
    }
    types::customerInfo_t Customer::GetCustomerInfo(const int &number){
        //TODO: implement search for customer. How to connect customer info to work product??
        return customer_info_;
    }