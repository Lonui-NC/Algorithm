#include <stdio.h>
//author:Nic github 
//SelectSort 选择排序
void SelectSort(int *a,int n)
{
    int i;
    int j;
    int temp=0;
    int flag=0;
    for (i=0;i<n-1;i++)
    {
        temp=a[i];
        flag=i;
        for (j=i+1;j<n;j++)
        {
            if (a[j]<temp)
            {
                temp=a[j];
                flag=j;
            }


        }
        if(flag!=i)
        {
            a[flag]=a[i];
            a[i]=temp;
        }
    }

}

int main()
{
    int i=0;
    int a[]={1,12,3,11,26,4,5,6,7};
    int len=sizeof(a)/sizeof(a[0]);
    SelectSort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
    return 0;
}