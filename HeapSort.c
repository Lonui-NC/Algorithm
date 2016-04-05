#include <stdio.h>
//author:Nic github 
//ShellSort:希尔排序
void AdjustMinHeap(int *a,int pos,int len)
{
    //将对应转为最小堆
    int temp;
    int child;
    for (temp=a[pos];2*pos+1<=len;pos=child)
    {
        child=2*pos+1;
        //判断该树的左右节点大小，取其中最小的来比较
        if(child<len&& a[child]>a[child+1])
            child++;
        //正常顺序为此时判断
        //调整令a[2*pos+1]>a[pos]
        //令其为最小堆
        //其实只会调用有限次，因为默认会从递归角度来看下面是都排好的
        //当且仅当当前节点不是最小值时将下面节点的值替换上来，然后对剩下的子节点（子堆）进行二次比较
        //否则默认比较已完成，只取最后的交换1即可
        if(a[child]<temp)
            a[pos]=a[child];
        else
            break;

    }
    a[pos]=temp;
}

void Swap(int& a,int& b)
{
    int temp;
    temp =a;
    a=b;
    b=temp;
}

void MyMinHeapSort(int *array,int len)
{
    int i;
    for(i=len/2-1;i>=0;i--)
    {
        //按节点顺序，从最大的节点处开始排列，即从下往上排找最小的放到下面
        AdjustMinHeap(array,i,len-1);
    }
    for(i=len-1;i>=0;i--)
    {
        Swap(array[0],array[i]);
        //以后因为前面堆排序保证了底层的堆都是正确有顺序的
        //所以只用构建一次堆，判断顶部节点与下面节点的位置即可
        AdjustMinHeap(array,0,i-1);
    }


}

void PrintArray(int *a,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
}

int main()
{
    int i=0;
    int a[]={5,4,9,25,16,8,6,7,12};
    int len=sizeof(a)/sizeof(a[0]);
    MyMinHeapSort(array,len);
    PrintArray(array,length);   
    //printf("\n");
    return 0;
}