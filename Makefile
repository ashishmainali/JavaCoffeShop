
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: main



debug: CXXFLAGS += -g
debug: default
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
reg_product: reg_product.o product.o *h
	${CXX} ${CXXFLAGS} -o reg_product reg_product.o product.o
reg_product.o: reg_product.cpp *.h
	${CXX} ${CXXFLAGS} -c reg_product.cpp

clean:
	-rm -f *.gch *.o reg_product.o reg_product product.o donut.o
