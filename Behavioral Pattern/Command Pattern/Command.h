#include <iostream>
#include <vector>

using namespace std;

class Receiver
{
    public:
    void task1()
    {
        cout << "this is task1!" << endl;
    }

    void task2()
    {
        cout << "this is task2!" << endl;
    }

};

class abstractCommand
{
public:
    virtual void execute() = 0;

    Receiver* m_receiver;
};

class concreteCommand1:public abstractCommand
{
    public:
    concreteCommand1(Receiver* receiver)
    {
        this->m_receiver = receiver;
    }
    void execute()
    {
        m_receiver->task1();
    }
};

class concreteCommand2:public abstractCommand
{
    public:
    concreteCommand2(Receiver* receiver)
    {
        this->m_receiver = receiver;
    }
    void execute()
    {
        m_receiver->task2();
    }
};

class Invoker
{
    public:
    vector<abstractCommand*> commandQueue;
    // abstractCommand* m_pcmd;

    void addCommand(abstractCommand* command)
    {
        commandQueue.push_back(command);
    }

    void work()
    {
        vector<abstractCommand*>::iterator it = commandQueue.begin();
        for(it; it != commandQueue.end(); it++)
        {
            // m_pcmd = *it;
            // m_pcmd->execute();
            (*it)->execute();
        }
    }

};



// end of file

