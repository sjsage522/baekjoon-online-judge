#include <stdio.h>
#include <stdlib.h>
int m, n;
typedef struct {
    int x, y;
} element;
typedef struct _QueueNode {
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

int is_empty(LinkedQueueType *q) {
    return q->front == NULL;
}

void init_queue(LinkedQueueType *q) {
    q->front = q->rear = NULL;
}

void enqueue(LinkedQueueType *q, element data) {
    QueueNode *tmp = (QueueNode*)malloc(sizeof(QueueNode));
    tmp->data = data;
    tmp->link = NULL;
    if(is_empty(q)) {
        q->front = tmp;
        q->rear = tmp;
    }
    else {
        q->rear->link = tmp;
        q->rear = tmp;
    }
}

element dequeue(LinkedQueueType *q) {
    QueueNode *tmp = q->front;
    element data;
    data = tmp->data;
    q->front = q->front->link;
    if(q->front == NULL)
        q->rear = NULL;
    free(tmp);
    return data;
}

#define MAX_SIZE 50
int visited[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
typedef struct _GraphType {
    int farm[MAX_SIZE][MAX_SIZE];
} GraphType;

void init_graph(GraphType *g) {
    int r, c;
    for(r=0; r<MAX_SIZE; r++)
        for(c=0; c<MAX_SIZE; c++) {
            g->farm[r][c] = 0;
            visited[r][c] = 0;
        }
}

void bfs(GraphType *g, element data) {
    LinkedQueueType q;
    element tmp;
    init_queue(&q);
    
    visited[data.y][data.x] = 1;
    enqueue(&q, data);
    while(!is_empty(&q)) {
        data = dequeue(&q);
        for(int i=0; i<4; i++) {
            int y = data.y + dy[i];
            int x = data.x + dx[i];
            tmp.x = x; tmp.y = y;
            if(x >= 0 && y >= 0 && x < m && y < n) {
                if(g->farm[y][x] && !visited[y][x]) {
                    visited[y][x] = 1;
                    enqueue(&q, tmp);
                }
            }
        }
    }   
}

int main() {
    int t, k, r, c, res;
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    element tmp;
    scanf("%d", &t);
    while(t--) {
        res = 0;
        init_graph(g);
        scanf("%d %d %d", &m, &n, &k);
        while(k--) {
            scanf("%d %d", &r, &c);
            g->farm[c][r] = 1;
        }

        for(int y=0; y<n; y++)
            for(int x=0; x<m; x++)
                if(!visited[y][x] && g->farm[y][x]) {
                    tmp.y = y; tmp.x = x;
                    bfs(g, tmp);
                    res++;
                }
        printf("%d\n", res);
    }
    free(g);
}