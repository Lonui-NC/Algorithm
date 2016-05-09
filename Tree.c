#include <stdio.h>
//author:Nic github 
//二叉树

typedef struct _TreeNode
{
    char c;
    _TreeNode *leftchild;
    _TreeNode *rightchild;
}TreeNode;

int compTree(TreeNode *tree1,TreeNode *tree2)
{
    if(!tree1 && !tree2)
    {
        return 1;
    }
    if((tree1 && !tree2) || (!tree1 && tree2))
    {
        return 0;
    }
    if(tree1 && tree2)
    {
        if(tree1->c==tree2->c)
        {
            if(compTree(tree1->leftchild,tree2->leftchild))
            {
                return compTree(tree1->leftchild,tree2->rightchild);
            }
            else if(compTree(tree1->leftchild,tree2->rightchild))
            {
                return compTree(tree1->rightchild,tree2->leftchild);
            }
        }
    }
    return 0;
}

int TreeHeight(const TreeNode *root,bool & balanced)
{
    const int LHeight=root->leftchild ? TreeHeight(root->leftchild,balanced)+1:0;
    if(!balanced)
    {
        return 0;
    }
    const int RHeight=root->rightchild ? TreeHeight(root->rightchild,balanced)+1:0;
    if (!balanced)
        return 0;
    const int diff=LHeight-RHeight;
    if(diff<-1 || diff>1)
        balanced=false;//在这里完成对应的balanced 判断，然后通过直接返回0来进行判断
    return (LHeight>RHeight ? LHeight:RHeight);
}

bool IsBalancedTree(const TreeNode *root)
{
    bool balanced = true;
    if(root)
    {
        TreeHeight(root,balanced);
    }
    return balanced;
}