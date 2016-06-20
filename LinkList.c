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
#include <iostream>
#define MAXSIZE 1024
#define LENGTH 8

using namespace std;

typedef struct 
{
    /* data */
    int r[MAXSIZE+1];
    int length;
}SqList;


void Merge(SqList SR,SqList &TR,int i,int m,int n)
{
    int j,k;
    //比较两个部分，1个是i开始的，1个是j开始的
    //两个区域对应的是两个归并前的数组
    for(j=m+1,k=i;i<=m&&j<=n;++k)
    {
        if(SR.r[i]<=SR.r[j])
            TR.r[k]=SR.r[i++];
        else
            TR.r[k]=SR.r[j++];
    }
    while(i<=m)
        TR.r[k++]=SR.r[i++];
    while(j<=n)
        TR.r[k++]=SR.r[j++];
}
//机智如你，一个值传递没影响，一个引用传递改变！！！！
void MSort(SqList SR,SqList &TR1,int s,int t)
{
    int m;
    SqList TR2;
    //t是长度的右边
    //s是长度的左边
    if(s==t)
        TR1.r[s]=SR.r[t];
    else
    {
        //共分一下几个变量
        //SqList 是初始的链表
        //TR1，TR2，是分开后的两个列表
        //因为三者所有东西一样，所以排序通过下标来
        m=(s+t)/2;
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
}


void MergeSort(SqList &L)
{
    MSort(L,L,1,L.length);
}




//如何实现单链表交换任意两个元素
struct node
{
    int data;
    node *next;
};

//返回前驱节点
node *FindPre(node *head,node *p)
{
    node *q=head;
    while(q)
    {
        if(q->next==p)
            return q;
        else
            q=q->next;
    }
    return NULL;
}

//主要是考虑的情况多
//如果两个元素数据相同，则不交换
//如果一个是另一个的前面，情况不同，
//还有就是两个元素在两个地方
node *Swap(node *head,node *p,node *q)
{
    if(head==NULL || p==NULL || q==NULL)
    {
        return head;
    }
    if(p->data==q->data)
        return head;
    if(p->next==q)
    {
        node* pre_p=FindPre(head,p);
        pre_p->next=q;
        p->next=q->next;
        q->next=p;
    }
    else if(q->next==p)
    {
        node* pre_q=FindPre(head,q);
        pre_q->next=p;
        q->next=p->next;
        p->next=q;
    }
    else if (p!=q)
    {
        node* pre_p=FindPre(head,p);
        node* pre_q=FindPre(head,q);
        node* after_p=p->next;
        p->next=q->next;
        q->next=after_p;
        pre_p->next=q;
        pre_q->next=p;
    }
    return head;
}


//快慢指针法判断是否有环
struct listtype
{
    int data;
    struct listtype *next;
}

typedef struct listtype *list;

int isLoop(list sll)
{
    list fast=sll->next;
    list slow=sll;
    if(fast==NULL || fast==slow)
        return -1;
    //快慢指针寻找
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==slow)
        {
            return 1;
        }
    }
}


// map指针表映射
map<node*,int>m;
bool isLoop(node *head)
{
    if(!head)
    {
        return false;
    }
    node *p=head;
    while(p)
    {
        if(m[p]==0)//默认都是0
            m[p]=1;
        else if(m[p]==1)
            return true;
        p=p->next;
    }
}

// fast 2s
// slow s
//2s=s+nr;
list* FindLoopPort(list *head)
{
    list *slow=head,*fast=head;
    while(fast && fast->next)
    {
        //慢指针每次走一步，快每次走两步
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }

    if(fast==NULL || fast->next==NULL)
    {
        return NULL;
    }
//找到对应单链表环的入口
//从链表头与相遇点各设置一个指针，2个指针必定相遇，且相遇第一点为环入口点
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}


//如何判断两个单链表（无环）是否交叉
//1将两个链表首尾相连，然后检测是否有两个环
//2判断两个链表的尾结点是否相同,如果相同，
//第一个节点用lengthMax-lengthMin后第二个再继续向前走
//对应可得新的相交点
bool IsIntersect(Node *list1,Node *list2,Node* &value)
{
    value=NULL;
    if(list1==NULL || list2==NULL)
    {
        return false;
    }
    Node *temp1=list1,*temp2=list2;
    int size1=0,size2=0;
    //temp1的长度
    while(temp1->next)
    {
        temp1=temp1->next;
        ++size1;
    }
    //temp2的长度
    while(temp2->next)
    {
        temp2=temp2->next;
        ++size2;
    }
    //判断尾节点是否相等
    if(temp1==temp2)
    {
        if(size1>size2)
        {
            while(size1-size2>0)
            {
                list1=list1->next;
                --size1;
            }
        }
        if(size2>size1)
        {
            while(size2-size1>0)
            {
                list2=list2->next;
                --size2;
            }
        }
        while(list2!=list1)
        {
            list1=list1->next;
            list2=list2->next;
        }
        value=list1;
        return value;
    }
    else
        return false;
}


//如何删除单链表中重复的节点
//重复删除没有排序的链表中重复的节点
//方法1 递归求解
//递归求解每次从最小的开始
//依次循环判断当前节点与后面已无重复等1节点之间是否有重复
//如果有重复就删除掉！
link delSame(link head)
{
    link pointer,temp=head;
    if(head->next==NULL)
    {
        return head;
    }
    head->next=delSame(head->next);
    pointer=head->next;
    while(pointer!=NULL)
    {
        if(head->number==pointer->number)
        {
            temp->next=pointer->next;
            free(pointer);
            pointer=temp->next;
        }
        else
        {
            pointer=pointer->next;
            temp=temp->next;
        }
    }
    return head;

}

//采用Hash法，将对应的节点放入Hash表中，如果有节点，则删除原有节点，
//否则将对应节点放入hash表




