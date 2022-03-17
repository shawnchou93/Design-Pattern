#include <iostream>

using namespace std;

class AbstractPaintColor
{
public:
    AbstractPaintColor();
    ~AbstractPaintColor();

    virtual void paintBlack() = 0;
    virtual void paintRed() = 0;
    virtual void paintGreen() = 0;
};

class AbstractDrawType
{
public:
    AbstractDrawType();
    ~AbstractDrawType();

    virtual void drawCircle() = 0;
    virtual void drawSquire() = 0;
};

class PaintColor: public AbstractPaintColor
{
public:
    PaintColor();
    ~PaintColor();

    virtual void paintBlack();
    virtual void paintRed();
    virtual void paintGreen();
};

class DrawType: public AbstractDrawType
{
public:
    DrawType();
    ~DrawType();

    virtual void drawCircle();
    virtual void drawSquire();
};


