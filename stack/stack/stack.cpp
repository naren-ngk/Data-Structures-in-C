#include <stdio.h>
#include<stdlib.h>
struct STACK {
    int size;
    int top;
    int* s;
};
void push(struct STACK* stack, int x) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow");
    }
    else {
        stack->top++;
        stack->s[stack->top] = x;
    }
}
int pop(struct STACK* stack) {
    int x = -1;
    if (stack->top == -1) {
        printf("Stack underflow");
    }
    else {
        x = stack->s[stack->top];
        stack->top--;
    }
    return x;
}
int peek(struct STACK stack, int pos) {
    int x = -1;
    if (stack.top - pos + 1 < 0) {
        printf("Invalid index");
    }
    else {
        x = stack.s[stack.top - pos + 1];
    }
    return x;
}
int stacktop(struct STACK stack) {
    if (stack.top == -1) {
        return -1;
    }
    else {
        return stack.s[stack.top];
    }
}
int isemptystack(struct STACK stack) {
    if (stack.top == -1) {
        return 1;
    }
    return 0;
}
int isfullstak(struct STACK stack) {
    if (stack.top == stack.size - 1) {
        return 1;
    }
    return 0;
}
int main()
{
    struct STACK *stack;
    printf("Enter the size: ");
    scanf("%d", stack->size);
    stack->s = (int*)malloc(stack->size * sizeof(int));
    stack->top = -1;
}

