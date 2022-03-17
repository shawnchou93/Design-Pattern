#include <iostream>

using namespace std;

class AbstractProduction
{
public:
    AbstractProduction(){};
    ~AbstractProduction(){};

    virtual void action1() = 0;
    virtual void action2() = 0;
};

class ConcreteProductionA: public AbstractProduction
{
public:
    ConcreteProductionA(){};
    ~ConcreteProductionA(){};

    virtual void action1()
    {
        cout << "ProductionA action1" << endl;
    };
    virtual void action2()
    {
        cout << "ProductionA action2" << endl;
    };
};

class ConcreteProductionB: public AbstractProduction
{
public:
    ConcreteProductionB(){};
    ~ConcreteProductionB(){};

    virtual void action1()
    {
        cout << "ProductionB action1" << endl;
    };
    virtual void action2()
    {
        cout << "ProductionB action2" << endl;
    };
};

class ConcreteProductionC: public AbstractProduction
{
public:
    ConcreteProductionC(unsigned int input1, unsigned int input2):
    m_param1(input1),
    m_param2(input2){

    };
    ~ConcreteProductionC(){};

    virtual void action1()
    {
        cout << "ProductionC action1" << endl;
        cout << "m_param1 =" << m_param1 << endl;
    };
    virtual void action2()
    {
        cout << "ProductionC action2" << endl;
        cout << "m_param2 =" << m_param2 << endl;
    };

    unsigned int m_param1;
    unsigned int m_param2;
};


class AbstractFactory
{
public:
    AbstractFactory(){};
    ~AbstractFactory(){};

    virtual AbstractProduction* getProduction(void) = 0;


};


class ConcreteFactoryA: public AbstractFactory
{
public:
    ConcreteFactoryA(){};
    ~ConcreteFactoryA(){};

    AbstractProduction* getProduction(void)
    {
        AbstractProduction* productionPtr = NULL;
        productionPtr = new ConcreteProductionA();

        return productionPtr;
    }


};

class ConcreteFactoryB: public AbstractFactory
{
public:
    ConcreteFactoryB(){};
    ~ConcreteFactoryB(){};

    AbstractProduction* getProduction(void)
    {
        AbstractProduction* productionPtr = NULL;
        productionPtr = new ConcreteProductionB();

        return productionPtr;
    }


};

class ConcreteFactoryC: public AbstractFactory
{
public:
    ConcreteFactoryC(){};
    ~ConcreteFactoryC(){};

    AbstractProduction* getProduction(void)
    {
        AbstractProduction* productionPtr = NULL;
        productionPtr = new ConcreteProductionC(100, 200);

        return productionPtr;
    }


};

