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
