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


//如何找出一个字符串中第一个只出现1次的字符
#include <stdio.h>
//Hash法取对应数组，然后依次遍历
char GetChar(char str[])
{
    if(str==NULL)
        return 0;
    const int size=256;
    //对应的char应转换为无符号数
    unsigned count[size]={0};
    char buffer[size];
    char *q=buffer;
    for(const char *p=str;*p!=0;++p)
    {
        //这里写的表明了边界，防止重复查找
        if(++count[(unsigned char)*p]==1)
        {
            *q++=*p;
        }
    }
    for(p=buffer;p<q;++p)
    {
        if(count[(unsigned char)*p]==1)
            return *p;
    }
    return 0;
}



//如何输出字符串的所有组合
#include <stdio.h>
#include <string.h>

void CombileRevursiveImpl(const char *str,char *begin,char *end)
{
    if(*str==0)
    {
        *end=0;
        if(begin!=end)
            printf("%s\n", begin);
        return;
    }
    CombileRevursiveImpl(str+1,begin,end);
    *end=*str;
    //当为最后一个的时候，打印执行先是c 
    CombileRevursiveImpl(str+1,begin,end+1);
}


//构造01字符串进行组合
void Combine(const char str[])
{
    if(str==NULL || *str==0)
        return;
    const int MAXLENGTH=64;
    int len=strlen(str);
    bool used[MAXLENGTH]={0};
    char cache[MAXLENGTH];
    char *result=cache+len;//最后一个
    *result=0;
    while(1)
    {
        //同样第二次的时候这里变成了index 0,但是used变成了true
        int index=0;
        //开始index为0，对应为false
        while(used[index])
        {
            //进入执行，变成了false
            used[index]=false;
            //重新输出最后的一个
            ++result;//result 最后一个
            //index=1
            if(++index==len)
                return;
        }
        //index=1
        //对应为true
        used[index]=true;
        //将对应的输出最后一个字符
        //再来一次时，成为了ba
        *--result=str[index];
        //result--;
        printf("%s",result);
    }

}


//如何检查字符是否是整数
int cheak(int p)
{
    int c=p;
    if(isdigit(p))
        c=p-48;
    return c;
}

int main()
{
    int c;
    while((c=getchar())!=EOF)
    {
        getchar();
        c=cheak(c);
        if(isalpha(c))
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}



//如何查找字符串中每个字符出现的个数
//初始化数组加1即可
int main()
{
    char *str="AbcABCa";
    int count[256]={0};
    for(char *p=str;*p;p++)
    {
        count[*p]++;
    }
    for(int i=0;i<256;i++)
    {
        if(count[i]>0)
            printf("the count of %c is %d\n",i,count[i]);
    }
    return 0;
}



//最长公共子序列与最长公共子串，仅在于是不是连续
//最大优先级，左上》左》上
#define LEFTUP 0
#define LEFT 1
#define UP 2
using namespace std;
int Max(int a,int b,int c,int *max){
    //找最大时的优先级a最大
    int res=0;//res记录来自哪个单元格
    *max=a;
    if(b>*max)
    {
        *max=b;
        res=1;
    }
    if(c>*max)
    {
        *max=c;
        res=2;
    }
    return res;
}

//调用函数时将长的字符串给str1，
string LCS(const string &str1,const string &str2)
{
    int xlen=str1.size();//横向长度
    int ylen=str2.size();//纵向长度
    if(xlen==0||ylen==0)
    {
        return "";
    }
    pair<int,int>arr[ylen+1][xlen+1];//构造数组，first记录数据，second记录来源
    for(int i=0;i<=xlen;i++)//首行清0
        arr[0][1].first=0;
    for(int j=0;j<=ylen;j++)//首列清0
        arr[j][0].first=0;
    for(int i=1;i<=ylen;i++)
    {
        char s=str2.at(i-1);
        //构造时一列一列的构造，因为对应寻找要么是左要么是上，便于生成
        for(int j=1;j<=xlen;j++){
            int leftup=arr[i-1][j-1].first;
            int left=arr[i][j-1].first;
            int up=arr[i-1][j].first;
            if(str1.at(j-1)==s) //C1=C2
                leftup++;
            int max;
            arr[i][j].second=Max(leftup,left,up,&arr[i][j].first);
        }
        //矩阵构造完，可以生成
    }
    //回溯找出最长公共子序列
    stack<int> st;
    int i=ylen,j=xlen;
    //最长子序列，为两者之一
    while(i>=0 && j>=0)
    {
        if(arr[i][j].second==LEFTUP)
        {
            //如果是包括当前点，将当前点也加进去
            //其余都是不包含当前点的，不用加入
            if(arr[i][j].first==arr[i-1][j-1].first+1)
                st.push(i);
            --i;
            --j;
        }
        else if(arr[i][j].second==LEFT){
            --j;
        }
        else if(arr[i][j].second==UP){
            --i;
        }
    }
    string res="";
    while(!st.empty())
    {
        int index=st.top()-1;
        res.append(str2.substr(index,1))//拼接字符串
        st.pop();
    }
    return res;




}


//java版本
public static <E> List<E> longestCommonSubsequence(E[] s1,E[] s2){
    int[][] num=new int[s1.length+1][s2.length+1];
    for(int i=1;i<s1.length+1;i++)
    {
        for(int j=1;j<s2.length+1;j++)
        {
            if(s1[i-1].equals(s2[j-1]))
            {
                num[i][j]=num[i-1][j-1]+1;
            }
            else
            {
                num[i][j]=Max.max(num[i-1][j],num[i][j-1]);
            }
        }
    }
    System.out.println("length:"+num[s1.length][s2.length]);
    int s1position=s1.length,s2position=s2.length;
    List<E> result=new LinkedList<E>();
    while(s1position>0 && s2position>0)
    {
        if(s1[s1position-1].equals(s2[s2position-1]))
        {
            result.add(s1[s1position-1]);
            s1position--;
            s2position--;
        }
        else if(num[s1position][s2position-1]>=num[s1position-1][s2position])
        {
            s2position--;
        }
        else
        {
            s1position--;
        }
    }
    Collections.reverse(result);
    return result;


}





























