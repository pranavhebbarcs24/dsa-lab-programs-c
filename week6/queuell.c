#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", data);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue empty\n");
        return -1;
    }
    int val = front->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    return val;
}

int peek() {
    if (front == NULL) {
        printf("Queue empty\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (front == NULL) {
        printf("Queue empty\n");
        return;
    }
    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    printf("Front: %d\n", peek());
    printf("Dequeued: %d\n", dequeue());
    display();
    
    return 0;
}
