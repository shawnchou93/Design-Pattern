#include <iostream>

using namespace std;

class singletonClass
{
public:
    singletonClass()
    {
        cout << "Constructor Called!" << endl;
    }
    ~singletonClass()
    {
        cout << "Deconstructor Called!" << endl;
    }

    static singletonClass& getInstance()
    {
       static singletonClass instanceObj;

        return instanceObj;
    }



};




