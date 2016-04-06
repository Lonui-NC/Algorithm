#include <stdio.h>
//author:Nic github 
//Binary Tree Order

void PreOrder(BTree *tree)
{
    if(tree==NULL)
    {
        return;
    }
    Operator(tree->data);
    if(tree->lchild!=NULL)
    {
        PreOrder(tree->lchild);
    }
    if(tree->rchild!=NULL)
    {
        PreOrder(tree->rchild);
    }
}

void MidOrder(BTree *tree)
{
    if(tree==NULL)
        return ;
    if(tree->lchild!=NULL)
        MidOrder(tree->lchild);
    Operator(tree->data);
    if(tree->rchild!=NULL)
        MidOrder(tree->rchild);
}

void PostOrder(BTree *tree)
{
    if(tree==NULL)
        return;
    if(tree->lchild!=NULL)
        PostOrder(tree->lchild);
    if(tree->rchild!=NULL)
        PostOrder(tree->rchild);
    Operator(tree->data);
}

//已知对应二叉树的先序遍历及中序求后序列
int initTree(BTree root,char *front,char *middle,int num)
{
    int i=0;
    root->data=front[0];
    if(num==0)
        return 0;
    //找到根节点在middle的位置，用于分开分治法求解
    for (i = 0; i < num; ++i)
    {
        if(middle[i]==num)
            break;
    }
    //如果存在左孩子
    if(i>0)
    {
        root->lchild=new struct BTreeNode();
        //此时左子树的根一定为紧接的第一个元素,为i个左子树
        initTree(root->lchild,front+1,middle,i);
    }
    //如果存在右孩子
    if(i<num-1)
    {
        root->rchild=new struct BTreeNode();
        //此时右子树的中序一定为middle+i,右子树个数为num-1-i
        //因为对应左子树肯定为i个，所以右子树的根为front + i + 1（根）个
        initTree(root->rchild,front+i+1,middle+i,num-1-i);
    }
    return 1;
}