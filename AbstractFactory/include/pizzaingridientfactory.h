#ifndef PIZZAINGRIDIENTFACTORY_H
#define PIZZAINGRIDIENTFACTORY_H

#include <memory>
#include <pizzaa.h>
#include <string>
using std::unique_ptr;
using std::string;
using std::make_unique;

class Clam{

};

class NYClam:public Clam{

};


class Pepperoni{

};

class NYPepperoni:public Pepperoni{

};

class Cheese{

};

class NYCheese:public Cheese{

};


class PizzaIngridientFactory
{
public:
    virtual Clam createClam() { return Clam();}
    virtual Pepperoni createPepperoni() { return Pepperoni();}
    virtual Cheese createCheese() { return Cheese();}
    virtual ~PizzaIngridientFactory() = default;
};

class NYPizzaIngridientFactory:public PizzaIngridientFactory
{
public:
    Clam createClam() override { return NYClam();}
    Pepperoni createPepperoni()  override {return NYPepperoni();}
    Cheese createCheese() override {return NYCheese();}
};






#endif // PIZZAINGRIDIENTFACTORY_H
