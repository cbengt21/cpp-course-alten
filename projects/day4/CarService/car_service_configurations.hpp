#ifndef CAR_SERVICE_configurations_HPP_
#define CAR_SERVICE_configurations_HPP_
#include <iostream>

namespace types{
    typedef struct CustomerInfo{
        std::string name;
        int personal_number=0;
        int date=0;
    } customerInfo_t;

    typedef struct WorkProduct{
        bool oilChange = false;
        enum class ServiceType service_type {kBigService, kSmallService, kNoService};
        enum class PaymentMethod {kNotKnown, kCash, kCard, kSwish, kCrypto};
    } workProduct_t;

    
}




#endif  //car_service_configurations.hpp