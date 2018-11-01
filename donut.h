#include "product.h"
enum Frosting { Unfrosted,Choclate_top,Vanilla_top,Pink_top};
enum Filling {Unfilled,Creme,Bavarian,Strawberry};

class Donut: public Product
{
  public:
    Donut(std::string name,double price,double cost, Frosting frosting, bool sprinkles, Filling filling);
  protected:
    Frosting _frosting;
    Filling _filling;
    bool _sprinkles;
}
