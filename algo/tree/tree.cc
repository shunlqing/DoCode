#include <iostream>
#include "tree.h"

using namespace std;

void PrintTree(BinaryTreeNode* pTree)
{
    if(pTree == nullptr)
        return;
    cout << pTree->m_nValue << ' ';
    PrintTree(pTree->m_pLeft);
    PrintTree(pTree->m_pRight);
}