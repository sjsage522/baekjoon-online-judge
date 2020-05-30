#include <stdio.h>
#include <stdlib.h>
#define MAX_SPACES 1000
int visited[MAX_SPACES][MAX_SPACES] = {0};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
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
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType *q) {
    QueueNode *temp = q->front;
    element data = temp->data;

    q->front = q->front->link;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);

    return data;
}

typedef struct _GraphType {
    int box[MAX_SPACES][MAX_SPACES];
} GraphType;

void init_graph(GraphType *g) {
    int r, c;
    for(r=0; r<MAX_SPACES; r++)
        for(c=0; c<MAX_SPACES; c++)
            g->box[r][c] = 0;
}

void bfs(GraphType *g) {
    LinkedQueueType q;
    init_queue(&q);
    element item;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g->box[i][j] == 1) {
                item.x = i;
                item.y = j;
                visited[i][j] = 1;
                enqueue(&q, item);
            }

    while(!is_empty(&q)) {
        item = dequeue(&q);
        for(int i=0; i<4; i++) {
            element tmp;
            tmp.x = item.x + dir[i][0]; 
            tmp.y = item.y + dir[i][1];
            if(tmp.x >= 0 && tmp.y >= 0 && tmp.x < n && tmp.y < m) {
                if(g->box[tmp.x][tmp.y] == 0 && !visited[tmp.x][tmp.y]) {
                    g->box[tmp.x][tmp.y] = 1;
                    visited[tmp.x][tmp.y] = 1;
                    visited[tmp.x][tmp.y] += visited[item.x][item.y];
                    enqueue(&q, tmp);
                }
            } 
        }            
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(visited[i][j] == 0) {
                printf("-1\n");
                return;
            }
    printf("%d\n", visited[item.x][item.y] - 1);
}

int main() {
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &(g->box[i][j]));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g->box[i][j] == -1)
                visited[i][j] = -1;
    bfs(g);
    free(g);
}