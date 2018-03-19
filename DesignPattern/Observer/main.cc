#include <iostream>
#include "Observer.h"
#include "Observable.h"

int main(int argc, char** argv)
{
    Observable * obj = new ConcreteObservable();
    Observer * objA = new ConcreteObserver("Observer_A");
    Observer * objB = new ConcreteObserver("Observer_B");
    obj->attach(objA);
    obj->attach(objB);

    obj->setState(1);
    obj->notify();

    cout << "--------------" << endl;
    obj->detach(objB);
    obj->setState(2);
    obj->notify();

    delete obj;
    delete objA;
    delete objB;

    return 0;
}