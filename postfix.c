#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Function to create a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Stack* stack = createStack();
    for (int i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            // Convert char to int and push onto stack
            push(stack, expression[i] - '0');
        } else {
            // Pop two operands for the operator
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid Operator: %c\n", expression[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }
    return pop(stack); // Final result
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression (e.g., 53+82-*): ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remove newline character from fgets input
    expression[strcspn(expression, "\n")] = 0;

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression '%s' is: %d\n", expression, result);

    return 0;
}
