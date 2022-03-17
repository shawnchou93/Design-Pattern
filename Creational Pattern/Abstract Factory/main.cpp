#include "AbstractFactory.h"
#include "AbstractProduction.h"

using namespace std;

void test01()
{
    AbstractFactory* factoryA = new FactoryA();
    AbstractPaintColor* paintA = new PaintColor();
    AbstractDrawType* drawA = new DrawType();
    paintA->paintBlack();
    drawA->drawCircle();

    delete factoryA;
    delete paintA;
    delete drawA;


    AbstractFactory* factoryB = new FactoryB();
    AbstractPaintColor* paintB = new PaintColor();
    AbstractDrawType* drawB = new DrawType();

    delete factoryB;
    delete paintB;
    delete drawB;
}

int main()
{
    test01();

    return 0;
}