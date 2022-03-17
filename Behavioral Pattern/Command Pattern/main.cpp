#include "Command.h"

int main()
{
    Invoker* pInvoker = new Invoker(); // The invoker is like a command processor
    Receiver* pReceiver = new Receiver(); // the receiver is action implementer 
    concreteCommand1* pCommand1 = new concreteCommand1(pReceiver);
    concreteCommand2* pCommand2 = new concreteCommand2(pReceiver);

    pInvoker->addCommand(pCommand1);
    pInvoker->addCommand(pCommand2);
   
    pInvoker->work();

    return 0;
}