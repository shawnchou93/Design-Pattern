#include <iostream>

using namespace std;

class AbstractBuilder
{
public:
    AbstractBuilder(){};
    ~AbstractBuilder(){};

    virtual void action1() = 0;
    virtual void action2() = 0;
    virtual void action3() = 0;
};

class ConcreteBuilder: public AbstractBuilder
{
public:
    ConcreteBuilder(){};
    ~ConcreteBuilder(){};

    virtual void action1()
    {
        cout << "action1 done" << endl;
    };
    virtual void action2()
    {
        cout << "action2 done" << endl;
    };
    virtual void action3()
    {
        cout << "action3 done" << endl;
    };
};

class Director
{
public:
    Director(){};
    ~Director(){};

    void setBuilder(AbstractBuilder* pBuilder)
    {
        m_pBuilder = pBuilder;
    }

    void buildProcess(void)
    {
        m_pBuilder->action1();
        m_pBuilder->action2();
        m_pBuilder->action3();
    }

private:
    AbstractBuilder* m_pBuilder;
};

