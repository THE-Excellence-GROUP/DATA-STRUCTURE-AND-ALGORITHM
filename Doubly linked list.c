                    #include <stdio.h>
                    #include <stdlib.h>
                    void insert_beg();
                    void insert_pos();
                    void insert_end();
                    void delete_beg();
                    void delete_pos();
                    void delete_end();
                    void display();
                    struct node               // making the structure of node
                    { 
                        int data;
                        struct node *prev;
                        struct node *next;
                    };
                    struct node *head=NULL,*newnode,*temp;  // declearing the global variables
                    int main()
                    {
                        int n,c;
                        while(1)
                        {
                        printf("\n****Main Menu****\n");
                        printf("1.Insert\n");
                        printf("2.Delete\n");
                        printf("3.Display\n");
                        printf("4.Exit\n");
                        printf("Enter your choice:");
                        scanf("%d",&n);
                        switch(n)
                        {
                            case 1:printf("\n---- Insert Menu ----\n");
                                   printf("1.Insert at begining\n");
                                   printf("2.Insert at specified position\n");
                                   printf("3.Insert at end\n");
                                   printf("Enter your choice:");
                                   scanf("%d",&c);
                                   switch(c)
                                   {
                                       case 1:insert_beg();
                                              break;
                                       case 2:insert_pos();
                                              break;
                                       case 3:insert_end();
                                              break;
                                       default:printf("Wrong choice\n");
                                   }
                                   break;
                            case 2:printf("\n---- Delete Menu ----\n");
                                   printf("1.Delete at begining\n");
                                   printf("2.Delete at specified position\n");
                                   printf("3.Delete at end\n");
                                   printf("Enter your choice:");
                                   scanf("%d",&c);
                                   switch(c)
                                   {
                                       case 1:delete_beg();
                                              break;
                                       case 2:delete_pos();
                                              break;
                                       case 3:delete_end();
                                              break;
                                       default:printf("Wrong choice\n");
                                   }
                                   break;
                            case 3:display();
                                   break;
                            case 4:exit(0);
                            default:printf("Wrong choice\n");
                        }
                        }
                        return 0;
                    }
                    
                    void insert_beg()
                    {
                        newnode=(struct node*)malloc(sizeof(struct node));  // creating the node
                        printf("Enter the data:");
                        scanf("%d",&newnode->data);  // asking the data from the user
                        if(head==NULL)  // if the list is empty
                        {
                            newnode->prev=NULL;
                            newnode->next=NULL;
                            head=newnode;
                        }
                        else  // list is not empty
                        {
                            newnode->prev=NULL;  // as this is the will be the first node
                            newnode->next=head;  // newnode will point to the starting node
                            head->prev=newnode;  // previous part of the starting node points to newnode
                            head=newnode;  // haed will start from newnode
                        }
                        return ;
                    }
                    
                    void insert_pos()
                    {
                        int pos,i;
                        if(head==NULL)  // list is empty
                        {
                            printf("List is empty!!");
                            return ;
                        }
                        newnode=(struct node*)malloc(sizeof(struct node));  // creating the node
                        printf("Enter the position:");  
                        scanf("%d",&pos);  // asking for the position
                        printf("Enter the data:");
                        scanf("%d",&newnode->data);  // asking for the data
                        temp=head;
                        for(i=1;i<pos-1;i++)
                        {
                            if(temp->next == NULL)
                            {
                                printf("Invalid position\n");  // if the position is greater than the no of node
                                return;
                            }
                            temp=temp->next;  // traversing to the previous position node
                        }
                        newnode->prev=temp;  // the previous pointer of the newnode node points to temp
                        newnode->next=temp->next;  // the next pointer of the newnode points to next node of temp
                        temp->next->prev=newnode;  // the previous pointer of the next node of temp points to newnode
                        temp->next=newnode;  // the next pointer of the temp node points to newnode
                        return ;
                    }
                    
                    void insert_end()
                    {
                        newnode=(struct node*)malloc(sizeof(struct node));  // creating the node
                        printf("Enter the data:");
                        scanf("%d",&newnode->data);  // asking for the data 
                        if(head==NULL)  // list is empty
                        {
                            newnode->next=NULL;
                            newnode->prev=NULL;
                            head=newnode;
                            return;
                        }
                        temp=head;  // list is not empty
                        while(temp->next!=NULL)
                        {
                            temp=temp->next;  // traversing to the last node
                        }
                        temp->next=newnode;  // the next pointer of the last node points to newnode
                        newnode->prev=temp; // previous pointer of the newnode will point to the last node
                        newnode->next=NULL;  // the next pointer of the newnode points to NULL
                        return ;
                    }
                    
                    void delete_beg()
                    {
                        if(head==NULL)  // list is empty
                        {
                            printf("List is empty\n\n");
                            return;
                        }
                        else  // list is not empty
                        {
                            temp=head;  // storing the value of the head node
                            head=head->next;  // head pointer goes to the next node
                            if(head != NULL)  // if list has more than one node
                                head->prev=NULL;  // the previous pointer of the head node points to NULL
                            free(temp);  // deallocating the memory for the previous head node
                        }
                        return ;
                    }
                    
                    void delete_pos()
                    {
                        if(head==NULL)  // list is empty
                        {
                            printf("List is empty\n\n");
                            return ;
                        }
                        int pos,i;  // list is not empty
                        printf("Enter the position:");
                        scanf("%d",&pos);  // asking for the position for delete
                        temp=head;
                        for(i=1;i<pos-1;i++)
                        {
                            temp=temp->next;  // traversing to the previous position node
                        }
                        struct node *ptr=temp->next;  // declearing pointer variable and storing the address of the deleted node
                        temp->next=ptr->next;  // the next pointer of the temp points to the next node of ptr
                        ptr->next->prev=temp;  // the previous pointer of the next node of ptr points to temp
                        free(ptr);
                        return;
                    }
                    
                    void delete_end()
                    {
                        if(head==NULL)  // list is mepty
                        {
                            printf("List is empty\n\n");
                            return ;
                        }
                        struct node *ptr=head;  // declearing pointer variable
                        while(ptr->next!=NULL)
                        {
                            temp=ptr;  // storing the previous value of the ptr 
                            ptr=ptr->next;  // traversing to the last node
                        }
                        if(ptr == head)  // list has only one node
                            head=NULL;
                        else  // list has more than one node
                            temp->next=NULL;  // the next pointer of the 2nd last node points to NULL
                        free(ptr);
                        return;
                    }
                    
                    void display()
                    {
                        if(head==NULL)  // list is empty
                        {
                            printf("List is empty\n\n");
                            return ;
                        }
                        temp=head;  // list is not empty
                        while(temp!=NULL)
                        {
                            printf("%d ",temp->data);  // printing the data for each node
                            temp=temp->next;  // traversing to the last node
                        }
                        printf("\n\n");
                        return;
                    }
