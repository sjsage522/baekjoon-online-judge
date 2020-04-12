#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int box[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int m, n, h;
typedef struct {
    int x, y, z;
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

int check_fail() {
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(visited[i][j][k] == 0) {
                    printf("-1\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

void bfs() {
    LinkedQueue q;
    element e;
    init_queue(&q);
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(box[i][j][k] == 1 &&
                 !visited[i][j][k]) {
                     element item;
                     item.x = i;
                     item.y = j;
                     item.z = k;
                     enqueue(&q, item);
                     visited[i][j][k] = 1;
                 }
            }
        }
    }

    while(!is_empty(&q)) {
        e = dequeue(&q);
        for(int i=0; i<6; i++) {
            int x = e.x + dx[i];
            int y = e.y + dy[i];
            int z = e.z + dz[i];
            if(x>=0 && y>=0 && z>=0 &&
            x<h && y<n && z<m) {
                if(box[x][y][z] == 0 && 
                !visited[x][y][z]) {
                    element tmp;
                    tmp.x = x;
                    tmp.y = y;
                    tmp.z = z;
                    enqueue(&q, tmp);
                    visited[x][y][z] = 1;
                    visited[x][y][z] += visited[e.x][e.y][e.z];
                }
            }
        }
    }
    if(check_fail())
        return;
    else
        printf("%d\n", visited[e.x][e.y][e.z]-1);
}

void check_visited() {
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(box[i][j][k] == -1)
                    visited[i][j][k] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &h);
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                scanf("%d", &box[i][j][k]);
            }
        }
    }
    check_visited();
    bfs();
}