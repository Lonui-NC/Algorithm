#include <stdio.h>
//author:Nic github 
//Bubble2Sort 双向冒泡排序
void Swap(int& a,int& b)
{
    int temp;
    temp =a;
    a=b;
    b=temp;
}

void Bubble2Sort(int array[],int length)
{
    int left=1;
    int right=length-1;
    int t;
    do
    {
        //正向部分
        for(int i=right;i>=left;i--)
        {
            if(array[i]<array[i-1])
            {
                Swap(array[i],array[i-1]);
                t=i;
            }
        }
        left=t+1;
        for (int i=left;i<right+1;i++)
        {
            if (array[i]<array[i-1])
            {
                Swap(array[i],array[i-1]);
                t=i;
            }

        }
        right=t-1;

    }while(left<=right);


}

int main()
{
    int i=0;
    int a[]={5,4,9,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    Bubble2Sort(a,len);
    for(i=0;i<len;i++)
    {
        printf("%d\n",a[i] );
    }
    printf("\n");
    return 0;
}
