#include "singleton.h"

void func1(void)
{
    singletonClass t1 = singletonClass::getInstance();

}


int main()
{
    singletonClass t1 = singletonClass::getInstance();

    return 0;
}
