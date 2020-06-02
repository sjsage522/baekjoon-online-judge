#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y, color;
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

//map
#define MAX_SIZE 101
int area[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n, res;
void bfs(element data) {
    LinkedQueue q;
    init_queue(&q);
    enqueue(&q, data);
    visited[data.x][data.y] = 1;
    while(!is_empty(&q)) {
        element item = dequeue(&q);
        for(int i=0; i<4; i++) {
            int x = item.x + dir[i][0];
            int y = item.y + dir[i][1];
            if(x>=0 && y>=0 && x<n && y<n) {
                if(!visited[x][y] && area[x][y] == item.color) {
                    element temp;
                    temp.x = x;
                    temp.y = y;
                    temp.color = item.color;
                    enqueue(&q, temp);
                    visited[x][y] = 1;
                }
            }
        }
    }
    res++;
}

void conversion() {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(area[i][j] == 'R') 
                area[i][j] = 'G';
}

void init() {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0; 
}

void process() {
    element data;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!visited[i][j] && 
            (area[i][j] == 'R' || area[i][j] == 'G' ||
             area[i][j] == 'B')) {
                data.x = i;
                data.y = j;
                data.color = area[i][j];
                bfs(data);
             }
}

int main() {
    // R : 82, G : 71, B : 66
    int ch;
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            scanf(" %c", &area[i][j]);
    process();
    printf("%d ", res);
    res = 0;
    conversion();
    init();
    process();
    printf("%d\n", res);
}