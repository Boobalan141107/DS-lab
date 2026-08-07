#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct stack{
int arr[MAX];
int top;
};
void initializestack(struct stack *stack);
int isFull(struct stack *stack);
int isEmpty(struct stack *stack);
void push(struct stack *stack, int element);
int pop(struct stack *stack);
void displaystack(struct stack *stack);
int main()
{
struct stack stack;
int choice, element;
initializestack(&stack);
while(1)
{
printf("\nStack Operations Menu:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice)
 {
case 1:
printf("Enter element to push: ");
scanf("%d", &element);
push(&stack, element);
break;
case 2:
element = pop(&stack);
if(element != -1)
printf("Popped element: %d\n", element);
break;
case 3:
displaystack(&stack);
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
  }
}

return 0;
}

void initializestack(struct stack *stack)
{
stack->top = -1;
}

int isFull(struct stack *stack)
{
return stack->top == MAX - 1;
}

int isEmpty(struct stack *stack)
{
return stack->top == -1;
}

void push(struct stack *stack, int element)
{
if(isFull(stack))
    {
 printf("Error: Stack Overflow.\n");
return;
    }

stack->arr[++stack->top] = element;
printf("Element pushed: %d\n", element);
}

int pop(struct stack *stack)
{
if(isEmpty(stack))
{
printf("Error: Stack Underflow.\n");
return -1;
}
return stack->arr[stack->top--];
}

void displaystack(struct stack *stack)
{
if(isEmpty(stack))
{
printf("Stack is empty.\n");
 return;
}

printf("Stack elements: ");
for(int i = stack->top; i >= 0; i--)
 {
printf("%d ", stack->arr[i]);
}
printf("\n");
}
