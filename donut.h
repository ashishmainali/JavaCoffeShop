#ifndef __DONUT_H
#define __DONUT_H
#include "product.h"
enum Frosting {UNFROSTED,CHOCOLATE_TOP,VANILLA_TOP,PINK_TOP};

enum Filling {UNFILLED,CREME,BAVARIAN,STRAWBERRY};

class Donut: public Product
{
  public:
    Donut(std::string name,double price,double cost, Frosting frosting, bool sprinkles, Filling filling);
    std::string to_string();
    void save(std::ostream& ost);
    Donut(std::istream& ist);
  protected:
    Frosting _frosting;
    Filling _filling;
    bool _sprinkles;
};

#endif
