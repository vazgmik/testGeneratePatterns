#include "pizzaa.h"

#include <iostream>

using std::cout;
PizzaA::PizzaA()
{

}

void PizzaA::bake()
{
    cout << "bake\n";

}

void PizzaA::cut()
{
    cout << "cut\n";

}

void PizzaA::box()
{
    cout << "box\n";

}

CheesePizzaA::CheesePizzaA(PizzaIngridientFactory f)
{
    ingFac = f;
}

void CheesePizzaA::prepare()
{
    cheese = ingFac.createCheese();
}

PepperoniPizzaA::PepperoniPizzaA(PizzaIngridientFactory f)
{
    ingFac = f;
}

void PepperoniPizzaA::prepare()
{
    pep = ingFac.createPepperoni();
}

ClamPizzaA::ClamPizzaA(PizzaIngridientFactory f)
{
    ingFac = f;
}

void ClamPizzaA::prepare()
{
    clam = ingFac.createClam();
}
