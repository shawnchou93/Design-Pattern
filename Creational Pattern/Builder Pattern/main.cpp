#include "BuilderPattern.h"

int main(void)
{
    AbstractBuilder* pBuilder = new ConcreteBuilder();
    Director* pDirector = new Director();

    pDirector->setBuilder(pBuilder);
    pDirector->buildProcess();

    return 0;
}