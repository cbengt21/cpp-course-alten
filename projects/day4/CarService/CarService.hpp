#include <iostream>

typedef struct customerInfo{
    std::string name;
    std::string streetAdress;
    int streetNr=0;
} customerInfo_t;

typedef struct date{
    int day = 0;
    int month = 0;
    int year = 0;
} date_t;
        
typedef struct partsChanged{
    bool oilChange = false;
    bool airFilterChange = false;
} parts_t;

enum serviceType {bigService, smallService, noService};
enum paymentMethod {notKnown, cash, card, swish};

class Customer{
    private:
        
        customerInfo_t customerInfo;
        date_t dateVisited;
        parts_t partsChanged;
        serviceType serviceT = serviceType::noService;
        paymentMethod payMethod = paymentMethod::notKnown;

    public:
        Customer();
        void setCustomerInfo(const customerInfo_t& info);
        customerInfo_t getCustomerInfo();
        void setDate(const date_t& date);
        date_t getDate();
        void setPartsChanged(const parts_t &parts);
        parts_t getPartsChanged();
        void setServiceType(serviceType type); 
        serviceType getServiceType();
        
};