#ifndef __STORE_H
#define __STORE_H

#include "product.h"
#include "donut.h"
#include "java.h"

class Store
{
  public:
    Store(std::string name);
    std::string name();
    void add_product(Product* product);
    int number_of_products();
    std::string product_to_string(int product);
  private:
    std::string _name;
    std::vector <Product *> _products;
};

#endif
