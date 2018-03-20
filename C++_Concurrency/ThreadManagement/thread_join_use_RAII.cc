/**
 * 如何保证主线程必然join到子线程
*/
#include <iostream>
#include <exception>
#include <thread>
using namespace std;

/**
 * 方法一：使用RAII封装，在析构函数中join
*/
class ThreadGuard {
public:
    explicit ThreadGuard(std::thread &t) : _t(t) {} 
    ~ThreadGuard() {
        if(_t.joinable()){
            _t.join();
        }
    }

    ThreadGuard(ThreadGuard& t) = delete;
    ThreadGuard& operator=(const ThreadGuard& _t) = delete;
private:
    std::thread &_t; // 线程对象不可拷贝，使用引用
};

void func1()
{
    std::thread t([]{
        cout << "ThreadFunc" << endl;
    });

    ThreadGuard g(t);
}


/**
 * 方法二：在创建子线程到join子线程的代码用try块，捕获异常
*/

void do_something(){}
void func2()
{
    std::thread t([]{
        cout << "threadFunc" << endl;
    });

    try {
        do_something();        
    }    
    catch(...) {
        t.join();
        throw;
    }
    t.join();
}

int main()
{
    func1();
}

/**
 * Compile: g++ thread_join_use_RAII.cc -std=c++11 -pthread
*/