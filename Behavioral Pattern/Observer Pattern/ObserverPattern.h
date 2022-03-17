#include <iostream>
#include <vector>

using namespace std;


class AbstractObserver
{
public:
    virtual void update() = 0;

};

class AbstractObject
{
public:
    // AbstractObject(){};
    // ~AbstractObject(){};

    virtual void registerObserver(AbstractObserver* observer) = 0;
    virtual void unregisterObserver(AbstractObserver* observer) = 0;
    virtual void notify() = 0;

};


class ConcreteObserver: public AbstractObserver
{
public:
    ConcreteObserver(): m_value(0){};
    ~ConcreteObserver(){};

    virtual void update()
    {
        m_value++;
        cout << "m_value = " << m_value << endl;
    }

    unsigned int m_value;

private:
    
};

class ConcreteObject: public AbstractObject
{
public:
    virtual void registerObserver(AbstractObserver* observer)
    {
        m_vector.push_back(observer);
    }

    virtual void unregisterObserver(AbstractObserver* observer)
    {
        for(vector<AbstractObserver*>::iterator itr=m_vector.begin(); itr!=m_vector.end(); itr++)
        {
            if(*itr == observer)
            {
                m_vector.erase(itr);
                return;
            }			
        }
    }

    virtual void notify()
    {
        for(vector<AbstractObserver*>::iterator itr=m_vector.begin(); itr!=m_vector.end(); itr++)
        {
            (*itr)->update();
        }
    }

    unsigned int getObserverNum(void)
    {
        return m_vector.size();
    }

private:
    unsigned int m_numOfObserver;
    vector<AbstractObserver* > m_vector;

};






