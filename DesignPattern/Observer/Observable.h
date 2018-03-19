#include <iostream>
#include <vector>
using namespace std;

class Observable {
public:
    Observable();
    virtual ~Observable();

    Observer *m_Observer; //???

    void attach(Observer *p_Observer);
    void detach(Observer *p_Observer);
    void notify();

    virtual int getState() = 0;
    virtual void setState(int i) = 0;    

private:
    vector<Observer*> m_vtObj;
};

class ConcreteObservable : Observable {
public:

private:
    int m_State;
};