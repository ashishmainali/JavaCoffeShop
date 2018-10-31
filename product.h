#ifndef __PRODUCT_H
#define __PRODUCT_H
#inclue <iostream>

class Product
{
  public:
    Product(std::string name, double price , double cost);
    std::string name();
    std::string to_string();
  protected:
    std::string _name;
    double _price;
    double _cost;
};



#endif
