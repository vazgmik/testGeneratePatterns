#include "simplepizzafactory.h"

unique_ptr<Pizza> createPizza(string type)
{
    if(type == "cheese")
        return make_unique<CheesePizza>();
    else if(type == "pepperoni")
        return make_unique<PepperoniPizza>();
    else if(type == "clam")
        return make_unique<ClamPizza>();

    return nullptr;
}

