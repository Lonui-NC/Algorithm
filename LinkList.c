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

//翻转链表
ListNode* ReverseIteratively(ListNode* pHead)
{
    ListNode* pReversedHead=NULL;
    ListNode* pNode=pHead;
    ListNode* pPrev=NULL;
    //同步翻转，只要一次遍历
    while(pNode!=NULL)
    {
        //先保存当前节点下一个节点
        ListNode* pNext=pNode->next;
        if(pNext==NULL)
            pReversedHead=pNext;
        //将当前节点的next指向前一个节点
        pNode->next=pPrev;
        pPrev=pNode;//将当前节点作为下一个的前一结点
        pNode=pNext;
    }
    return pReversedHead;
}

//如果是输出元素，则更加简单
void PrintReverseLink(ListNode* head)
{
    if(head->next!=NULL)
    {
        PrintReverseLink(head->next);
        printf("%d\n",head->val);
    }
}

//传递的是指针的引用，会改变head
//采用递归方法实现
ListNode* Reverse(ListNode* p,ListNode* &head)
{
    if(p==NULL || p->next==NULL)
    {
        head=p;
        return p;
    }
    else
    {
        //每次返回的都是最新的head和最新的前一项
        ListNode* temp=Reverse(p->next,head);
        temp->next=p;
        return temp;
    }

}

//从尾到头输出单链表可以引申为从尾到头输出一个字符串，以及求字符串长度

//快速寻找单链表的中间节点
//快慢指针法，每次走一步和两步
ListNode* SearchMid(node* head)
{
    node* temp=head;
    node* mid=head;
    while(head!=NULL && head->next!=NULL && head->next->next!=NULL)
    {
        head=head->next->next;
        temp=temp->next;
        mid=temp;
    }
    return mid;
}


//如何进行单链表排序
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int data;
    struct node *next;
}linkList;

linkList *head=NULL;

linkList* CreateList(int *arr,int len)
{
    //初始化定义，取当前指针，和结束的部分
    int data;
    linklist *pCurrent,*rear;
    head=(linklist*)malloc(sizeof(linkList));
    rear=head;

    int count=0;
    while(count<len)
    {
        pCurrent=(linklist*)malloc(sizeof(linkList));
        pCurrent->data=arr[count];
        rear->next=pCurrent;
        rear=pCurrent;
        count++;
    }
    rear->next=NULL;
    return head;
}

void ShowList(linklist* p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

}

void BubbleSortList(linkList * p)//链表冒泡排序
{
    linklist *_temp=p->next;
    linklist *_node=p->next;
    int temp;
    for(;_temp->next;_temp=_temp->next)
    {
        for(_node=p->next;_node->next;_node=_node->next)
        {
            //如果相邻的两个数大小，交换
            if(_node->data>_node->next->data)
            {
                temp=_node->data;
                _node->data=_node->next->data;
                _node->next->data=temp;
            }
        }
    }
}

//可以用归并排序进行，满足分治法条件





















