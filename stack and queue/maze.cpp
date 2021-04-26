/**迷宫问题
 * 迷宫事实上是一个数组
 * 如果是3x3的迷宫，数组就是[5][5](上下左右各需要一个边框)
 * 0表示可以走；1表示不能走
 * */

//迷宫问题在recursion文件夹中也有一个版本'example5-F-maze.cpp'

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
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
    int di;
} Box;

typedef struct
{
    Box data[MaxSize];
    int top;
} StType;

//typedef StType SqStack;
//typedef Box ElemType;

void InitStack(StType *&s)     //初始化顺序栈
{
    s=(StType *)malloc(sizeof(StType));
	s->top=-1;
} 

void DestroyStack(StType *&s) //销毁顺序栈
{
	free(s);
}

bool StackEmpty(StType *s)	   //判断栈空否
{
	return(s->top==-1);
}

bool Push(StType *&s,Box e)	 //进栈
{
	if (s->top==MaxSize-1)   //栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Pop(StType *&s,Box &e)	 //出栈
{
	if (s->top==-1)					 //栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
} 

bool GetTop(StType *s,Box &e)	 //取栈顶元素
{
	if (s->top==-1) 			//栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];
	return true;
}

bool FindAWay(int xi, int yi, int x, int y) //获取一条路径
{
    Box path[MaxSize], e;					//path数组来储存路径 
    int i, j, di, i1, j1, k;
    bool find;
    StType *st;								//用栈来保存走过的点，这样可以使走进死胡同时能够回退 
    InitStack(st); 
    e.i = xi;
    e.j = yi;
    e.di = -1;
    Push(st,e); 							//最初的入口入栈 
    mg[xi][yi] = -1;						//防止之后重新走到这个点 
    while(!StackEmpty(st)) 
    {
        GetTop(st, e);  					//获取栈顶元素，并未取出来
        i = e.i;
        j = e.j;
        di = e.di;
        if(i==x&&j==y)						//如果栈顶元素是终点——显示完整路径 
        {
            printf("\n\nfind a path:\n");
            k = 0;
            while(!StackEmpty(st))
            {
                Pop(st, e);					//依次取出栈中的元素放进path数组（path中的元素是逆序的） 
                path[k++] = e;
            }
            while(k>=1)
            {
                k--;						//将path数组逆序输出 
                printf("\t(%d,%d)", path[k].i, path[k].j);
                if ((k + 2) % 5 == 0)		//每输出五个方块就换一行 
                    printf("\n");
            }
            printf("\n");
            DestroyStack(st);
            return true;
        }
        find = false;
        while (di < 4 && !find)
        {
            di++;
            switch(di)  //优先右边
            {
                case 0: //右边
                    i1 = i;
                    j1 = j + 1;
                    break; 
                case 1: //下边
                    i1 = i + 1;
                    j1 = j;
                    break;
                case 2: //左边
                    i1 = i - 1;
                    j1 = j;
                    break;
                case 3: //上边
                    i1 = i;
                    j1 = j - 1;
                    break;
            }
            if(mg[i1][j1]==0)
                find = true;
        }
        if(find)							   //如果找到了一个正确的方向-即下一个点 
        {
            st->data[st->top].di = di;		   //改变栈顶的di值 
            e.i = i1;
            e.j = j1;
            e.di = -1;
            Push(st, e);					   //入栈下一个点 
            mg[i1][j1] = -1;
        }
        else
        {
            Pop(st, e);						   //退栈--返回上一个点重新来 
            mg[e.i][e.j] = -1;
        }
    }
    DestroyStack(st);
    return false;
}

int main()
{
    FindAWay(1, 1, M, N);
    //if(!FindAWay(1,1,M,N))
        //printf("\nNo Path!\n");
    return 1;
}
