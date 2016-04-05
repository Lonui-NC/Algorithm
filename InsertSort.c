#include <stdio.h>
//author:Nic github 
//SelectSort 插入排序
void InsertSort(int par_array[],int array_size)
{
    int i,j;
    int temp;
    for(i=1;i<array_size;i++)
    {
        temp=par_array[i];
        for (j=i-1;j>=0;j--)
        {
            if (temp<par_array[j])
            {
                par_array[j+1]=par_array[j];

            }
            else 
                break;

        }
        par_array[j+1]=temp;
    }
}

int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    InsertSort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );

    }
    printf("\n");
    return 0;
}