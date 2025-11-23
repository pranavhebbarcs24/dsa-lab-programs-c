#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

void create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d added\n", data);
}

void insertLeft(int target, int data) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("%d not found\n", target);
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;
    
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    
    printf("%d inserted left of %d\n", data, target);
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    printf("%d deleted\n", data);
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf("<-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    create(10);
    create(20);
    create(30);
    create(40);
    display();
    
    insertLeft(30, 25);
    display();
    
    insertLeft(10, 5);
    display();
    
    deleteNode(25);
    display();
    
    deleteNode(10);
    display();
    
    return 0;
}
