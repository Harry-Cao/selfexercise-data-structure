//汉诺塔问题

/*
首先明确一点
如果我要从汉诺塔上的X柱上面将n个圈转移到Y柱
如果n为奇数，那么就要把第1个放到Z柱，第2个放在Y柱
但是这样子其实挺麻烦的

我们可以拆分这个大问题

从X柱上面将n个圈借助Z柱转移到Y柱
相当于
先从X柱上面将(n-1)个圈借助Y柱转移到Z柱
再将第n个圈从X柱转移到Y柱Y
最后将从Z柱上面将(n-1)个圈借助X柱转移到Y柱
*/


#include<stdio.h>

void Hanoi(int n,char x,char y,char z)//n借助Y从X到Z
{
    if(n==1)
        printf("\t将第%d个从%c柱移动到%c柱\n",n,x,z);
    else
    {
        Hanoi(n - 1, 'X', 'Z', 'Y');
        printf("\t将第%d个从%c柱移动到%c柱\n",n,x,z);
        Hanoi(n - 1, 'Y', 'X', 'Z');
    }
}

int main()
{
    int n = 8;
    printf("现在开始将第%d个从%c柱移动到%c柱\n", n, 'X', 'Z');
    Hanoi(n, 'X', 'Y', 'Z');
    return 1;
}