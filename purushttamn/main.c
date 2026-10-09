#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
     stack[++top] = c; }
char pop() {
     return (top == -1) ? '\0' :
     stack[top--]; }
char peek() {
    return (top == -1) ? '\0' :
     stack[top]; }

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && prec(peek()) >= prec(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
