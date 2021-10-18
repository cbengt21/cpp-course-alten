#ifndef WORK_PRODUCT_HPP_
#define WORK_PRODUCT_HPP_

#include "shop.hpp"

class WorkProduct: public Shop{

    protected:
        types::workProduct_t work_product_;

    public:
        WorkProduct();
        void SetWorkProduct(const types::workProduct_t &parts);
        types::workProduct_t GetWorkProduct();       
};



#endif