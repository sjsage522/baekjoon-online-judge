#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 102
#define MAX_QUEUE_SIZE 10404
int visited[MAX_VERTICES][MAX_VERTICES] = {0};
int res = 0;
int n, m;
typedef struct _GraphType {
    int n;
    int location[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType *g) {
    int r, c;
    for(r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->location[r][c] = 0;
}

typedef struct {
    int r,c;
} element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType *q) {
    q->front = q->rear = -1;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

void enqueue(QueueType *q, element item) {
    q->rear += 1;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    q->front += 1;
    return q->data[q->front];
}

void bfs(GraphType *g, element rc) {
    QueueType q;
    element tmp;
    init_queue(&q);
    visited[rc.r][rc.c] = 1;
    enqueue(&q, rc);
    while(!is_empty(&q)) {
        rc = dequeue(&q);
        if(rc.r <= n && rc.c <= m && rc.r > 0 && rc.c > 0) {
            if(g->location[rc.r-1][rc.c] && !visited[rc.r-1][rc.c]) {
                tmp.r = rc.r - 1;
                tmp.c = rc.c;
                visited[rc.r-1][rc.c] = 1;
                visited[rc.r-1][rc.c] += visited[rc.r][rc.c];
                enqueue(&q, tmp);
            }
            if(g->location[rc.r+1][rc.c] && !visited[rc.r+1][rc.c]) {
                tmp.r = rc.r + 1;
                tmp.c = rc.c;
                visited[rc.r+1][rc.c] = 1;
                visited[rc.r+1][rc.c] += visited[rc.r][rc.c];
                enqueue(&q, tmp);
            }
            if(g->location[rc.r][rc.c-1] && !visited[rc.r][rc.c-1]) {
                tmp.r = rc.r;
                tmp.c = rc.c-1;
                visited[rc.r][rc.c-1] = 1;
                visited[rc.r][rc.c-1] += visited[rc.r][rc.c];
                enqueue(&q, tmp);
            }
            if(g->location[rc.r][rc.c+1] && !visited[rc.r][rc.c+1]) {
                tmp.r = rc.r;
                tmp.c = rc.c+1;
                visited[rc.r][rc.c+1] = 1;
                visited[rc.r][rc.c+1] += visited[rc.r][rc.c];
                enqueue(&q, tmp);
            }
        }   
    }
}

int main() {
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    element rc;
    init(g);
    scanf("%d %d", &n, &m);
    for(int r=1; r<=n; r++)
        for(int c=1; c<=m; c++)
            scanf("%1d", &(g->location[r][c]));

    rc.r = 1; rc.c = 1;
    bfs(g, rc);
    free(g);
    printf("%d\n", visited[n][m]);
}