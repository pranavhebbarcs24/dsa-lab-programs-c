#include<stdio.h>
#define size 2
int front=-1,rear=-1;
int queue[size];
void enque(int value){
    if(rear==size-1)
        printf("queue is full");
    else{
        if(front==-1)
            front=0;
        queue[++rear
        ]=value;
    }
}
void deque(){
    if(front==-1||front>rear)
            printf("queue is empty");
    else
        printf("%d",queue[front++]);
}
void display(){
    if(front==-1)
        printf("queue is empty");
    else{
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
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
