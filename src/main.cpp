#include <QCoreApplication>
#include <iostream>

#include "simplepizzafactory.h"

using namespace std;


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

        return pizza;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "hello: " << std::endl;


    return a.exec();
}
