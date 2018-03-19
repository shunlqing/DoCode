#include "Observer.h"

ConcreteObserver::ConcreteObserver(string name) : m_objName(name)
{
}

ConcreteObserver::~ConcreteObserver()
{

}

void ConcreteObserver::update(Observable* ob)
{
    m_observerState = ob->getState();
    cout << "update observer[" << m_objName << "] state:" << m_observerState << endl;
}