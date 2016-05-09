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


//寻找对应出现次数最多的

int main()
{
    int array[]={1,2,3,4,5,6};
    int len=sizeof(array)/sizeof(int);
    IsIncrease(array,len);

}