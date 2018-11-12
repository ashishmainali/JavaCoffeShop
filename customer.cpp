#include "Customer.h"

Customer::Customer(std::string Customer, std::string Customer_phone)
    : _Customer{Customer}, _Customer_phone{Customer_phone} { }
Customer::Customer() : Customer("", "") { }

Customer::Customer(std::istream& ist) {
    std::getline(ist, _Customer);
    std::getline(ist, _Customer_phone);
}
void Customer::save(std::ostream& ost) {
    ost << _Customer << std::endl;
    ost << _Customer_phone << std::endl;
}

std::string Customer::to_string() const {
    return _Customer + ", " + _Customer_phone;
}

std::ostream& operator<<(std::ostream& ost, const Customer& Customer) {
    ost << Customer.to_string();
    return ost;
}
