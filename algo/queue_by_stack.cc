/**
 * 剑指Offer 題9
 * 题目：用两个栈实现队列
 *     用两个栈实现队列，队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成队列尾部插入节点和在队列头部删除节点的功能
 * 
 * 延伸：用两个队列实现栈
 * 
*/

#include <exception>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class CQueue {
public:
    CQueue(void){};
    ~CQueue(void){};

    void appendTail(const T& node);
    T deleteHead(void);

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead(void)
{
    if(stack2.empty())
    {
        T node;
        while(!stack1.empty())
        {
            node = stack1.top();
            stack2.push(node);
            stack1.pop();
        }
    }

    if(!stack2.empty())
    {
        T ret;
        ret = stack2.top();
        stack2.pop();
        return ret;
    }

    throw runtime_error("queue is empty");
}

template <typename T>
class CStack {
public:
    CStack();
    ~CStack();

    void pop();
    void push(const T& node);

private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T>
void CStack<T>::pop()
{
    if(queue1.empty() && queue2.empty())
        throw runtime_error("stack is empty");

    if(queue1.empty())
    {
        while(queue2.size() > 1)
        {
            queue1.push(queue2.top());
            queue2.pop();
        }
        queue2.pop();
    }

    if(queue2.empty())
    {
        while(queue1.size() > 1)
        {
            queue2.push(queue1.top());
            queue1.pop();
        }
        queue2.pop();
    }
}

template <typename T>
void CStack<T>::push(const T& node)
{
    if(queue1.empty() && queue2.empty()) {
        queue1.push(node);
    }
    else if(!queue1.empty()) {
        queue2.push(node);
    }
    else {
        queue1.push(node);
    }
}

int main()
{
    CQueue<int> cq;
    cq.appendTail(1);
    cq.appendTail(2);
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    // cout << cq.deleteHead();
}