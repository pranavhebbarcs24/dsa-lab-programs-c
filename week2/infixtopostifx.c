#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    if (top == 99) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

char pop() {
    if (top == -1) {
        return '0';
    } else {
        return stack[top--];
    }
}

int isOperand(char c) {
    return isalnum(c);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;

    int len = strlen(infix);
    int k = 0;

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                if (c == '^' && stack[top] == '^') break;
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
