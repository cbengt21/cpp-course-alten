#ifndef RECORD_HPP_
#define RECORD_HPP_


#include "customer.hpp"
#include "work_product.hpp"

class Record:public Customer, public WorkProduct{
    private:


    public:
        Record();
        void RecordInfo();

};


#endif