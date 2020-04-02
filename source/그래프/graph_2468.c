#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int map[MAX_SIZE][MAX_SIZE];
int copy[MAX_SIZE][MAX_SIZE];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n;

typedef struct {
    int x, y;
} element; 

typedef struct _QueueNode {
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct _LinkedQueue {
    QueueNode *front, *rear;
} LinkedQueue;

void init_queue(LinkedQueue *q) {
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueue *q) {
    return q->front == NULL;
}

void enqueue(LinkedQueue *q, element data) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueue *q) {
    QueueNode *temp = q->front;
    element item = temp->data;
    q->front = q->front->link;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return item;
}

void bfs(element item) {
    LinkedQueue q;
    element e;
    init_queue(&q);
    enqueue(&q, item);
    copy[item.x][item.y] = -1;
    while(!is_empty(&q)) {
        e = dequeue(&q);
        for(int i=0; i<4; i++) {
            int x = e.x + dir[i][0];
            int y = e.y + dir[i][1];
            if(x>=0 && y>=0 && x<n && y<n) {
                if(copy[x][y] != -1) {
                    element tmp;
                    tmp.x = x; tmp.y = y;
                    copy[x][y] = -1;
                    enqueue(&q, tmp);
                }
            }
        }
    }
}

int main() {
    element item;
    int cnt=0, res=0, i;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);

    for(i=0; i<=100; i++) {
        cnt = 0;
        for(int r=0; r<n; r++)
            for(int c=0; c<n; c++)
                copy[r][c] = map[r][c];

        for(int r=0; r<n; r++)
            for(int c=0; c<n; c++)      
                if(copy[r][c] <= i)
                    copy[r][c] = -1;

        for(int r=0; r<n; r++)
            for(int c=0; c<n; c++)
                if(copy[r][c] != -1) {
                    item.x = r; item.y = c;
                    bfs(item);
                    cnt++;
                }
        if(res < cnt)
            res = cnt;
    }
    printf("%d\n", res);
}