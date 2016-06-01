#include <stdio.h>
//author:Nic github 
//数组相关

//递归判断实现递增
bool IsIncrease(int a[],int n)
{
    if(n==1)
        return true;
    else 
        //若不是，则递归进行判断
        return (a[n-1]>=a[n-2]) && IsIncrease(a,n-1);
}

//非递归算法实现对应二分查找
int BinarySearch(int array[],int len,int findData)
{
    if(array==NULL || len<=0)
        return -1;
    int start=0;
    int end=len-1;
    int mid=0;
    while(start<end)
    {   
        mid=start+(end-start)/2;
        if(array[mid]==findData)
        {
            return mid;
        }
        else if(findData<array[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

//递归方法实现二分查找
int BinarySerachRec(int array[],int start,int end,int findData)
{
    if(start>end)
        return -1;
    int mid=start+(end-start)/2;
    if(array[mid]==findData)
    {
        return mid;
    }
    else if(findData<array[mid])
    {
        end=mid-1;
    }
    else
    {
        start=mid+1;
    }
    return BinarySearchRec(array,start,end,findData);
}

//查找对应出现多次在数组中的数字
int BinarySearchNum(int *a,int length,int num,bool isLeft)
{
    //定义最左与最右的数据分析
    int left=0,right=length-1;
    int last=-1;
    int mid=(left+right)/2;
    while(left<right)
    {
        //寻找对应的边界值
        if(a[mid]>num)
        {
            left=mid+1;
        }
        else if(a[mid]<num)
        {
            right=mid-1;
        }
        else
        {
            last=mid;
            //这两个是判断对应是在最左的一个还是最右的一个
            if(isLeft)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
    }
    return last;
}
//最后返回的是对应的个数
//设置了两种可能性进行判断，即中间的元素是最左边的和中间的元素是最右边的，只有这两种可能
//要保证对应有序才可以
//main函数中对应
// int Lower=BinarySearchNum(array,sizeof(array)/sizeof(array[0]),3,true);
//int Upper=BinarySearchNum(array,sizeof(array)/sizeof(array[0]),3,false);
//int count=Upper-Lower+1;//返回的就是最左与最右的下标

//两个有序数组之间的遍历
int mixed(int array1[],int array2[],int n1,int n2,int *mixed)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(array1[i]==array2[j])
        {
            mixed[k++]=array1[i];
            i++;
            j++;
        }
        else if(array1[i]>array2[j])
        {
            mixed[k++]=array2[j];
            j++;
        }
        else
        {
            mixed[k++]=array1[i];
            i++;
        }
    }
    return k;
}


//寻找对应出现次数最多的数组元素
//首先遍历元素得到对应最大的index
//然后用空间换时间
//count[array[i]]++;
int GetMaxNum(int *arr,int len,int &num)
{
    int index=arr[0];
    int i;
    for(i=0;i<len;i++)
    {
        if(arr[i]>index)
        {
            index=arr[i];
            num=i;
        }
    }
    return index;
}

//如何获取对应数组中出现次数超过一半的数
//排序后取，对应点中间(n+1)/2一定是中间的数
int FindMostApperse(int *num,int len)
{
    int candidate=0;
    int count=0;
    //for(int i=0;i<len)
    int i,A,B;
    int a[3]={1,2,3};
    A=a[1];
    B=0;
    for(i=0;i<10;i++)
    {
        if(B==0)
        {
            A=a[i];
            B=1;
        }
        else if(A==a[i])
            B++;
        else if(A!=a[i])
        {
            B--;
        }

    }
}

//找出对应的数组中唯一重复的元素
//分别为1~N-1个数字
//可以异或一次，所有相同的异或后为0
//不相同的异或为1 ，不再改变
void xor_findDup(int *a,int N)
{
    int tmp1=0;
    int tmp2=0;
    for(int i=0;i<N-1;++i)
    {
        tmp1+=(i+1);
        tmp2+=a[i];
    }
    tmp2+=a[N-1];
    int result=tmp2-tmp1;

} 

//位图法
//设置标志位
void xor_findDup(int *arr,int NUM)
{
    int *arrayflag=(int *)malloc(NUM*sizeof(int));
    int i=1;
    while(i<NUM)
    {
        arrayflag[i]=false;
        i++;
    }
    for(int i=0;i<NUM;i++)
    {
        if(arrayflag[arr[i]]==false)
            arrayflag[arr[i]]=true;
        else
        {
            //printf("%s\n", );
        }
    }
}

//若进行变形，对应有多个数可能会重复，则采用以下几种方法
//1.位图法，同上设置标志位，判断是否出现过，然后输出
//2.数组排序法，对数组进行计数排序，然后扫描
//3.采用Hash法

int FindInteger(int array[],int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        if(array[i]>0)
        {
            if(array[array[i]]>0)
            {
                array[array[i]]=-array[array[i]];
            }
            else
            {
                return -array[array[i]];
            }
        }
        else
        {
            if(array[-array[i]]>0)
            {
                array[array[i]]=-array[array[i]];
            }
            else
            {
                return -array[-array[i]];
            }
        }
    }
}


//判断单链表中是否存在环
//快慢指针法判断对应是否有环
//1.对于问题1，使用追赶的方法，设定两个指针slow、fast，
//从头指针开始，每次分别前进1步、2步。如存在环，则两者相遇；如不存在环，fast遇到NULL退出。
// 2.对于问题2，记录下问题1的碰撞点p，slow、fast从该点开始，再次碰撞所走过的操作数就是环的长度s。
//3.有定理：碰撞点p到连接点的距离=头指针到连接点的距离，
//碰撞点到连接点的距离=头指针到连接点的距离
// 因此，分别从碰撞点、头指针开始走，相遇的那个点就是连接点。(证明在后面附注)
// 4.已经求出连接点距离头指针的长度，加上问题2中求出的环的长度，二者之和就是带环单链表的长度
int FindInteger(int array[],int n)
{
    int x,y;
    x=y=0;
    do
    {
        x=array[array[x]];//x一次走两步
        y=array[y];//y一次走一步
    }while(x!=y);//表明这时候走进了环里
    x=0;
    do
    {
        x=array[x];
        y=array[y];
    }while(x!=y);
    return x;
}


//从一连串的数字中判断是否有相邻的数字
bool IsContinuous(int * a,int n)
{
    int min=-1,max=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            if(min>a[i] || -1==min)
            {
                min=a[i];
            }
            if(max<a[i] || -1==max)
            {
                max=a[-i];
            }
        }
    }
    if(max-min>n-1)
    {
        return false;
    }
    else
        return true;

}



