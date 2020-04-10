#include <stdio.h>
#include <stdlib.h>

// queue
typedef struct {
    int x,y;
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
    element data = temp->data;
    q->front = q->front->link;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

//map
#define MAX_SIZE 300
int chess[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dir[8][2] = {{-2,-1}, {-2,1}, {2,-1}, {2,1},
                 {-1,-2}, {-1,2}, {1,-2}, {1,2}};
int l;
void init() {
    for(int x=0; x<MAX_SIZE; x++)
        for(int y=0; y<MAX_SIZE; y++) {
            chess[x][y] = 0;
            visited[x][y] = 0;
        }
}

element search() {
    element data;
    for(int x=0; x<l; x++)
        for(int y=0; y<l; y++)
            if(chess[x][y] == 1) {
                data.x = x;
                data.y = y;
            }
    return data;
}

void bfs(element data) {
    LinkedQueue q;
    init_queue(&q);
    enqueue(&q, data);
    visited[data.x][data.y] = 1;
    while(!is_empty(&q)) {
        element item = dequeue(&q);
        for(int i=0; i<8; i++) {
            int x = item.x + dir[i][0];
            int y = item.y + dir[i][1];
            if(x>=0 && y>=0 && x<l && y<l) {
                if(!visited[x][y]) {
                    if(chess[x][y] == 2) {
                        printf("%d\n", visited[item.x][item.y]);
                        return;
                    }
                    element temp;
                    temp.x = x;
                    temp.y = y;
                    enqueue(&q, temp);
                    visited[x][y] = 1;
                    visited[x][y] += visited[item.x][item.y];
                }
            }
        }
    }
}

int main() {
    element data;
    int t, x1, y1, x2, y2;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d", &l);
        scanf("%d %d", &x1, &y1);
        chess[x1][y1] = 1; // curr
        scanf("%d %d", &x2, &y2);
        chess[x2][y2] = 2; // goal
        if(x1 == x2 && y1 == y2) {
            printf("0\n");
            continue;
        }
        data = search();
        bfs(data);
    }    
}
