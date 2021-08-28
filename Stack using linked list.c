//stack using linked list
#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

int main()
{
    int choice,val;
	while(1)
	{
		printf("1.Push\n");
	    printf("2.Pop\n");
	    printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: "); 
        scanf("%d",&choice);
        switch(choice){
        	case 1:
        		push();
        	    break;
        	case 2:
        		pop();
        		break;
        	case 3:
        		display();
        		break;
        	case 4:
        		exit(0);
        		break;
            default: printf("Wrong choice!\n");
                     break;
		}
	}
	return 0;
}

void push()
{
    struct node *newnode;
    int val;
    printf("Enter the data: ");
    scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
    return;
}

void pop()
{
	if(top==NULL)
	    printf("Underflow\n");
	else
	{
		struct node *temp;
	    temp=top;
	    top=top->next;
	    free(temp);
    }
    return;
}

void display()
{
	if(top==NULL)
	    printf("Empty\n");
	else
	{
		struct node *temp;
		temp=top;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	
}
