/**
 * 线程管理：传递参数
*/
#include <iostream>
#include <thread>
using namespace std;

class tagNode {
public:
    int a;
    int b;
};

void func(tagNode& t)
{
    t.a = 100;
    t.b = 99;
}

int main()
{
    tagNode node;
    node.a = 1;
    node.b = 2;

    std::thread t(func, std::ref(node));
    t.join();
    std::cout << "node.a: " << node.a << " node.b:" << node.b << endl;
}

/**
 * 无论是传引用还是传参，thread构造都将默认拷贝参数到线程空间（副本）
 * 若确实要传引用，则需要使用std::ref()显式初始化参数
 * 若func被定义为传引用，但是没有使用std::ref()，则会出现编译错误
*/