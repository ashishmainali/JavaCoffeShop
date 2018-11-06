#include "donut.h"

Donut::Donut(std::string name,double price,double cost, Frosting frosting, bool sprinkles, Filling filling):Product(name,price,cost){
_frosting=frosting;
_sprinkles=sprinkles;
_filling=filling;
}

std::string Donut::to_string()
{
  std::ostringstream strs;
  strs << _name << " ( "<< _price << " / " << _cost << " ) Filled with ";
  if (_filling==Filling::CREME)
  	strs<<"Creme";
  else if (_filling==Filling::BAVARIAN)
  	strs<<"Bavarian";
  	else
  		strs<<"Strawberry";
  	//checking sprinkles 
  	if (_sprinkles)
  		strs<< "and sprinkles.";
  	
  	//checking frostings here
  	if (_frosting==Frosting::CHOCLATE_TOP)
  		strs<<"(Choclate topping)";
  	else if (_frosting == Frosting::VANILLA_TOP)
  		strs<<"(Vanilla topping)";
  	
  	else
  		strs<< "(Pink topping)";
  	
  std::string str = strs.str() ;
  return str;
}
