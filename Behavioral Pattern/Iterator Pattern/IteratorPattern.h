// 不使用类模板，使用基类与继承来实现，这样通用性不强

#include <iostream>
#include <vector>

using namespace std;

namespace iteratorpattern1{

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

class AbstractIterator
{
public:
    AbstractIterator(){};
    virtual ~AbstractIterator(){};
    virtual tmpClass* getFirst() = 0;
    virtual tmpClass* getNext() = 0;
    virtual tmpClass* getCurrent() = 0;
    virtual bool isEnd() = 0;
};

class AbstractAggregate
{
public:
    virtual unsigned int getCount() = 0;
    virtual void push(tmpClass* pushclass) = 0;
    virtual tmpClass* pop(unsigned int index) = 0;
    virtual AbstractIterator* createIterator() = 0;
};

class ConcreteIterator: public AbstractIterator
{
public:
    ConcreteIterator(){};
    ConcreteIterator(AbstractAggregate* aggregate)
    :m_aggregate(aggregate),
    m_currentIdx(0) {};
    virtual ~ConcreteIterator(){};

    virtual tmpClass* getFirst()
    {
        return m_aggregate->pop(1);
    };

    virtual tmpClass* getCurrent()
    {
        if (m_currentIdx < m_aggregate->getCount())
        {
            return m_aggregate->pop(m_currentIdx);
        }

        return NULL;
    }

    virtual tmpClass* getNext()
    {
        m_currentIdx++;
        if (m_currentIdx < m_aggregate->getCount())
        {
            return m_aggregate->pop(m_currentIdx);
        }

        return NULL;
    };

    virtual bool isEnd()
    {
        if (m_currentIdx == m_aggregate->getCount())
        {
            return true;
        }

        return false;
    }

private:
    AbstractAggregate* m_aggregate;
    unsigned int m_currentIdx;
};

class ConcreteAggregate: public AbstractAggregate
{
public:
    ConcreteAggregate(){};
    virtual ~ConcreteAggregate(){};

    virtual unsigned int getCount()
    {
        return m_num;
    };

    virtual void push(tmpClass* pushclass)
    {
        m_vector.push_back(pushclass);
        m_num++;
    };

    virtual tmpClass* pop(unsigned int index)
    {
        if (index < getCount())
        {
            return m_vector[index-1];
        }

        return NULL;
    };

    virtual AbstractIterator* createIterator()
    {
        return new ConcreteIterator(this);
    }

private:
    vector<tmpClass*> m_vector;
    unsigned int m_num;
};

} // namespace iteratorpattern1
