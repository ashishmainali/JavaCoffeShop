#include "order.h"

Order::Order()
{
    static int _next_order_number = 1;
   _order_number = _next_order_number++;
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
  _is_paid = true;
}
bool Order::filled()
{
  return _is_filled;
}

void Order::fill()
{
  _is_filled = true;
}
std::string Order::order_to_string()
{
  std::ostringstream strs;
  int i = 0;
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
 