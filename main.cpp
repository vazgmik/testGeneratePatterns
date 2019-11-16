#include <QCoreApplication>
#include <iostream>



//#define SIMPLE_FACTORY  0
#define FACTORY_METHOD  1
using namespace std;


#ifdef SIMPLE_FACTORY
#include "simplepizzafactory.h"
class PizzaStore {
private:
SimplePizzaFactory::Factory factory;
public:
    PizzaStore()
    {
    }

    PizzaStore(SimplePizzaFactory::Factory fact)
    {
        factory = fact;
    }

    unique_ptr<Pizza> orderPizza(string type)
    {
        //or factory.createPizza(type);
        auto pizza = SimplePizzaFactory::createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};
#endif

#ifdef FACTORY_METHOD
#include "pizza.h"

class PizzaStore {
public:
    unique_ptr<Pizza> orderPizza(string type)
    {
        auto pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    virtual unique_ptr<Pizza> createPizza(string type) = 0;
    virtual ~PizzaStore() = default;
};


class NYPizzaStore: public PizzaStore {
public:
    unique_ptr<Pizza> createPizza(string type) override
    {
        if(type == "cheese")
            return make_unique<NYStyleCheesePizza>();
        else if(type == "pepperoni")
            return make_unique<NYStylePepperoniPizza>();
        else if(type == "clam")
            return make_unique<NYStyleClamPizza>();
        return nullptr;
    }
};
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef SIMPLE_FACTORY
    cout << "SIMPLE_FACTORY\n";

    PizzaStore store;
    store.orderPizza("pepperoni");

    SimplePizzaFactory::Factory factory;
    PizzaStore storeDynamic(factory);
    storeDynamic.orderPizza("pepperoni");

    //e.g we can create different factories
    //SimplePizzaFactory::FactoryNY NYfactory;
    //PizzaStore NYStore(NYfactory);
    //NYStore.orderPizza("pepperoni");

    //SimplePizzaFactory::FactoryChicago Chicagofactory;
    //PizzaStore ChicagoStore(Chicagofactory);
    //ChicagoStore.orderPizza("pepperoni");
#endif

#ifdef FACTORY_METHOD
    cout << "FACTORY_METHOD\n";

    NYPizzaStore nystore;
    auto nypizza = nystore.orderPizza("pepperoni");

    //ChicagoPizzaStore chicagostore;
    //auto chpizza = chicagostore.orderPizza("pepperoni");
#endif

    return a.exec();
}
