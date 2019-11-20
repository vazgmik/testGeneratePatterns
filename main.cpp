#include <QCoreApplication>
#include <iostream>


//#define DEPENDENT_FACTORY  -1
//#define SIMPLE_FACTORY  0
#define FACTORY_METHOD  1
//#define ABSTRACT_FACTORY  2
using namespace std;

#ifdef DEPENDENT_FACTORY
#include "pizza.h"
class DependentPizzaStore {
public:
    DependentPizzaStore()
    {
    }

    unique_ptr<Pizza> orderPizza(string type)
    {
        unique_ptr<Pizza> pizza;

        if(type == "cheese")
            pizza =  make_unique<CheesePizza>();
        else if(type == "pepperoni")
            pizza =  make_unique<PepperoniPizza>();
        else if(type == "clam")
            pizza = make_unique<ClamPizza>();

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};
#elif SIMPLE_FACTORY
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
#elif FACTORY_METHOD
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
    virtual ~PizzaStore() = default;
protected:
    virtual unique_ptr<Pizza> createPizza(string type) = 0;

};


class NYPizzaStore: public PizzaStore {
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
#elif ABSTRACT_FACTORY
#include "pizzaa.h"
class PizzaStore {
public:
    unique_ptr<PizzaA> orderPizza(string type)
    {
        auto pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    virtual unique_ptr<PizzaA> createPizza(string type) = 0;
    virtual ~PizzaStore() = default;
};


class NYPizzaStore: public PizzaStore {
public:
    unique_ptr<PizzaA> createPizza(string type) override
    {
        PizzaIngridientFactory factory = NYPizzaIngridientFactory();
        if(type == "cheese")
            return make_unique<CheesePizzaA>(factory);
        else if(type == "pepperoni")
            return make_unique<PepperoniPizzaA>(factory);
        else if(type == "clam")
            return make_unique<ClamPizzaA>(factory);
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
#elif FACTORY_METHOD
    cout << "FACTORY_METHOD\n";

    NYPizzaStore nystore;
    auto nypizza = nystore.orderPizza("pepperoni");

    //ChicagoPizzaStore chicagostore;
    //auto chpizza = chicagostore.orderPizza("pepperoni");

#elif ABSTRACT_FACTORY
    NYPizzaStore store;
    store.orderPizza("cheese");
#endif

    return a.exec();
}
