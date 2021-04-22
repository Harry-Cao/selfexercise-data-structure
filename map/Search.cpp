/**
 * 遍历
 * 
 * 深度优先/DFS
 * 广度优先/WFS
 * 
 */
#include"graph.cpp"

int visited[MAXV] = {0};

//DFS


void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d", v);
    p = G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[v]==0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

//WFS

void WFS(AdjGraph *G, int v)
{
    int w, i;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    printf("%d", v);
    visited[v] = 1;
    enQueue(v);
    while(!QueueEmpty(qu))
    {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("%d", p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}
