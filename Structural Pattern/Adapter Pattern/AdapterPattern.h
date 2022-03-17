#include <iostream>

using namespace std;


class Target
{
public:

    virtual void request(void){};
};

class Adaptee
{
public:
    Adaptee(){};
    ~Adaptee(){};

    virtual void action1(void)
    {
        cout << "Adaptee:action1" << endl;
    };

};

// 类适配, public继承并实现目标接口，private继承适配者提供的接口，最终适配器使用目标要求的接口调用继承自适配者提供的接口，从而实现适配
class AdapterA: public Target, private Adaptee
{
public:
    AdapterA(){};
    ~AdapterA(){};

    void request(void)
    {
        cout << "AdapterA:request" << endl;
        this->action1();
    }
};

// 对象适配，public继承并实现目标接口，把适配者对象传入适配器，适配器使用目标要求的接口直接调用适配者提供的接口
// 可以把多个适配者传入适配器，从而实现对象的组合
class AdapterB: public Target
{
public:
    AdapterB(Adaptee* adaptee): m_pAdaptee(adaptee){};
    AdapterB(){};
    ~AdapterB(){};

    void request(void)
    {
        cout << "AdapterB:request" << endl;
        m_pAdaptee->action1();
    }

private:
    Adaptee* m_pAdaptee;

};
