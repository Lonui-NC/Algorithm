#include <stdio.h>
//author:Nic github 
//QuickSort:快排

void Sort(int array[],int low,int high)
{
    int i,j;
    int index;
    if(low>=high)
    {
        return;
    }
    i=low;
    j=high;
    //此处Index用于存放标准值
    index=array[i];
    while(i<j)
    {
        while(i<j && array[j]>=index)
        {
            j--;
        }
        //此处为找到右侧第一个小于index的值，交换赋值
        if(i<j)
        {
            array[i]=array[j];
        }
        //开始从左往右找
        i++;
        while(i<j && array[i]<=index)
        {
            i++;
        }
        if (i<j)
        {
            array[j]=array[i];
        }
        j--;
        //此时j之后的均为整齐的，i++之前为整齐的，再在中间找
    }
    array[i]=index;
    Sort(array,low,i-1);
    Sort(array,i+1,high);

}

void QuickSort(int array[],int len)
{
    Sort(array,0,len-1);
}

int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    QuickSort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );

    }
    printf("\n");
    return 0;
}