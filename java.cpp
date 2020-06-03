#include "java.h"
#include "product.h"


class myexception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Invalid darkness!!!";
  }
} myex;

	Java::Java(std::string name,double price,double cost, int darkness):Product(name,price,cost)
{
	_darkness= darkness;
}
void Java::add_shot(Shot shot)
{
	_shots.push_back(shot);
}
std::string Java::to_string()
{
	std::ostringstream strs;
  strs << _name<< " ("<< _price << " /" << _cost<< ")";
  switch (_darkness)
  {
  	case 1: strs << " Blonde"; break;
  	case 2: strs << " Light";break;
  	case 3: strs << " Medium";break;
  	case 4: strs << " Dark";break;
  	case 5: strs << " Extra Dark";break;
  	default: throw myex;
  }



  for (int i = 0 ; i < _shots.size(); i ++)
  {
  	Shot tempShot = _shots[i];

  	if (tempShot == Shot::CHOCOLATE)
  		strs << "(Chocolate)";
  	else if(tempShot == Shot::VANILLA)
  		strs <<"(Vanilla)";
  	else if(tempShot == Shot::HAZELNUT)
  		strs <<"(Hazelnut)";
    else if (tempShot == Shot::IRISHCREME)
      strs << "(Irish crème)";
  	else
  		strs << "(Peppermint)";

  	if ( i < _shots.size()-1)
  	strs << ", ";
  }

  std::string str = strs.str() ;
  return str;
}


void Java::save(std::ostream& ost)
{
  ost<< "##JAVA##"<<std::endl;
  ost << _name << std::endl;
  ost << _price << std::endl;
  ost << _cost << std::endl;
  ost << _darkness << std::endl;
  ost << _shots.size() << std::endl;
  for ( auto s : _shots)
    ost << (int)s << std::endl;
}

Java::Java(std::istream& ist):Product()
{
  double temp;
  int ss,i = 0;
    std::getline(ist, _name); 
    ist >> temp; ist.ignore();
    _price = temp;
    ist >> temp; ist.ignore();
    _cost = temp;
    
    ist >> temp; ist.ignore();
    _darkness = temp;
   
    ist >> ss; ist.ignore();
    while (i <ss )
    {
      ist >> temp; ist.ignore();
      _shots.push_back((Shot)temp);
      i++;
    }
   
}