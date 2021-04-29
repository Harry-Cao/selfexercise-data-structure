#include"back-linklist.cpp"
//链表的逆序
//把大问题拆分成小问题

/**why
 * 首先 理清大问题是什么
 * 对于一个链表L
 * L->next->next=L;
 * L->next=NULL;
 * 但是，如果L是头节点的话
 * 我们怎么理解
 * 我们需要的是将头节点直接指向现在的尾节点
 * 那我们得在小操作中不处理头节点
 * 然后在最后处理到尾节点之后再处理头节点的问题
 * 然后，尾节点怎么处理
 * 也就是说，如果L->next->next=NULL时我们就得退出了
 * 
 * 或者
 * 我们也可以先找到尾节点
 * 然后逆着来
 * 先把头节点连上
 * 但是
 * 这样的话
 * 就会直接断掉
 * */

//还有一个问题，如果顺着来，直接L->next->next改了，如果逆序在递归之前，没办法找到下一个了

//所以：要先递归，然后再逆序操作

void Reverse(LinkNode * p, LinkNode *&L)
{
    if(p->next==NULL)
    {
        L->next = p;    //解决头节点问题
        return;
    }
    Reverse(p->next, L);
    p->next->next = p;
    printf("\t %c的下一个为%c\n", p->next->data, p->data);
    p->next = NULL;
    printf("\t 置%c的下一个为空\n", p->data);
}


//其实我最后的效果就是从尾节点来开始处理，但是这样又能保证不会中间断掉

//用来看效果的主函数

int main()
{
    LinkNode *L;
    char a[] = "123";
    int n = 3;
    CreateListR(L, a, n);
    printf("L: ");
    DispList(L);
    printf("reversed L:\n");
    Reverse(L->next,L);
    DispList(L);
    DestroyList(L);
    return 1;
}