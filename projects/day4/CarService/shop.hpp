#ifndef SHOP_HPP_
#define SHOP_HPP_
#include "car_service_types.hpp"
#include <unordered_map>

class Shop{
    protected:
        std::unordered_map<int, types::WorkProduct> work_info_;
        std::unordered_map<int, types::CustomerInfo> customer_info_;
        int customer_id_=0;

    public:
        Shop();
        void UpdateShopCustomerData(const types::customerInfo_t &customer_info);
        //types::customerInfo_t GetCustomerInfo();
};

#endif