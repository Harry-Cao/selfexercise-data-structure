/**
 * linked-list
 * 用另一种方式逆序链表
 */ 

#include "background-linklist.cpp"

void Reverse(LinkNode *p, LinkNode *&L);

int main()
{
    LinkNode *L;
    char a[] = "12";
    int n = 2;
    CreateListR(L, a, n);
    printf("L: ");
    DispList(L);
    printf("reversed L:");
    Reverse(L->next,L);
    DispList(L);
    DestroyList(L);
    return 1;
}


void Reverse(LinkNode *p, LinkNode *&L)
{
    if(p->next==NULL)
    {
        L->next = p;
        return;
    }
    Reverse(p->next, L);
    p->next->next = p;
    p->next = NULL;
}

//👇解释if判断语句的作用(尤其是return这个判断语句是怎么用的)

/*
void Reverse(LinkNode *p, LinkNode *&L)
{
    if(p->next==NULL)//第一次判断p是否为尾节点
    {
        L->next = p;
        return;
    }

    //Reverse(p->next, L);就相当于套娃

    if(p->next->next==NULL)//开始新一次的判断p->next是否到了尾节点
    {
        L->next = p->next;//若是，就把原来的尾节点（反转后成了头节点）指向p->next
        return;

        //warning!此处的return是跳出Reverse(p->next, L)这个函数!

    }
    Reverse(p->next->next, L);
    p->next->next->next = p;
    p->next->next = NULL;


    p->next->next = p;
    p->next = NULL;
}

 */

//下面👇解释执行操作在自我调用之后的作用效果

/*
我们换一个主函数的赋值：
    char a[] = "123";
    int n = 3;
    CreateListR(L, a, n);
这时候，我们在Reverse中的判断语句省略，
因为相当于第三次调用这个函数的时候判断语句直接return了，
相应的操作并没有执行

void Reverse(LinkNode *p, LinkNode *&L)
{ //p=L->next;//相当于头节点指向的第一个节点

    //Reverse(p->next, L);
    {

        //Reverse(p->next->next, L);
        {
            if(p->next==NULL)//输入的p->next->next已经是最后一个节点了
            {
                L->next = p;
                return;//这个函数就终止了
            }
        }
        //输入的p其实是第二个节点了
        p->next->next//第三个节点next指向的// = p;
        p->next = NULL;
    }
    //输入的p其实是第一个节点了
    p->next->next//第二个节点next指向的在上面已经变成NULL// = p;
    p->next = NULL;//第一个节点变成了尾节点（next指向的值为空//
}

*/

/*
这时候应该能大致有一个印象了
相应的操作在自身调用之后的话
事实上是从最后一次调用的函数那里开始操作

相当于一个洋葱，皮是从最里面开始拨的，从里到外

上面链表倒序就是这个意思
是从尾节点开始，尾节点判断结束
然后是倒数第二个节点，
    使得尾节点指向的值的next指向倒数第二个节点
*/