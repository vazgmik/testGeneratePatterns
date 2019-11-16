#ifndef SIMPLEPIZZAFACTORY_H
#define SIMPLEPIZZAFACTORY_H

#include <memory>
#include <pizza.h>
#include <string>
using std::unique_ptr;
using std::string;
using std::make_unique;
namespace  SimplePizzaFactory {
    static unique_ptr<Pizza> createPizza(string type)
    {
        if(type == "cheese")
            return make_unique<CheesePizza>();
        else if(type == "pepperoni")
            return make_unique<PepperoniPizza>();
        else if(type == "clam")
            return make_unique<ClamPizza>();

        return nullptr;
    }
}


#endif // SIMPLEPIZZAFACTORY_H
