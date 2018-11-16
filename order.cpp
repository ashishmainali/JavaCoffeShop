#include "order.h"
Order::Order():_next_order_number{order_number+1}{}
int Order::order_number()
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
