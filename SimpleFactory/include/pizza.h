#ifndef PIZZA_H
#define PIZZA_H


class Pizza
{
public:
    Pizza();
    void prepare();
    void bake();
    void cut();
    void box();

};

class CheesePizza: public Pizza
{

};

class PepperoniPizza: public Pizza
{

};

class ClamPizza: public Pizza
{

};
#endif // PIZZA_H
