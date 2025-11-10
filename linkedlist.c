#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newnode, *temp;
    int i, val;
    for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &val);
        newnode->data = val;
        newnode->next = NULL;
        if (head == NULL) head = newnode;
        else {
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert_begin(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insert_end(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) head = newnode;
    else {
        struct node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newnode;
    }
}

void insert_pos(int val, int pos) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }
    struct node *temp = head, *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, n, val, pos;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d%d", &val, &pos);
                insert_pos(val, pos);
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
