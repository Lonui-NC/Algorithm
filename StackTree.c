#include <stdio.h>
//author:Nic github 
//二叉树遍历
typedef struct 
{
    Bitree Elem[100];
    int pop;
}SqStack;//结构体指针

void PreOrderUnrec(Bitree t)
{
    SqStack s;
    StackInit(s);
    p=t;
    while(p!=null || !StackEmpty(s))
    {
        while(p!=null)
        {
            visite(p->data);
            push(s,p);
            p=p->lchild;
        }
        if(!StackEmpty(s))
        {
            //最后一步时p为空，此时pop后，得到的是上一个父节点，然后执行p->rchild 递归
            p=pop(s);
            p=p->rchild;
        }
    }
}

void InOrderUnrec(Bitree t)
{
    SqStack s;
    StackInit(s);
    p=t;
    while(p!=null || !StackEmpty(s))
    {
        while(p!=null)
        {
            push(s,p);
            p=p->lchild;
        }
        if(!StackEmpty(s))
        {
            p=pop(s);
            visite(p->data);
            p=p->rchild;
        }
    }
}
