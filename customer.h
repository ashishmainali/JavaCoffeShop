#ifndef __Customer_H
#define __Customer_H
#include <string>
#include <ostream>
#include <istream>

class Customer {
  public:
    Customer(std::string Customer, std::string Customer_phone);
    Customer();
    Customer(std::istream& ist);
    void save(std::ostream& ost);
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Customer& Customer);
  private:
    std::string _Customer;
    std::string _Customer_phone;
};
#endif
