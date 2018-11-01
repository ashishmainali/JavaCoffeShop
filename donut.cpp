#include "donut.h"

Donut::Donut(std::string name,double price,double cost, Frosting frosting, bool sprinkles, Filling filling):_name{name},_price{price},_cost{cost},_frosting{frosting},_sprinkles{sprinkles},_filling{filling}{}
Donut::to_string()
{
  std::ostringstream strs;
  strs << _name<< " "<< _price << " " << _cost;
  std::string str = strs.str() ;
  return str;
}
