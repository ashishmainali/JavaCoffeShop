#include "java.h"

int main() {

try
{
  Java j("Frappe",10,5,3);
  j.add_shot(Shot::CHOCLATE);
  j.add_shot (Shot::PEPPERMINT);
  std::cout << j.to_string() << '\n';
}
catch(std::exception& e)
{
	std::cerr<< e.what();
  return 0;
}

try
{
  Java k("Frappe",10,5,8);
  k.add_shot(Shot::NONE);
  k.add_shot (Shot::PEPPERMINT);
  std::cout << k.to_string() << '\n';
}
catch(std::exception& e)
{
	std::cerr<< e.what();
  return 0;
}


}
