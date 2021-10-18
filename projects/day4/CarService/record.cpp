#include "record.hpp"


    Record::Record(){
        RecordInfo();
    }

    void Record::RecordInfo(){
        for(;;){
            types::customerInfo_t customer_data;
            types::workProduct_t work_product;

            std::cout << "Select choice: 1)Add new job, 2)get info on earlier jobs " << std::endl;
            int choice; 
            std::cin >> choice;
            if ( choice == 1){
                std::cout << "Enter name" << std::endl; 
                std::cin >> customer_data.types::CustomerInfo::name;    //no checks
                std::cout << "Enter personal number" << std::endl;
                std::cin >> customer_data.types::CustomerInfo::personal_number;
                std::cout << "Enter date" << std::endl;
                std::cin >> customer_data.types::CustomerInfo::date;
                SetCustomerInfo(customer_data);
                
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
                    work_product.service_type == types::workProduct_t::ServiceType::kBigService;
                } else if (service==2){
                    work_product.service_type == types::workProduct_t::ServiceType::kSmallService;
                } else {
                    work_product.service_type == types::workProduct_t::ServiceType::kNoService;
                }
                int pay;
                std::cout << "Choose payment method: [1]=cash, [2]=card, [3]=swish, [4]=crypto" << std::endl;
                std::cin >> pay;
                if(pay ==1){
                    work_product.payment_method == types::workProduct_t::PaymentMethod::kCash;
                } else if (pay==2){
                    work_product.payment_method == types::workProduct_t::PaymentMethod::kCard;
                } else if(pay==3){
                    work_product.payment_method == types::workProduct_t::PaymentMethod::kSwish;
                } else{
                    work_product.payment_method == types::workProduct_t::PaymentMethod::kCrypto;
                }
                SetWorkProduct(work_product);
            } else if(choice == 2){
                int pNr;
                std::cout << "Enter personal number" << std::endl;
                std::cin >> pNr;
                work_product = GetWorkProduct();
                customer_data = GetCustomerInfo(pNr);
            }
        }
    }