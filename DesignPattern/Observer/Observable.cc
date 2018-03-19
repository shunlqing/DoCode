#include "Observer.h"
#include "Observable.h"

Observable::Observable()
{

}

Observable::~Observable()
{

}

void Observable::attach(Observer *p_Observer)
{
    m_vtObj.push_back(p_Observer);
}

void Observable::detach(Observer *p_Observer)
{
    for(vector<Observer*>::iterator it = m_vtObj.begin();
            it != m_vtObj.end(); it++)
            {
                if(*it == p_Observer)
                {
                    m_vtObj.erase(it);
                    return;
                }            
            }
} 

void Observable::notify()
{
    for(vector<Observer*>::iterator it = m_vtObj.begin();
            it != m_vtObj.end(); it++)
            {
                (*it)->update(this);
            }  
} 

ConcreteObservable::ConcreteObservable()
{
    m_State = 0;
}

ConcreteObservable::~ConcreteObservable()
{

}

int ConcreteObservable::getState()
{
    return m_State;
}

void ConcreteObservable::setState(int i)
{
    m_State = i;
}