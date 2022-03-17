#include <iostream>

using namespace std;

class Proxy
{
public:
    Proxy(){};
    ~Proxy(){};

    void request()
    {

    }
};

class RealObject
{
public:
    RealObject(){};
    ~RealObject(){};

    void action1()
    {
        cout << "action 1" << endl;
    };

    void action2()
    {
        cout << "action 2" << endl;
    };

    void action3()
    {
        cout << "action 3" << endl;
    };

};


