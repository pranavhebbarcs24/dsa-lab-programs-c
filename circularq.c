#include<stdio.h>
#define size 2
int front=-1,rear=-1;
int queue[size];
void enque(int value){
    if((rear+1)%size==front)
        printf("queue is full");
    else{
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        queue[rear]=value;
    }
}
void deque(){
    if(front==-1)
            printf("queue is empty");
    else{
    printf("%d",queue[front]);
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%size;
    }
}
void display() {
    if (front == -1) {
        printf("queue is empty");
    } else {
        int i = front;
        while(1){
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i=(i+1)%size;
    }
}
}
int main(){
    int value,choice;
    while(1){
    printf(" \n1.enque\n 2.deque\n 3.display\n 4.exit\n");
    printf("enter choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("enter value:");
        scanf("%d",&value);
        enque(value);
        break;
    case 2:
        deque();
        break;
    case 3:
        display();
        break;
    case 4:
        return 0;
    default:
        printf("invalid choice");
    }
    }
}

