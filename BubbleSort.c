#include <stdio.h>
//author:Nic github 
//SelectSort 冒泡排序
void Swap(int& a,int& b)
{
    int temp;
    temp =a;
    a=b;
    b=temp;
}
void BubbleSort(int array[],int len)
{
    int i,j;
    for(i=0;i<len-1;++i)
    {
        for(j=len-1;j>i;--j)
        {
            if(array[j]<array[j-1])
            {
                Swap(array[j],array[j-1]);
            }
        }
    }
}
int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    BubbleSort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );
    }
    printf("\n");
    return 0;
}
