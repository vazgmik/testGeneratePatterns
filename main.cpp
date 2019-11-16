#include <QCoreApplication>
#include <iostream>



#define SIMPLE_FACTORY  0
using namespace std;


#ifdef SIMPLE_FACTORY
#include "simplepizzafactory.h"
class PizzaStore {

private:

public:
    PizzaStore()
    {
    }

    unique_ptr<Pizza> orderPizza(string type)
    {
        auto pizza = SimplePizzaFactory::createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef SIMPLE_FACTORY
    cout << "SIMPLE_FACTORY\n";

    PizzaStore store;
    store.orderPizza("peperroni");
#endif
    return a.exec();
}
