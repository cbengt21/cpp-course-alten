#include "CarService.hpp"

Customer::Customer(){
}

void Customer::setCustomerInfo(const customerInfo_t& info){
    customerInfo.name = info.name;
    customerInfo.streetAdress = info.streetAdress;
    customerInfo.streetNr = info.streetNr;
    return;
}
customerInfo_t Customer::getCustomerInfo(){
    return customerInfo;
}
void Customer::setDate(const date_t& date){
    dateVisited.day = date.day;
    dateVisited.month = date.month;
    dateVisited.year = date.year;
    return;
}
date_t Customer::getDate(){
    return dateVisited;
}
void Customer::setPartsChanged(const parts_t &parts){
    partsChanged.airFilterChange = parts.airFilterChange;
    partsChanged.oilChange = parts.oilChange;
    return;
}
parts_t Customer::getPartsChanged(){
    return partsChanged;
}
void Customer::setServiceType(serviceType type){
    serviceT = type;
    return;
}
serviceType Customer::getServiceType(){
    return serviceT;
}    