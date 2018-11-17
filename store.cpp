#include "store.h"

Store::Store(std::string name):_name{name}{}
Store::Store(){};
std::string Store::name()
{
  return _name;
}
void Store::add_product(Product* product)
{
  _products.push_back(product);
}
int Store::number_of_products()
{
  return _products.size();
}
std::string Store::product_to_string(int product)
{
  return _products[product] -> to_string();
}

void Store::free_products()
{
	for (int i = 0 ; i <_products.size();i++)
	{
		delete _products[i];
		_products.pop_back();
	}
}

void Store::add_customer(Customer *customer)
{
  _customers.push_back(customer);
}
int Store::number_of_customers()
{
  _customers.size();
}

std::string Store::customer_to_string( int customer)
{
  return _customers[customer] -> to_string();
}

int Store::place_order(Order order, int customer)
{
   //_orders.insert ( std::pair<Order,Customer>(order,_customers[customer]) );
  //_orders[order]= *(_customers[customer]);
  return order.order_number();
}

int Store::number_of_orders()
{
  return _orders.size();
}

std::string Store::order_to_string(int order_number)
{
  std::ostringstream strs;
  strs << "Order Number # " << order_number<<": \n";
  bool order_not_found = true;
  for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
        {
          Order temp_order = it->first;
          if(temp_order.order_number()==order_number)
          {
            strs<<temp_order.order_to_string();
            Customer *temp_customer = it->second;
            strs << temp_customer->to_string()<<std::endl;
            order_not_found = false;
          }
        }
    if (order_not_found)
    {
      strs<<"Order not Found !!!";
    }
    return strs.str();
}
Product* Store::get_product(int product)
{
  return _products[product];
}

void Store::save(std::ostream& ost) {
    for (auto p : _products) 
        p->save(ost);
    for (auto c : _customers)
        c->save(ost);
}