//寻找对应出现奇数次的元素
//采用异或方法
int FIndElementWithOddCount(int *a,int n)
{
    int r=a[0];
    for (int i = 0; i < n; ++i)
    {
        /* code */
        r^=a[i];
    }
    return r;
}

//引申求2个出现奇数次的元素
void FindElement(int a[],int length)
{
    int s=0;
    int i;
    int k=0;
    for(i=0;i<length;i++)
    {
        s=s^a[i];
    }
    int s1=s;
    int s2=s;
    //求出a与b不同的那一位，分割点，用于判断
    //与前面的对应，表示对应最后一位1
    while(!(s1&1))
    {
        s1=s1>>1;
        k++;//k表示位数
    }
    for(i=0;i<length;i++)
    {
        //表明对应位上也是1
        if(a[i]>>k&1)
        {
            s=s^a[i];
        }

    }
    // printf()
}

//找出数组中满足条件的数对
//双指针法
void FixedSum(int *a,int n,int d)
{
    for(int i=0,j=n-1;i<n &&j>=0 && i<j)
    {
        if(a[i]+a[j]<d)
        {
            ++i;
        }
        else if(a[i]+a[j]==d)
        {
            printf("%d,%d\n",a[i],a[j]);
            ++i;
            --j;
        }
        else
            --j;
    }
}

//若有两个数组，采用排序+线性扫描法
void print_pairs_with_sum(int A[],int B[],int m,int n,int sum)
{
    sort(A,A+m);
    sort(B,B+n);
    int p,q;
    p=0;
    q=n-1;
    while(p<m && q>=0)
    {
        if(A[p]+B[q]==sum)
        {
            cout<<"("<<A[p]<<","<<B[q]<<")"<<endl
            p++;
            q--;
        }
        else if(A[p]+B[q]>sum)
        {
            q--;
        }
        else
        {
            p++;
        }
    }
}

//采用HashTable法，寻找HashTable中小的那一个数字
void print_pairs_with_sum2(int A[],int B[],int m,int n,int sum)
{
    map<int,bool> hash_table;
    int *psmaller=A;
    int *pbigger=B;
    int nsmaller=(m>=n) ? n:m;
    int nbigger=(m>=n) ? m:n;
    if(m>n)
    {
        psmaller=B;
        pbigger=A;
    }
    for(int i=0;i<nsmaller;i++)
    {
        hash_table.insert(pair<int,bool>(psmaller[i],true));
    }
    for(int i=0;i<nbigger;i++)
    {
        if(hash_table.find(sum-pbigger[i]!=hash_table.end()))
        {
            cout<<"("<<pbigger[i]<<","<<sum-pbigger[i]<<")"<<endl;
        }
    }
}

int main()
{
    int array[]={1,2,3,4,5,6};
    int len=sizeof(array)/sizeof(int);
    IsIncrease(array,len);

}