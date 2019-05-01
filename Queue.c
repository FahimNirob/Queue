#include<stdio.h>
#define Q_SIZE 5

typedef struct {
    int data[Q_SIZE + 1];
    int head,tail;
} Queue ;

void ENQUEUE(Queue *q, int item);
int DEQUE(Queue *q);

int main(){
    Queue my_q;
    int item;
    int value;
    int i,j,n;
    my_q.head = 0;
    my_q.tail = 0;

    printf("How many numbers to enqueue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        ENQUEUE(&my_q,j);
        value = (&my_q,j);
        printf("Value = %d, Tail = %d\n",value,my_q.tail);
    }

    /*
    ENQUEUE(&my_q,5);
    printf("Tail = %d\n",my_q.tail);
    ENQUEUE(&my_q,6);
    printf("Tail = %d\n",my_q.tail);
    */

    printf("\nBeginning head = %d\n",my_q.head);

    printf("How many items to Deque : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        item = DEQUE(&my_q);
        printf("Item = %d, Head = %d\n",item,my_q.head);
    }

    /*
    item = DEQUE(&my_q);
    printf("Item = %d, head = %d\n",item,my_q.head);
    item = DEQUE(&my_q);
    printf("Item = %d , head = %d\n",item,my_q.head);
    item = DEQUE(&my_q);
    printf("Item = %d, head = %d\n",item,my_q.head);
    */

}

void ENQUEUE(Queue *q,int item){
    if((q->tail + 1) % (Q_SIZE + 1) == q->head){
        printf("Queue is full !\n");
        return ;
    }

    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_SIZE + 1);
}

int DEQUE(Queue *q){
    int item;
    if(q->tail == q->head){
        printf("Queue is empty !\n");
        return -1;
    }

    item = q->data[q->head];
    q->head = (q->head + 1) % (Q_SIZE + 1);
    return item;
}

