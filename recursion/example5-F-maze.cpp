#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define M 8
#define N 8

int mg[M + 2][N + 2] =
{   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

typedef struct
{
    int i;
    int j;
} Box;

typedef struct
{
    Box data[MaxSize];
    int length;
} PathType;

//迷宫问题事实上是从(xi,yi)到(x,y)找到一条路径，储存在path数组当中
//也就是函数mypath(xi,yi,x,y,path)
//当走了一步之后，下一步函数就变成了mypath(xi+1,yi+1,x,y,path)

/**那在反复调用这个函数的时候，所有的判断分支操作都得在这个函数中进行
 * 首先，我们要明确到底有哪些操作与判断要进行
 * 
 * 首先是要判断是否为终点，也就是(xi==x&&yi==y)
 *      如果是的话就要去直接输出path数组中的值，也就是复现路径
 * 
 * 其次要判断(xi,yi)这个点四周有没有点可以走
 *      如果可以走的话就继续函数
 *      如果不可以走的话就要退出
 * 
 * 最后就是要考虑如果点(xi,yi)不能走的话如何处理
 * 也就是说，这个时候中间调用的函数已经结束，回到了上一个函数继续进行
 * 
 * ！！也就是说  这是就要退回上一步走的点重新走！！！
 * */

int mypath(int xi,int yi,int x,int y,PathType path)
{
    int i = 0, j = 0, di, k;
    if(xi==x&&yi==y)
    {
        //找到出口，输出数组
        path.data[path.length].i = xi;
        path.data[path.length].j = yi;
        path.length++;
        printf("the path of the maze:\n");
        for (k = 0; k < path.length; k++)
            printf("\t(%d,%d)", path.data[k].i, path.data[k].j);
        printf("\n");
    }
    else
    {
        if(mg[xi][yi]!=0)
            return NULL;
        else
        {
            di = 0;
            while(di<4)
            {
                path.data[path.length].i = xi;
                path.data[path.length].j = yi;
                path.length++;
                switch(di)  //优先右边
                {
                    case 0: //右边
                        i = xi;
                        j = yi + 1;
                        break; 
                    case 1: //下边
                        i = xi + 1;
                        j = yi;
                        break;
                    case 2: //左边
                        i = xi - 1;
                        j = yi;
                        break;
                    case 3: //上边
                        i = xi;
                        j = yi - 1;
                        break;
                }
                mg[xi][yi] = -1;
                mypath(i, j, x, y, path);
                //下面就是如果上面的函数退出了
                mg[xi][yi] = 0;
                path.length--;
                di++;
            }
        }
    }

}

int main()
{
    PathType path;
    path.length = 0;
    mypath(1, 1, M, N, path);

    return 1;
}