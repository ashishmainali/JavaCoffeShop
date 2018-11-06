#include "product.h"

int main() {
  Product a("coffee",1.0,0.5);
  std::cout << a.to_string() << '\n';
  return 0;
}
