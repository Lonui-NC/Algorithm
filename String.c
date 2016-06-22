#include <stdio.h>
//author:Nic github 
//字符串相关

//统计句子中单词出现的个数
//通过空格来判断，连续出现的为空格，否则为单词
#include <stdio.h>
#define BUFFERSIZE 1024

int main()
{
    char string[BUFFERSIZE];
    int i,count=0,word=0;
    char c;
    gets(string);
    for(i=0;(c=string[i])!='\0';i++)
    {
        if(c=='')
            word=0;
        else if(word==0)
        {
            word=1;
            count++;
        }
    }
    printf("%d",count);
}



//如何将字符串逆序
#include <stdio.h>
//普通逆序，设置等长字符串数组，反向拷贝
char *Reverse(char *s)
{
    char *q=s;
    while(*q++)
        ;
    q-=2;//计算对应字符串的长度，-2是到最后一个字符串的位置
    char *p=new char[sizeof(char)*(q-s+2)];
    char *r=p;
    //逆序存储
    while(q>=s)
        *p++=*q--;
    *p='\0';
    return r;
}

//方法2，原地逆序
//原地逆序不分配新的存储空间，将字符串数组的两边字符逐个交换
//设置两个指针，头尾交换

char *Reverse(char *s)
{
    char *p=s;
    char *q=s;
    while(*q)
        ++q;
    q--;
    while(q>p)
    {
        char t=*p;
        *p++=*q;
        *q--=t;
    }
    return s;
}

//递归方法逆序,使用指针
char *Reverse(char *s,int left,int right)
{
    if(left>=right)
        return s;
    char t=s[left];
    s[left]=s[right];
    s[right]=t;
    Reverse(s,left+1,right-1);
}

//非递归方法，使用下标
char *Reverse(char *s,int left,int right)
{
    while(left<right)
    {
        char t=s[left];
        s[left++]=s[right];
        s[right--]=t;
    }
}

//对于不允许有临时变量的部分，进行逆序主要有
//异或方法，异或可以得到交换两个变量而不引入第三个变量，
//或者对于结尾为'\0'的采用这一个来实现交换
//1)异或
char * Reverse(char *s)
{
    char *r=s;
    char *p=s;
    while(*(p+1)!='\0')
        ++p;
    while(p>s)
    {
        *p=*p^*s;
        *s=*p^*s;//前面异或后与自己异或了两次，变成了*p
        *p=*p--^*s++;//这个变成了s
    }
    return r;
}


//2)
char* Reverse(char *s)
{
    //没有占用额外的空间
    char *r=s;
    char *p=s;
    while(*p!='\0')
        ++p;
    char *q=p-1;
    while(q>s)
    {
        *p=*q;
        *q--=*s;
        *s++=*p;
    }
    *p='\0';
}

//按单词逆序，实现打印
//首先所有单词逆序，然后将整个句子逆序
void ReverseWord(char *p,char *q)
{
    while(p<q)
    {
        char t=*p;
        *p++=*q;
        *q--=t;
    }
}

char* Reverse(char *s)
{
    char *p=s;
    char *q=s;
    while(*q!='\0')
    {
        if(*q==' ')
        {
            ReverseWord(p,q-1);
            q++;
            p=q;
        }
        else
            q++;
    }
    //最后一个单词没有对应的空格
    ReverseWord(p,q-1);
    ReverseWord(s,q-1);
}


//如何实现逆序打印
//求出字符串长度，方向遍历即可
void ReversePrint(const char *s)
{
    int len=strlen(s);
    for(int i=len-1;i>=0;--i)
    {
        printf("%c",s[i]);
    }
}

//如果不求长度，先遍历到末尾，再遍历回来
void ReversePrint(const char *s)
{
    const char *p=s;
    while(*p)
        *p++;
    --p;
    while(p>=s)
    {
        printf("%c", *p);
        --p;
    }
}


//也可以用递归
void ReversePrint(const char *s)
{
    if(*(s+1)!='\0')
        ReversePrint(s+1);
    printf("%c",*s);
}





















