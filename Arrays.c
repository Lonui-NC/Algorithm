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


//如何找出数列中的缺失的数
//将所有元素相加，然后再减一次就可以

//如何判断数组中是否存在重复元素
//先进行排序，然后进行比较相邻元素是否相同
int comp(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}

int isArrayRepeat(int *a,int n)
{
    int i=0;
    if(!a || n<1)
    {
        return -1;
    }
    qsort(a,n,sizeof(int),comp);
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
            return 1;
    }
    return 0;
}

//遍历数组，将下标值移动到对应的元素中，判断是否发生了冲突
int isArrayRepeat(int *a,int n)
{
    int j=-1;
    for(int i=-;i<n;i++)
    {
        j=a[i];
        if(i==j-1)//此时不用移动
        {
            continue;
        }
        if(a[i]==a[j-1])
        {
            //当前数字为a[i]
            //需要移动的位置为j-1
            //若此时对应j-1的数与其本身相等，则表明两者对应的值是一样的
            return 1;
        }
        a[i]=a[j-1];
        a[j-1]=j;
        i--;
    }
    return 0;

}


//如何重新排列数组使得数组左边为奇数，右边为偶数
//类似快排，两个指针，首尾指针法
void Swap(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

void ReverseArray(int arr[],int len)
{
    int begin=0;
    int end=len-1;
    while(begin<end)
    {
        while(arr[begin]%2==1 && end>begin)
        {
            ++begin;
        }
        while(arr[end]%2==0 && end>begin)
        {
            --end;
        }
        Swap(arr[begin],arr[end]);
    }
}


//如何把整型数组中重复的数字去掉
int int_cmp(const void *a,const void *b)
{
    const int *ia=(const int *)a;
    const int *ib=(const int *)b;
    return *ia-*ib;
}

int unique(int *array,int number)
{
    int k=0;
    //k表示下标，依次往前递增，然后通过数目删除
    for(int i=0;i<number;i++)
    {
        if(array[k]!=array[i])
        {
            array[k+1]=array[i];
            k++;
        }
    }
    return k+1;
}

int Unique_QuickSortMethod(int *arr,int elements)
{
    qsort(arr,elements,sizeof(int),int_cmp);
    return unique(arr,elements);
}


//寻找数组中第k大的数
const int MIN=-32767;
int FindSecMax(int data[],int count)
{
    int maxnumber=data[0];
    int sec_max=MIN;
    for(int i=0;i<count;i++)
    {
        if(data[i]>maxnumber)
        {
            sec_max=maxnumber;
            maxnumber=data[i];
        }
        else
        {
            if(data[i]>sec_max)
            {
                sec_max=data[i];
            }
        }
    }
    return sec_max;
}

void GetMaxAndMin(int *arr,int len,int& Max,int& min)
{
    Max=arr[0];
    Min=arr[0];
    for(int i=1;i<len-1;i=i+2)
    {
        if(NULL==arr[i+1])
        {
            if(arr[i]>Max)
                Max=arr[i];
            if(arr[i]<Min)
                Min=arr[i];
        }
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>Max)
                Max=arr[i];
            if(arr[i]<Min)
                Min=arr[i];
        }
        else
        {
            if(arr[i+1]>Max)
                Max=arr[i+1]
            if(arr[i]<Min)
                Min=arr[i];
        }
    }

}

//分治法
void GetMaxMin(int a[],int low,int high,int &max,int &min)
{
    int k,max1,min1,max2,min2;
    if(high-low==1 || high-low==0)
    {
        a[low]>a[high]?(max=a[low],min=a[high]):(max=a[high],min=a[low]);
    }
    else
    {
        k=(low+high)/2;
        GetMaxMin(a,low,k,max1,min1);
        GetMaxMin(a,k+1,high,max2,min2);
        max=max1>max2?max1:max2;
        min=min1>min2?min1:min2;
    }
}


//将数组的后面m个数移动到前面m个数
//前m个数颠倒
//后面n-m个数颠倒
//将n个数颠倒
void func(int *start,int *end)
{
    //将数字前后颠倒
    while(start<end)
    {
        int temp=*start;
        *start=*end;
        *end=temp;
        ++start;
        --end;
    }
}


void f(int n,int m,int *numbers)
{
    func(numbers,numbers+m-1);
    func(numbers+m,numbers+n-1);
    func(numbers,numbers+n-1);
}


//构造序列的前n个元素
void Generate(int a,int b,int N,int *Q)
{
    int tmpA,tmpB;
    int j=1;
    int j=1;
    for(int k=0;k<N;k++)
    {
        tmpA=a*i;
        tmpB=b*j;
        if(tmpA<=tmpB)
        {
            Q[k]=tmpA;
            i++;
        }
        else
        {
            Q[k]=tmpB;
            j++;
        }
    }

}

//异或找出数组中只出现一次的数组
int findNotDouble(int a[],int n)
{
    int result=a[0];
    int i;
    for(i=1;i<n;i++)
    {
        result^=a[i];
    }
    return result;
}


