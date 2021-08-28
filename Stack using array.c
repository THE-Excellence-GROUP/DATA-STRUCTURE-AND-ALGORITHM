//stack using array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void push(int [],int *);
void pop(int [],int *);
void peek(int [],int *);
bool is_empty(int *);
bool is_full(int *);
void display(int [],int *);

int main()
{
    int stack[SIZE],top=-1;
    int choice;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(stack,&top);
            break;
        case 2: pop(stack,&top);
                break;
        case 3: peek(stack,&top);
                break;
        case 4: display(stack,&top);
                break;
        case 5: exit(0);
        default: printf("Wrong choice!\n");
            break;
        }
    }
    return 0;
}

void push(int stack[],int *top)
{
    if(is_full(top))
    {
        printf("Stack overflow!\n");
        return;
    }
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    *top=*top+1;
    stack[*top]=data;
    return;
}

void pop(int stack[],int *top)
{
    if(is_empty(top))
    {
        printf("Stack underflow!\n");
        return;
    }
    *top=*top-1;
    return;
}

void peek(int stack[],int *top)
{
    if(is_empty(top))
    {
        printf("Stack underflow!\n");
        return;
    }
    printf("Top element: %d\n",stack[*top]);
    return;
}

bool is_empty(int *top)
{
    if(*top<0)
        return true;
    else    
        return false;
}

bool is_full(int *top)
{
    if(*top>=SIZE-1)
        return true;
    else    
        return false;
}

void display(int stack[],int *top)
{
    if(is_empty(top))
    {
        printf("Stack underflow!\n");
        return;
    }
    int i;
    for(i=*top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
    return;
}
