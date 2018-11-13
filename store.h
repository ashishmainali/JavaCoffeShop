#ifndef __STORE_H
#define __STORE_H

#include "donut.h"
#include "java.h"
#include "product.h"
#include "customer.h"
class Store
{
  public:
  	Store(std::string name);
    Store();
    void free_products();
    std::string name();
    void add_product(Product* product);
    int number_of_products();
    std::string product_to_string(int product);
    void add_customer(Customer* customer);
    int number_of_customers();
    std::string customer_to_string( int customer);
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
};

#endif
