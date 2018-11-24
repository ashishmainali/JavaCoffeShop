#ifndef __STORE_H
#define __STORE_H

#include "donut.h"
#include "java.h"
#include "product.h"
#include "customer.h"
#include "order.h"
#include <map>
#include <iterator>

class Store
{
  public:
  	Store(std::string name);
    Store();
   
    std::string name();
    void add_product(Product* product);
    int number_of_products();
    Product* get_product(int product);
    std::string product_to_string(int product);
    void add_customer(Customer* customer);
    int number_of_customers();
    std::string customer_to_string(int customer);
    int place_order(Order order,int customer);
    int number_of_orders();
    std::string order_to_string(int order_number);

    double pay_order (int order_number);
    bool order_is_paid(int order_number);
    void discard_order(int order_number);
    bool order_is_discarded(int order_number);
    void fill_order(int order_number);
    bool order_is_filled(int order_number);
    bool order_is_completed(int order_number);
    bool order_is_pending(int order_number);
    double get_cash();

    void save(std::ostream& ost); 
    void load (std::istream& ist);
    int last_order();
    void free_products();
    

    
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::map<Order, Customer> _orders;
    auto& find_order_pair(int order_number);
    static double _cash;
};

#endif
