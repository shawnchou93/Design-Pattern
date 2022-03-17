#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <iostream>
#include "AbstractProduction.h"

using namespace std;

class AbstractFactory
{
public:
    AbstractFactory();
    ~AbstractFactory();

    virtual AbstractPaintColor* productPaint() = 0;
    virtual AbstractDrawType* pruductDraw() = 0;
};

class FactoryA: public AbstractFactory
{
public:
    FactoryA();
    ~FactoryA();

    virtual AbstractPaintColor* productPaint();
    virtual AbstractDrawType* pruductDraw();

};

class FactoryB: public AbstractFactory
{
public:
    FactoryB();
    ~FactoryB();

    virtual AbstractPaintColor* productPaint();
    virtual AbstractDrawType* pruductDraw();

};


#endif //_SIMPLEFACTORY_H_

