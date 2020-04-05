#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 100
int map[MAX_SIZE][MAX_SIZE] = {0, };
int ascending[MAX_SIZE] = {0, };
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int m, n, res = 0, idx = 0;
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
    return (q->front == NULL);
}

void enqueue(LinkedQueue *q, element data) {
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
    int cnt = 0;
    LinkedQueue q;
    element e;
    init_queue(&q);
    enqueue(&q, item);
    map[item.x][item.y] = 1;
    while(!is_empty(&q)) {
        e = dequeue(&q);
        for(int i=0; i<4; i++) {
            int x = e.x + dir[i][0];
            int y = e.y + dir[i][1];
            if(x >= 0 && y >= 0 && x < n && y < m) {
                if(map[x][y] == 0) {
                    item.x = x; item.y = y;
                    enqueue(&q, item);
                    map[x][y] = 1;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(map[i][j] == 1) {
                map[i][j] = 2;
                cnt++;
            }
    
    ascending[idx++] = cnt; 
    res++;
}

void bubble_sort(int list[], int n) {
    int i, j, temp;
    for(i=n-1; i>0; i--) {
        for(j=0; j<i; j++)
            if(list[j]>list[j+1])
                SWAP(list[j], list[j+1], temp);
    }
}

int main() {
    int k, x1, y1, x2, y2;
    element item;
    scanf("%d %d %d", &m, &n, &k);
    while(k--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i=x1; i<x2; i++)
            for(int j=y1; j<y2; j++)
                map[i][j] = 2;
        
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(map[i][j] == 0) {
                item.x = i; item.y = j;
                bfs(item);
            }

    printf("%d\n", res);
    bubble_sort(ascending, res);
    for(int i=0; i<res; i++)
        printf("%d ", ascending[i]);
}
