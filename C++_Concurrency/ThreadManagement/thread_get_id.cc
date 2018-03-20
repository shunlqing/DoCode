#include <iostream>
#include <thread>
using namespace std;

void func()
{
    cout << "thread id:" << this_thread::get_id() << endl; //当前线程获取线程ID
}

int main()
{
    std::thread t(func);
    cout << "thread id:" << t.get_id() << endl;//获取指定线程对象的线程ID
    t.join();
}