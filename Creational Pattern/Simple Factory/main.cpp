#include "SimpleFactory.h"

int main(void)
{
    ConcreteFactory* factoryPtr = new ConcreteFactory();

    AbstractProduction* productionPtr = factoryPtr->getProcInstance(ENUM_PRODUCTION_C);

    productionPtr->action1();
    productionPtr->action2();

    return 0;
}
