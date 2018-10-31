#ifndef __JAVA_H
#define __JAVA_H
#include <iostream>
#include <vector>
enum Shot {None, Choclate, Vanilla, Peppermint, Hazelnut }

class Java: public product
{
	public:
		Java(std::string name,double price,double,double cost, int darkness);
		void add_shot(Shot shot);
	protected:
		int _darkness;
		std::vector <Shot> _shots;


};
#endif
