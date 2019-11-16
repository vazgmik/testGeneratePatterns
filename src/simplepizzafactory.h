#ifndef SIMPLEPIZZAFACTORY_H
#define SIMPLEPIZZAFACTORY_H

#include <memory>
#include <pizza.h>
#include <string>
using std::unique_ptr;
using std::string;

class SimplePizzaFactory
{
public:
    static unique_ptr<Pizza> createPizza(string type);
};

#endif // SIMPLEPIZZAFACTORY_H
