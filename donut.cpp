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
  		strs<< " and sprinkles.";

  	//checking frostings here
  	if (_frosting== Frosting::CHOCOLATE_TOP)
  		strs<<"(Chocolate topping)";
  	else if (_frosting == Frosting::VANILLA_TOP)
  		strs<<"(Vanilla topping)";

  	else
  		strs<< "(Pink topping)";

  std::string str = strs.str() ;
  return str;
}

void Donut::save(std::ostream& ost)
{
  ost<< "##DONUT##" <<std::endl;
  ost << _name <<std::endl;
  ost << _price <<std::endl;
  ost << _cost <<std::endl;
  ost << (int)_filling <<std::endl;
  ost << (int) _frosting <<std::endl;
  ost << _sprinkles <<std::endl;
}

Donut::Donut(std::istream& ist):Product()
{
    double temp;
    std::getline(ist, _name);
    
    ist >> temp; ist.ignore();
    _price = temp;
   
    ist >> temp; ist.ignore();
    _cost = temp;
   
    ist >> temp; ist.ignore();
    _filling = (Filling)temp;
   
    ist >> temp; ist.ignore();
    _frosting = (Frosting)temp;
   
    ist >> temp; ist.ignore();
    _sprinkles = (temp != 0);
   

}
