/***
 *  不完整
 */

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "list.h"
using namespace std;

ListNode* MakeEmptyList()
{
    ListNode *pHead = nullptr;
    return pHead;
}

ListNode* MakeRandomList(int size)
{
    ListNode * pHead = nullptr;
    srand((unsigned)time(NULL));

    ListNode *tmp = new ListNode();
    tmp->m_nValue = rand()%20;
    tmp->m_pNext = nullptr;
    pHead = tmp;
    for(int i = 1; i < size; i++)
    {
        ListNode *tmp = new ListNode();
        tmp->m_nValue = rand()%20;
        tmp->m_pNext = pHead->m_pNext;
        pHead->m_pNext = tmp;
    }

    ListNode* t = pHead;
    while(t != nullptr)
    {
        cout << t->m_nValue << ' ';
        t = t->m_pNext;
    }
    cout << endl;

    return pHead;
}

void FreeList(ListNode * pHead)
{
    if(pHead == nullptr)
        return;

    ListNode* tmp = pHead;
    while(tmp != nullptr)
    {
        pHead = pHead->m_pNext;
        free(tmp);
        tmp = pHead;
    }
}

ListNode* PrintList(ListNode* pHead)
{
    ListNode* p = pHead;
    cout << "List: ";
    while(p != nullptr)
    {
        cout << p->m_nValue << ' ';
    }
    cout << endl;
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode * pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;

        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    
    if(pToBeDeleted != nullptr){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}