#include "Observable.h"
#include "Observer.h"

Observer::Observer()
{

}

Observer::~Observer()
{
    
}

ConcreteObserver::ConcreteObserver(string name) : m_objName(name)
{

}

ConcreteObserver::~ConcreteObserver()
{

}

void ConcreteObserver::update(Observable* ob)
{
    m_observerState = ob->getState();
    std::cout << "update observer[" << m_objName << "] state:" << m_observerState << endl;
}