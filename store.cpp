  #include "store.h"

  Store::Store(std::string name):_name{name}
  {
    _cash = 0;
  }
  Store::Store()
  {
    _cash = 0 ;
  };
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
     _orders.insert ( std::pair<Order,Customer>(order,*(_customers[customer])) );
    //_orders[order]= *(_customers[customer]); //alternate method
    return order.order_number();
  }

  int Store::number_of_orders()
  {
    return _orders.size();
  }


  std::string Store::order_to_string(int order_number)
  {
    std::ostringstream strs;
    strs << "Order Number # " << order_number;
    bool order_not_found = true;
    for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
          {
            Order temp_order = it->first;
            if(temp_order.order_number()==order_number)
            {
              strs<<temp_order.order_to_string();
              Customer temp_customer = it->second;
              strs << temp_customer.to_string()<<std::endl;
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
      int i ,j;
      ost<<_products.size()<<std::endl;
      for (auto p : _products) 
      {
          p->save(ost);
      }
      ost <<_customers.size()<<std::endl;
      for (auto c : _customers)
          c->save(ost);
        ost<<"##ORDER##"<<std::endl;
         ost <<_orders.size()<<std::endl;
        for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
          { 
            Order o(it ->first);
            o.save(ost);      
            ost << it->second.to_string()<<std::endl;
          }
  }


  void Store::load (std::istream& ist)
  {

    int product_size,customer_size , i ,j, temp;
    std::string product_text;
    ist >> product_size ; ist.ignore();
    for ( i = 0 ; i <product_size; ++i)
    {
      std::getline(ist,product_text);
      if (product_text == "##JAVA##")
        {
                  Java *temp_product = new Java(ist);
                  _products.push_back(temp_product);
        }  
      else
      {
          Donut *temp_product = new Donut(ist);
          _products.push_back(temp_product);
      }

    }
    ist  >> customer_size; ist.ignore();
    for ( i = 0 ; i < customer_size; i++)
    {
      Customer *temp_customer = new Customer(ist);
      _customers.push_back(temp_customer);
    }
    std::string garbage;
    int order_size;
    std::getline(ist,garbage);
    ist>> order_size;ist.ignore();
    for (i = 0 ; i < order_size;i++)
    {
      Order *o = new Order();
      ist>>product_size;ist.ignore();
      for ( j = 0 ; j < product_size;j++)
      {
        std::string product_string;
        std::getline(ist,product_string);
        for ( int k = 0 ; k < _products.size(); k++)
        {
          if (_products[k]->to_string() == product_string)
            o->add_product(_products[k]);
        }
      }

          bool  d,f,p;
      ist>>d;ist.ignore();
      ist>>f;ist.ignore();
      ist>>p;ist.ignore();
      if ( d )
        o->discard();
      if (f)
        o->fill();
      std::string customer_string;
      std::getline(ist,customer_string);
      int customerid ;
      for (j= 0 ; j <_customers.size(); j++)
            {
              std::string compare_string = _customers[j]->to_string();
              if (!(customer_string.compare(compare_string)))
                  customerid = j;
            }
      
      this->place_order(*o,customerid);
      
      if (p)
       this->pay_order(o->order_number()); 
      

    }

  }

  int Store::last_order()
  {
   
    return _orders.size()+1;
  }


  auto& Store::find_order_pair(int order_number)
  {
    for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
    {
      if (it->first.order_number() == order_number)
          return it->first;
    }  

  }

void Store::pay_order (int order_number)
  {
   
    
    for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
      {
        
        if (it->first.order_number() == order_number)
            {
              
              Order temp_order(it->first);
              Customer temp_customer = it->second;
              temp_order.pay();
              _orders.erase(it);
              _orders.insert ( std::pair<Order,Customer>(temp_order,temp_customer) );
              _cash += temp_order.profit();
            }
      }  
  }


  void Store::discard_order(int order_number)
  {
    for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
      {
        if (it->first.order_number() == order_number)
            {
              Order temp_order(it->first);
              Customer temp_customer = it->second;
              temp_order.discard();
              _orders.erase(it);
              _orders.insert ( std::pair<Order,Customer>(temp_order,temp_customer) );
              break;
            }
      }  
  }

  void Store::fill_order(int order_number)
  {
    for ( auto it = _orders.begin(); it != _orders.end(); ++it  )
      {
        if (it->first.order_number() == order_number)
            {
              Order temp_order(it->first);
              Customer temp_customer = it->second;
              temp_order.fill();
              _orders.erase(it);
              _orders.insert ( std::pair<Order,Customer>(temp_order,temp_customer) );
              break;
            }
      }  
  }


      bool Store::order_is_paid(int order_number)
      {
        auto temp = find_order_pair(order_number);
        return temp.paid();

      }
      
      bool Store::order_is_discarded(int order_number)
      {
        auto it = find_order_pair(order_number);
        return it.discarded();
      }
      
      bool Store::order_is_filled(int order_number)
      {
        auto it = find_order_pair(order_number);
        return it.filled();
      }
      bool Store::order_is_completed(int order_number)
      {
        auto it = find_order_pair(order_number);
        return it.completed();
      }
      bool Store::order_is_pending(int order_number)
      {
        auto it = find_order_pair(order_number);
        return it.pending();
      }

      double Store::get_cash()
      {
        return _cash;
      }