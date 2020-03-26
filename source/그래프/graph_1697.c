#include <stdio.h>
#include <stdlib.h>
int visited[200001] = {0};
int dir[3] = {-1, 1, 2};
int n, k;
typedef struct {
    int v;
    int day;
} element;

typedef struct _QueueNode {
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

void init_queue(LinkedQueueType *q) {
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType *q) {
    return q->front == NULL;
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

void bfs() {
    LinkedQueueType q;
    init_queue(&q);
    element item;
    item.v = n;
    item.day = 1;
    visited[n] = 1;
    enqueue(&q, item);
    while(!is_empty(&q)) {
        item = dequeue(&q);
        if(item.v == k) {
            printf("%d\n", item.day-1);
            return;
        }
        for(int i=0; i<3; i++) {
            element tmp;
            if(dir[i] != 2) {
                tmp.v = item.v + dir[i];
                tmp.day = item.day;
            }
            else {
                tmp.v = item.v * dir[i];
                tmp.day = item.day;
            }
            if(tmp.v <= 100000 && tmp.v >= 0 && !visited[tmp.v]) {
                tmp.day += 1;
                visited[tmp.v] = 1;
                enqueue(&q, tmp);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    bfs();
}