// 使用类模板，这样通用性强

#include <iostream>
#include <vector>

using namespace std;

namespace iteratorpattern2{

class tmpClass
{
public:
    tmpClass(){};
    tmpClass(unsigned int val): m_val(val) {};
    ~tmpClass(){};

    void action1()
    {
        cout << "tmpClass:action1" << endl;
    };

    void action2()
    {
        cout << m_val << endl;
    };

    unsigned int m_val;
};


template <class T, class N>
class Iterator
{
public:
    Iterator(){};
    Iterator(N* aggregate): m_aggregate(aggregate), m_currentIdx(0) {};
    ~Iterator(){};

    tmpClass* getFirst()
    {
        return m_aggregate->pop(1);
    };

    tmpClass* getCurrent()
    {
        if (m_currentIdx < m_aggregate->getCount())
        {
            return m_aggregate->pop(m_currentIdx);
        }

        return NULL;
    }

    tmpClass* getNext()
    {
        m_currentIdx++;
        if (m_currentIdx < m_aggregate->getCount())
        {
            return m_aggregate->pop(m_currentIdx);
        }

        return NULL;
    };

    bool isEnd()
    {
        if (m_currentIdx == m_aggregate->getCount())
        {
            return true;
        }

        return false;
    }

private:
    N* m_aggregate;
    unsigned int m_currentIdx;
};


template <class T>
class Aggregate
{
public:
    Aggregate(){};
    ~Aggregate(){};

    unsigned int getCount()
    {
        return m_num;
    };

    void push(T* pushclass)
    {
        m_vector.push_back(pushclass);
        m_num++;
    };

    T* pop(unsigned int index)
    {
        if (index < getCount())
        {
            return m_vector[index-1];
        }

        return NULL;
    };

    Iterator<T, Aggregate>* createIterator()
    {
        return new Iterator<T, Aggregate>(this);
    }

private:
    vector<T*> m_vector;
    unsigned int m_num;
};

} // namespace iteratorpattern1
