#include <stdio.h>
//author:Nic github 
//MergeSort :归并排序
void Merge(int array[],int p,int q,int r)
{
    int i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    int *L=new int[n1];
    int *R=new int[n2];
    //存放左半边元素，从p到q的元素
    //r为元素的总长度，此时讲数组分为的两部分，下标分别是
    //p~q,q+1~r
    for(i=0,k=p;i<n1;i++,k++)
    {
        L[i]=array[k];
    }
    for(i=0,k=q+1;i<n2;i++,k++)
    {
        R[i]=array[k];
    }
    //左右初步合并
    for(k=p,i=0,j=0;i<n1 && j<n2;k++)
    {
        if(L[i]>R[j])
        {
            array[k]=R[j];
            j++;
        }
        else
        {
            array[k]=L[i];
            i++;
        }
    }
    //判断那个数组还有末尾未合并加进去
    if(i<n1)
    {
        for (i; i < n1; ++i)
        {
            array[k]=L[i];
            k++;
        }
    }
    if(j<n2)
    {
        for(j;j<n2;j++)
        {
            array[k]=R[j];
            ++k;
        }
    }
}

void MergeSort(int array[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(array,p,q);
        MergeSort(array,q+1,r);
        Merge(array,p,q,r);
    }
}

int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    MergeSort(a,0,len-1);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );

    }
    printf("\n");
    return 0;
}