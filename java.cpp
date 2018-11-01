#include "java.h"
#include "product.h"

Java::Java(std::string name,double price,double cost, int darkness): _name{name}, _price{price},_cost{cost},_darkness{darkness}{}
void Java::add_shot(Shot shot)
{
	_shots.push_back(shot);
}
Java::to_string()
{
	std::ostringstream strs;
  strs << _name<< " "<< _price << " " << _cost;
  std::string str = strs.str() ;
  return str;
}
