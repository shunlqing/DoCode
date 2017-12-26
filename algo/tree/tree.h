#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void PrintTree(BinaryTreeNode* pTree);

#endif