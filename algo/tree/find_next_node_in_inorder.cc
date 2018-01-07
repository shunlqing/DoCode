/**
 * 剑指Offer 题8
 * 题目: 二叉树的下一个节点
 *     给定一棵二叉树和其中一个节点,如何找出中序遍历序列的下一个节点?树中的节点除了有两个分别指向左,右子节点的指针,还有一个指向父节点的指针
*/

#include <iostream>
// #include "tree.h"
using namespace std;

struct TreeNode {
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
    TreeNode* m_pParent;
};

TreeNode* NextNodeOfInorder(TreeNode* pTree)
{
    if(pTree == nullptr)
        return nullptr;
    
    TreeNode * pNext = nullptr;
    if(pTree->m_pRight != nullptr)
    {
        TreeNode *p = pTree->m_pRight;
        while(p->m_pLeft != nullptr)
            p = p->m_pLeft;

        pNext = p;
    }
    else
    {
        TreeNode *y = pTree->m_pParent;
        TreeNode *p = pTree;

        while(y != nullptr && p == y->m_pRight)
        {
            p = y;
            y = y->m_pParent;
        }

        if(y == nullptr)
            pNext = nullptr;
        
        if(p == y->m_pLeft)
            pNext = y;
    }
        
    return pNext;
}
