#include <stdio.h>
//author:Nic github 
//链表相关

//单链表插入
Status InsertList(LinkList head,DataType x,int i)
{
    ListNode *p;
    p=head;
    int j=1;
    while(p && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j<i)
    {

    }
    s=(ListNode *)malloc(sizeof(ListNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
    return OK;

}

//单链表删除
Status DeleteList(LinkList head,int i)
{
    ListNode *p,*r;
    p=head;
    int j=1;
    while(p->next && j<i)
    {
        p=p->next;
        ++j;
    }
    if(p->next==NULL || j>i)
    {
        printf("");
    }
    r=p->next;
    p->next=r->next;
    free(r);
    return OK;
}

//删除头结点
void RemoveHead(LinkList head)
{
    ListNode *p;
    p=head->next;
    head->next=p->next;
    free(p);
}

//如何找出单链表中倒数第k个元素
//双指针，快慢指针法
template<class T>
struct ListNode
{
    T data;
    ListNode *next;
};

template<class T>
ListNode<T>* FindElem(ListNode<T> *head,int k)
{
    ListNode<T> *ptr1,*ptr2;
    ptr1=ptr2=head;
    for(int i=0;i<k,++i)
    {
        ptr1=ptr1->next;
    }
    while(ptr1!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr2;
}
