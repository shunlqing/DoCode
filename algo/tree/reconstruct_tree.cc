/**
 * 题目:重建二叉树
 *     输入某二叉树的前序遍历和中序遍历的结果,请重建二叉树.假设输入的前序遍历和中序遍历的结果中都不含重复的数字.
*/

#include <iostream>
#include "tree.h"
using namespace std;

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr)
        return nullptr;

    if(length == 1)
    {
        BinaryTreeNode* root = new BinaryTreeNode();
        root->m_nValue = *preorder;
        root->m_pLeft = nullptr;
        root->m_pRight = nullptr;

        return root;
    }
    
    int rootValue = *preorder;
    int left_cnt = 0;
    int * p = inorder;
    while(*p != rootValue){
        p++;
        left_cnt++;
    }

    int * preorderOfLeft, *inorderOfLeft, *preorderOfRight, *inorderOfRight;
    int lengthOfLeft, lengthOfRight;

    if(left_cnt == 0){
        preorderOfLeft = nullptr;
        inorderOfLeft = nullptr;
        lengthOfLeft = 0;
    } else {
        preorderOfLeft = preorder + 1;
        inorderOfLeft = inorder;
        lengthOfLeft = left_cnt;
    }

    if((length - left_cnt - 1) == 0) {
        preorderOfRight = nullptr;
        inorderOfRight = nullptr;
        lengthOfRight = 0;
    } else {
        preorderOfRight = preorder + (left_cnt + 1);
        inorderOfRight = inorder + (left_cnt + 1);
        lengthOfRight = length - left_cnt - 1;
    }

    BinaryTreeNode * pLeftTree;
    BinaryTreeNode * pRightTree;
    if(lengthOfLeft > 0) {
        pLeftTree = Construct(preorderOfLeft, inorderOfLeft, lengthOfLeft);
    } else {
        pLeftTree = nullptr;
    }

    if(lengthOfRight > 0) {
        pRightTree = Construct(preorderOfRight, inorderOfRight, lengthOfRight);
    } else {
        pRightTree = nullptr;
    }

    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = pLeftTree;
    root->m_pRight = pRightTree;

    return root;
}

int main()
{
    int pre[8] = {1,2,4,7,3,5,6,8};
    int in[8] = {4,7,2,1,5,3,8,6};
    BinaryTreeNode* tree = Construct(pre, in, 8);
    PrintTree(tree);

    int pre1[5] = {1,2,3,4,5};
    int in1[5] = {5,4,3,2,1};
    tree = Construct(pre1, in1, 5);
    PrintTree(tree);

}