/**
 * 题目:从尾到头打印链表
 *  输入一个链表的头节点, 从尾到头打印出每个节点的值
*/

#include <iostream>
#include <stack>
#include "list.h"
using namespace std;

/**
 * 使用递归,递归本质上是一种栈的思想
*/
void PrintReversingly1(ListNode *pHead)
{
    if(pHead == nullptr)
        return;
    else 
        PrintReversingly1(pHead->m_pNext);

    cout << pHead->m_nValue << ' ';
    return;
}

/**
 * 使用栈
*/
void PrintReversingly2(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nValue << ' ';
        nodes.pop();
    }
}

int main()
{
    ListNode * testlist = MakeRandomList(5);
    PrintReversingly2(testlist);
    FreeList(testlist);
}