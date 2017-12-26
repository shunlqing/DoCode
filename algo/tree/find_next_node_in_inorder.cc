/**
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

TreeNode* NextNodeOfInorder(TreeNode* pTree, )
