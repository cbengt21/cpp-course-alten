#include "work_product.hpp"


    WorkProduct::WorkProduct(){}

    void WorkProduct::SetWorkProduct(const types::workProduct_t &parts){
        work_product_ = parts;
        return;
    }
    types::workProduct_t WorkProduct::GetWorkProduct(){
        //TODO: implement search for work product. How to connect customer info to work product??
        return work_product_;
    }