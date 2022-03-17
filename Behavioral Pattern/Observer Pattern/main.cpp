#include "ObserverPattern.h"

int main(void)
{
    ConcreteObject* obj = new ConcreteObject();
    AbstractObserver* obs1 = new ConcreteObserver();
    AbstractObserver* obs2 = new ConcreteObserver();

    cout << obj->getObserverNum() << endl;
    obj->registerObserver(obs1);
    obj->registerObserver(obs2);
    cout << obj->getObserverNum() << endl;
    obj->notify();

    obj->unregisterObserver(obs1);
    cout << obj->getObserverNum() << endl;
    obj->notify();

    return 0;
}