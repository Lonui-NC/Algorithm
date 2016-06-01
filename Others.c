#include <stdio.h>
//author:Nic github 
//其他

//位运算实现除法
int div(const int x,const int y)
{
    int left_num=x;
    int result=0;
    while(left_num>=y)
    {
        int multi=1;
        while(y*multi<=(left_num>>1))
        {
            multi=multi<<1;
        }
        result+=multi;
        left_num-=y*multi;
    }
    return result;

}

//位运算实现加法
int add(int num1,int num2)
{
    if(0==num2)
    {
        return num1;
    }
    int sumTemp=num1^num2;
    int carry=(num1&num2)<<1;
    return add(sumTemp,carry);
}

int add(int num1,int num2)
{
    int sum=0;
    int num3=0;
    int num4=0;
    while((num1&num2)>0)
    {
        num3=num1^num2;
        num4=num1&num2;
        num1=num3;
        num2=num4<<1;
    }
    sum=num1^num2;
    return sum;
}

//逻辑加法实现乘法
#include <iostream>
#include <map>

using namespace std;
int multiply(int a,int b)
{
    bool neg=(b<0);
    if(b<0)
        b=-b;
    int sum=0;
    map<int,int> bit_map;
    for(int i=0;i<32;i++)
    {
        bit_map.insert(pair<int,int>(1<<i,i));
    }
    while(b>0)
    {
        int last_bit=bit_map[b&~(b-1)];
        sum+=(a<<last_bit);
        b&=b-1;
    }
    if(neg)
        sum=-sum;
    return sum;
}


