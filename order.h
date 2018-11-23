#ifndef __ORDER_H
#define __ORDER_H
#include "product.h"
#include "java.h"
#include "donut.h"
#include <vector>
class Order
{
  public:
    Order();
    Order(const Order& obj);
    int order_number() const;
    void add_product (Product* product);
    bool paid();
    void pay();
    bool filled();
    void fill();
    std::string order_to_string();
    bool operator< (const Order& rhs)const;
    void discard();
    bool discarded();
    bool pending();
    bool completed();
    double profit();



  protected:
    std::vector<Product*> _products;
  private:
    static int _next_order_number;
    int _order_number;
    bool _is_paid;
    bool _is_filled;
    bool _is_discarded;

};
#endif
