
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: main



debug: CXXFLAGS += -g
debug: default
main: main.o mainwin.o donut.o product.o store.o java.o customer.o dialogs.o order.o mainfun.o
	${CXX} ${CXXFLAGS} -o main java.o product.o store.o main.o customer.o mainwin.o donut.o mainfun.o dialogs.o order.o ${GTKFLAGS}
order.o: order.cpp *.h
	${CXX} ${CXXFLAGS} -c order.cpp
main.o : main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp ${GTKFLAGS}
mainwin.o: mainwin.cpp *.h
	${CXX} ${CXXFLAGS} -c mainwin.cpp  ${GTKFLAGS}
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp
customer.o : customer.cpp *.h
	${CXX} ${CXXFLAGS} -c customer.cpp
	###testing area
reg_donut: reg_donut.o donut.o product.o *h
	${CXX} ${CXXFLAGS} -o reg_donut reg_donut.o donut.o product.o
reg_java: reg_java.o java.o product.o *h
	${CXX} ${CXXFLAGS} -o reg_java reg_java.o java.o product.o
reg_product: reg_product.o product.o *h
	${CXX} ${CXXFLAGS} -o reg_product reg_product.o product.o
reg_donut.o : reg_donut.cpp *.h
	${CXX} ${CXXFLAGS} -c reg_donut.cpp
reg_java.o : reg_java.cpp *.h
	${CXX} ${CXXFLAGS} -c reg_java.cpp
reg_product.o: reg_product.cpp *.h
	${CXX} ${CXXFLAGS} -c reg_product.cpp
dialogs.o: dialogs.cpp *h
	${CXX} ${CXXFLAGS} -c dialogs.cpp ${GTKFLAGS}
mainfun.o: mainfun.cpp *h
	${CXX} ${CXXFLAGS} -c mainfun.cpp ${GTKFLAGS}


clean:
	-rm -f *.gch *.o reg_product.o reg_product product.o donut.o reg_donut.o reg_java.o reg_java reg_donut store.o java.o main.o main