//如何找出数组中只出现一次的2个数字
//两个数字至少有一位不同，为1
void findOnce(int data[],int n,int &num1,int &num2)
{
    if(n<5)
        return;
    int r1=0;
    for(int i=0;i<n;i++)
    {
        r1^=data[i];
    }
    int bitNum=0;
    while(!(r1&0x1))
    {
        r1>>=1;
        ++bitNum;
    }
    int flag=(1<<bitNum);
    num1=0;
    num2=0;
    for(int j=0;j<n;j++)
    {
        if(data[j]&flag)
            num1^=data[j];
        else
            num2^=data[j];
    }
}


//最大子序列的方法
//只要前n项的和还没有小于0，那么就向后扩展
//否则丢弃之前的子序列，开始新的序列！


//最长递增序列

// 比如arr={1,5,8,2,3,4}的最长递增子序列是1,2,3,4
// 动态规划的思想，
// 考虑{arr[0],...,arr[i]}的最长递增子序列时
// 需要找到所有比arr[i]小的arr[j]，且j<i，
// 结果应该是所有{arr[0],...,arr[j]}的最长递增子序列中最长的那一个再加1。
// 即我们需要一个辅助的数组aid_arr，aid_arr[i]的值是{arr[0],...,arr[i]}的最长递增子序列的长度，
// aid_arr[0]=1。

//最长递增子序列从头开始
int main()
{
    const int len=14;
    int arr[len]={1,9,3,8,11,4,5,6,4,1,9,7,1,7};
    vector<int> vec(&arr[0],&arr[len]);
    vector<int> monoseqlen(len,1);//初始化，len个为1
    vector<int> preindex(len,-1);
    int maxmonoseqlen=-1;
    int maxmonoindex=-1;

    for(int i=1;i<len;i++)
    {
        int curr=vec[i];//第一个数
        for(int j=0;j<i;j++)
        {
            if(vec[j]<vec[i])
            {
                //对应的monosqlen是相对应的长度值，表示在
                //当前j的位置上monoseqlen是当前j的最大递增子序列
                //所以加1表明现在的最大递增是多少
                //所以这里要从头开始
                int msl=monoseqlen[j]+1;
                if(msl>monoseqlen[i])
                {
                    monoseqlen[i]=msl;
                    preindex[i]=j;//表明在i对应位置最大子序列前一个是j
                }
            }
        }

        for(int i=0;i<len;i++)
        {
            if(monoseqlen[i]>maxmonoseqlen)
            {
                //取最大值!
                maxmonoseqlen=monoseqlen[i];
                maxmonoindex=i;
            }
        }

        stack<int> st;
        //取当前点的序列值，依次找前一点序列值，逆向输出！
        while(maxmonoindex>=0)
        {
            st.push(vec[maxmonoindex]);
            maxmonoindex=preindex[maxmonoindex];
        }

        vector<int> rect;
        while(!st.empty()){
            rect.push_back(st.top());
            st.pop();
        }

        vector<int>::iterator itr=rect.begin();
        while(itr!=rect.end()){
            count<<*itr++<<"\t";
        }
        cout<<endl;
        return 0;

    }

}


//最长公共子串LCS
// 个二维矩阵怎么构造呢？直接举个例子吧："bab"和"caba"(当然我们现在一眼就可以看出来最长公共子串是"ba"或"ab")

// 　　 b　　a　　b

// c　　0　　0　　0

// a　　0　　1　　0

// b　　1　　0　　1

// a　　0　　1　　0

//求对应最长元素的子串，，构造上述二维矩阵，然后让对角线上为其前一行
//加1即可
//  b　　a　　b

// c　　0　　0　　0

// a　　0　　1　　0

// b　　1　　0　　2

// a　　0　　2　　0

//str1是横向，str2是纵向
const string LCS(const string& str1,const string& str2)
{
    //用一维数组横向比较保存
    int xlen=str1.size();//横向长度
    vector<int> tmp(xlen);//保存矩阵的上一行
    //arr(tmp) 表明对应为tmp的一个副本
    vector<int> arr(tmp);//当前行
    int ylen=str2.size();//纵向长度
    int maxele=0;//矩阵中出现的最大值
    int pos=0;//矩阵原酸最大值的列数
    for(int i=0;i<ylen;i++)
    {
        string s=str2.substr(i,1);
        arr.assign(xlen,0);//数组清0
        //取其中每一个字符进行比较
        for(int j=0;j<xlen;j++)
        {
            //单个字符对应
            if(str1.compare(j,1,s)==0)
            {
                if(j==0)
                    arr[j]=1;//首行字符为1
                else
                    arr[j]=tmp[j-1]+1;//否则为上一行字符加1
                if(arr[j]>maxele)
                {
                    maxele=arr[j];
                    pos=j;
                }
            }
        }

        tmp.assign(arr.beign(),arr.end());
    }
    string res=str1.substr(pos-maxele+1,maxele);
    return res;

}








































int main()
{
    int array[]={1,2,3,4,5,6};
    int len=sizeof(array)/sizeof(int);
    IsIncrease(array,len);

}