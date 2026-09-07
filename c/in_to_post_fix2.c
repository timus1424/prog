#include <stdio.h>
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) 
        return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) 
        return -1;
    return stack[top];
}

int precedence(char op) {
    if (op == '^') 
        return 3;
    if (op == '*' || op == '/') 
        return 2;
    if (op == '+' || op == '-') 
        return 1;
    return 0;
}

// helper: check if operand (letter or digit)
int isOperand(char c) {
    return ( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}

void InfixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // operator
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    InfixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}