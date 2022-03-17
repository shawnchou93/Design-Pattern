#include "AbstractProduction.h"

void squire()
{
    // concrete implemention to draw squire
}

void circle()
{
    // concrete implemention to draw circle
}

void black()
{
    // draw black
}

void red()
{
    // draw red
}

void green()
{
    // draw green
}

void PaintColor::paintBlack()
{
    black();
}

void PaintColor::paintRed()
{
    red();
}

void PaintColor::paintGreen()
{
    green();
}

void DrawType::drawCircle()
{
    circle();
}

void DrawType::drawSquire()
{
    squire();
}

