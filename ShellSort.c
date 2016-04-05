#include <stdio.h>
//author:Nic github 
//ShellSort:希尔排序
void ShellSort(int array[],int length)
{
    int i,j;
    int h;
    int temp;
    for (h=length/2;h>0;h=h/2)
    {
        for(i=h;i<length;i++)
        {
            temp=array[i];
            for(j=i-h;j>=0;j-=h)
            {
                if (temp<array[j])
                {
                    /* code */
                    array[j+h]=array[j];
                }
                else
                    break;
                    //边界肯定是对齐的，每次只取值了中间部分进行比较
                    //根据前述，每次最多肯定只比较1次（有比较两次的机会说明有了偶数个，可以拆分成两次）
                    //此时对应为最多的，相邻中间为
            }
            //最后一步保证换过后最小的在最左边
            array[j+h]=temp;
        }
    }
}

int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    ShellSort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );

    }
    printf("\n");
    return 0;
}