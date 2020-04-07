#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_VERTICES 25
#define MAX_GROUPS 315
int visited[MAX_VERTICES][MAX_VERTICES] = {0};
int groups[MAX_GROUPS] = {0};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // e w s n
int n, group = 0, cnt = 0;

void bubble_sort(int list[], int gp) {
    int i, j, temp;
    for(i=gp-1; i>0; i--) {
        for(j=0; j<i; j++)
            if(list[j]>list[j+1])
                SWAP(list[j], list[j+1], temp);
    }
}

typedef struct {
    int x, y;
} element;

#define MAX_QUEUE_SIZE 625
typedef struct {
    element queue[MAX_QUEUE_SIZE];
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
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
    q->front += 1;
    return q->queue[q->front];
}

typedef struct _GraphType {
    int n;
    int map[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init_graph(GraphType *g) {
    int r, c;
    for(r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->map[r][c] = 0;
}

void bfs(GraphType *g, element item) {
    QueueType q;
    element tmp;
    init_queue(&q);

    visited[item.x][item.y] = 1;
    enqueue(&q, item);
    cnt++;

    while(!is_empty(&q)) {
        item = dequeue(&q);
        for(int i=0; i<4; i++) {
            int x = item.x + dir[i][0];
            int y = item.y + dir[i][1];
            tmp.x = x;
            tmp.y = y;
            if(x >= 0 && y >= 0 && x < n && y < n) {
                if(g->map[x][y] && !visited[x][y]) {
                    visited[x][y] = 1;
                    enqueue(&q, tmp);
                    cnt++;
                }
            }
        }
    }
    groups[group++] = cnt;
}

int main() {
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);
    element item;
    scanf("%d", &n);
    for(int r=0; r<n; r++)
        for(int c=0; c<n; c++)
            scanf("%1d", &(g->map[r][c]));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(g->map[i][j] && !visited[i][j]) {
                item.x = i; item.y = j;
                cnt = 0;
                bfs(g, item);
            }

    bubble_sort(groups, group);
    printf("%d\n", group);
    for(int i=0; i<MAX_GROUPS; i++)
        if(groups[i] != 0)
            printf("%d\n", groups[i]);
    free(g);
}