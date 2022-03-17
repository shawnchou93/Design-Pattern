#include "IteratorPattern.h"
#include "IteratorPattern2.h"

using namespace iteratorpattern1;
using namespace iteratorpattern2;

void func1(void)
{
    iteratorpattern1::tmpClass* tmp1 = new iteratorpattern1::tmpClass(1);
    iteratorpattern1::tmpClass* tmp2 = new iteratorpattern1::tmpClass(2);
    iteratorpattern1::tmpClass* tmp3 = new iteratorpattern1::tmpClass(3);
    iteratorpattern1::tmpClass* tmp4 = new iteratorpattern1::tmpClass(4);

    ConcreteAggregate* aggregatePtr = new ConcreteAggregate();
    aggregatePtr->push(tmp1);
    aggregatePtr->push(tmp2);
    aggregatePtr->push(tmp3);
    aggregatePtr->push(tmp4);

    AbstractIterator* iteratorPtr = aggregatePtr->createIterator();
    iteratorpattern1::tmpClass* tmp = iteratorPtr->getFirst();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getCurrent();
    tmp->action1();
    tmp->action2();

    bool isEnd = iteratorPtr->isEnd();
    cout << "isEnd = " << isEnd << endl;

    delete tmp1;
    delete tmp2;
    delete tmp3;
    delete tmp4;
    delete aggregatePtr;
    delete iteratorPtr;
    delete tmp;
}


void func2()
{
    iteratorpattern2::tmpClass* tmp1 = new iteratorpattern2::tmpClass(1);
    iteratorpattern2::tmpClass* tmp2 = new iteratorpattern2::tmpClass(2);
    iteratorpattern2::tmpClass* tmp3 = new iteratorpattern2::tmpClass(3);
    iteratorpattern2::tmpClass* tmp4 = new iteratorpattern2::tmpClass(4);

    Aggregate<iteratorpattern2::tmpClass>* aggregatePtr = new Aggregate<iteratorpattern2::tmpClass>();
    aggregatePtr->push(tmp1);
    aggregatePtr->push(tmp2);
    aggregatePtr->push(tmp3);
    aggregatePtr->push(tmp4);

    Iterator<iteratorpattern2::tmpClass, Aggregate<iteratorpattern2::tmpClass> >* iteratorPtr = aggregatePtr->createIterator();
    iteratorpattern2::tmpClass* tmp = iteratorPtr->getFirst();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getNext();
    tmp->action1();
    tmp->action2();

    tmp = iteratorPtr->getCurrent();
    tmp->action1();
    tmp->action2();

    bool isEnd = iteratorPtr->isEnd();
    cout << "isEnd = " << isEnd << endl;

    delete tmp1;
    delete tmp2;
    delete tmp3;
    delete tmp4;
    delete aggregatePtr;
    delete iteratorPtr;
    delete tmp;
}

int main(void)
{
    // func1();

    func2();

    return 0;
}