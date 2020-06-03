#include "product.h"

Product::Product(std::string name, double price , double cost):_name{name},_price{price},_cost{cost}{}
std::string Product::name()
{
  return _name;
}
Product::Product(){}
std::string Product::to_string()
{
  std::ostringstream strs;
  strs << _name<< " "<< _price << " " << _cost;
  std::string str = strs.str() ;
  return str;
}
double Product::profit()
{
	return(_price - _cost);
}

void Product::save(std::ostream& ost)
{

}
