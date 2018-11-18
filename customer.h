#ifndef __Customer_H
#define __Customer_H
#include <string>
#include <ostream>
#include <istream>

class Customer {
  public:
    Customer(std::string customer, std::string customer_phone);
    Customer();
    Customer(std::istream& ist);
    void save(std::ostream& ost);
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
  private:
    std::string _customer;
    std::string _customer_phone;
};
#endif
