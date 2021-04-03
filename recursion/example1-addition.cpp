#include <stdio.h>

int addition(int n)
{
    if(n==1)
        return 1;
    else
        return n + addition(n - 1);
}

int main()
{
    int n = 100;
    printf("%d\n", addition(n));
}