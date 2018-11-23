#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>
#include <string>
#include <ostream>
#include <istream>
#include <sstream>


class Product
{
  public:
    Product(std::string name, double price , double cost);
    Product();
    std::string name();
    double profit();
    virtual std::string to_string();
    virtual void save(std::ostream& ost);

  protected:
    std::string _name;
    double _price;
    double _cost;
};



#endif
