#include "AdapterPattern.h"

int main(void)
{
    Adaptee* adaptee = new Adaptee();

    // 类适配
    Target* aa = new AdapterA();
    aa->request();

    // 对象适配
    Target* bb = new AdapterB(adaptee);
    bb->request();

    return 0;
}