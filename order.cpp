#include "order.h"

Order::Order()
{
    static int _next_order_number = 1;
   _order_number = _next_order_number++;
   _is_paid = false;
   _is_discarded =false;
   _is_filled = false;
}


Order::Order(const Order& obj)
{
  static int _next_order_number = 1;
   _order_number = obj._order_number;
   _next_order_number= obj.order_number()+1;
   _is_paid = obj._is_paid;
   _is_discarded =obj._is_discarded;
   _is_filled = obj._is_filled;
   for ( int i = 0; i < obj._products.size();i++)
   {
    _products.push_back(obj._products[i]);
   }
}

int Order::order_number() const
{
  return _order_number;
}
void Order::add_product(Product* product)
{
  _products.push_back(product);
}
bool Order::paid()
{
  return _is_paid;
}
void Order::pay()
{
  if( _is_paid == false && _is_discarded == false)
  _is_paid = true;
  else
    throw std::runtime_error("Invalid Pay Operation");
}
bool Order::filled()
{
  return _is_filled;
}

void Order::fill()
{
  if ( !_is_filled && !_is_discarded)
  _is_filled = true;
  else
    throw std::runtime_error("Invalid Operation fill!!");
}

std::string Order::order_to_string()
{
  std::ostringstream strs;
  int i = 0;
  if (this->discarded())
    strs<<"(discarded): \n";
  else if(this->paid())
    strs<<"(paid): \n";
  else if(this->filled())
    strs<<"(filled): \n";
  else
    strs << "(unfilled): \n";
  while (i < _products.size())
  {
      strs <<"\t"<< std::to_string(i+1) << ". " << _products[i]->to_string()<<std::endl;
      i++;
  }
  return strs.str();
}

bool Order::operator< ( const Order& rhs) const
    {
        return(this->order_number()<rhs.order_number());
    }
 
 void Order::discard()
 {
  if (!_is_discarded  && !(this->completed()))
  {
    _is_discarded = true;
  }
  else
    throw std::runtime_error("Invalid Discard Operation");
 }
    bool Order::discarded()
    {
      return _is_discarded;
    }
    bool Order::pending()
    {
      return (!_is_filled && !_is_paid && !_is_discarded);
    }
    bool Order::completed()
    {
      return (_is_filled && _is_paid && !_is_discarded);
    }
    double Order::profit ()
    {
      double profit =0;
      for (int i = 0 ; i < _products.size();i++)
      {
        profit += _products[i]->profit();
      }
      return profit;
    }