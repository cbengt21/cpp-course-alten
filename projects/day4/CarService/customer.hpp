#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include "shop.hpp"

class Customer: public Shop{
    protected:
        types::customerInfo_t customer_info_;

    public:
        Customer();
        void SetCustomerInfo(const types::customerInfo_t &info);
        types::customerInfo_t GetCustomerInfo(const int &number);     

};


#endif