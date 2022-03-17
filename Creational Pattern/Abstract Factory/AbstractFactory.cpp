#include "AbstractFactory.h"

AbstractPaintColor* FactoryA::productPaint()
{
    AbstractPaintColor* temp = NULL;
    temp = new PaintColor();
    return temp;
}

AbstractDrawType* FactoryA::pruductDraw()
{
    AbstractDrawType* temp = NULL;
    temp = new DrawType();
    return temp;
}

AbstractPaintColor* FactoryB::productPaint()
{
    AbstractPaintColor* temp = NULL;
    temp = new PaintColor();
    return temp;
}

AbstractDrawType* FactoryB::pruductDraw()
{
    AbstractDrawType* temp = NULL;
    temp = new DrawType();
    return temp;
}

