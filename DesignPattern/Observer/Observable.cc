#include "Observable.h"

Observable::Observable()
{

}

Observable::~Observable()
{

}

void Observable::attach(Obserser *p_Observer)
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