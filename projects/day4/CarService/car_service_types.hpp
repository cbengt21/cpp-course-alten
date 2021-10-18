#ifndef CAR_SERVICE_TYPES_HPP_
#define CAR_SERVICE_TYPES_HPP_
#include <iostream>

namespace types{
    typedef struct CustomerInfo{
        std::string name;
        int personal_number=0;
        int date=0;
    } customerInfo_t;

    typedef struct WorkProduct{
        bool oilChange = false;
        enum class ServiceType {kBigService, kSmallService, kNoService} service_type ;
        enum class PaymentMethod {kNotKnown, kCash, kCard, kSwish, kCrypto} payment_method;
    } workProduct_t;
}

#endif 