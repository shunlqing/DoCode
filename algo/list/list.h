#ifndef _LIST_H_
#define _LIST_H_

struct ListNode {
    int     m_nValue;
    ListNode* m_pNext;
};

/**
 * 创建大小为size的链表, 结点的值为随机数, 返回指向首节点的ListNode*指针
*/
ListNode* MakeRandomList(int size);

/**
 * 打印链表
*/
ListNode* PrintList(ListNode* pHead);

/**
 * 释放链表内存
*/
void FreeList(ListNode * pHead);

#endif