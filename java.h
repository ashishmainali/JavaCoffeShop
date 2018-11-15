#ifndef __JAVA_H
#define __JAVA_H
#include <iostream>
#include <vector>
#include <exception>
#include "product.h"
enum Shot {NONE, CHOCOLATE, VANILLA,PEPPERMINT, HAZELNUT, IRISHCREME};

class Java: public Product
{
	public:
		Java(std::string name,double price,double cost, int darkness);
		void add_shot(Shot shot);
		std::string to_string();
	protected:
		int _darkness;
		std::vector <Shot> _shots;
};


#endif
