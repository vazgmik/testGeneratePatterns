#ifndef PIZZAA_H
#define PIZZAA_H

#include "pizzaingridientfactory.h"

class PizzaA
{
public:
    PizzaA();
    virtual void prepare() = 0;
    void bake();
    void cut();
    void box();

    virtual ~PizzaA() = default;
};

class CheesePizzaA: public PizzaA
{
private:
    Cheese cheese;
    PizzaIngridientFactory ingFac;
public:
    CheesePizzaA(PizzaIngridientFactory f);
    void prepare() override;

};

class PepperoniPizzaA: public PizzaA
{
private:
    PizzaIngridientFactory ingFac;
    Pepperoni pep;
public:
    PepperoniPizzaA(PizzaIngridientFactory f);
    void prepare() override;

};

class ClamPizzaA: public PizzaA
{
private:
    Clam clam;
    PizzaIngridientFactory ingFac;
public:
    ClamPizzaA(PizzaIngridientFactory f);
    void prepare() override;
};


class NYStyleCheesePizza: public PizzaA
{

};

class NYStylePepperoniPizza: public PizzaA
{

};

class NYStyleClamPizza: public PizzaA
{

};
#endif // PIZZAA_H
