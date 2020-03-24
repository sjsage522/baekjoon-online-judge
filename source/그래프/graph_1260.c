#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001
int visited[MAX_VERTICES] = {0};

typedef struct _GraphType {
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init_graph(GraphType *g) {
    int r, c;
    for(r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)   
            g->adj_mat[r][c] = 0;
}

void insert_edge(GraphType *g, int s, int e) {
    g->adj_mat[s][e] = 1;
    g->adj_mat[e][s] = 1;
}

typedef struct {
    int queue[MAX_VERTICES];
    int front, rear;
} QueueType;

void init_queue(QueueType *q) {
    q->front = q->rear = -1;
}

void enqueue(QueueType *q, int item) {
    q->rear = q->rear + 1;
    q->queue[q->rear] = item;
}

int dequeue(QueueType *q) {
    q->front = q->front + 1;
    return q->queue[q->front];
}

int is_empty(QueueType *q) {
    return q->rear == q->front;
}

void dfs(GraphType *g, int v, int n) {
    int w;
    visited[v] = 1;
    printf("%d ", v);
    for(w=1; w<=n; w++)
        if(g->adj_mat[v][w] && !visited[w])
            dfs(g, w, n);
}

void bfs(GraphType *g, int v, int n) {
    int w;
    QueueType q;
    init_queue(&q);
    visited[v] = 1;
    printf("%d ", v);
    enqueue(&q, v);
    while(!is_empty(&q)) {
        v = dequeue(&q);
        for(w=1; w<=n; w++)
            if(g->adj_mat[v][w] && !visited[w]) {
                visited[w] = 1;
                printf("%d ", w);
                enqueue(&q, w);
            }
    }
}

int main() {
    int n, m, v, s, e;
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    scanf("%d %d %d", &n, &m, &v);
    while(m--) {
        scanf("%d %d", &s, &e);
        insert_edge(g, s, e);
    }
    dfs(g, v, n);
    printf("\n");
    for(int i=0; i<MAX_VERTICES; i++)
        visited[i] = 0;
    bfs(g, v, n);
    free(g);
}