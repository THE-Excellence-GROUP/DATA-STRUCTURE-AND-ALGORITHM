                    #include <stdio.h>
                    #include <stdlib.h>
                    void insert_beg();
                    void insert_end();
                    void delete_beg();
                    void delete_end();
                    void display();
                    struct node               // making the structure of node
                    { 
                        int data;
                        struct node *prev;
                        struct node *next;
                    };
                    struct node *head=NULL,*newnode,*temp,*ptr;  // declearing the global variables
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
                                   printf("2.Insert at end\n");
                                   printf("Enter your choice:");
                                   scanf("%d",&c);
                                   switch(c)
                                   {
                                       case 1:insert_beg();
                                              break;
                                       case 2:insert_end();
                                              break;
                                       default:printf("Wrong choice\n");
                                   }
                                   break;
                            case 2:printf("\n---- Delete Menu ----\n");
                                   printf("1.Delete at begining\n");
                                   printf("2.Delete at end\n");
                                   printf("Enter your choice:");
                                   scanf("%d",&c);
                                   switch(c)
                                   {
                                       case 1:delete_beg();
                                              break;
                                       case 2:delete_end();
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
                            newnode->prev=newnode;  // the previous pointer of the newnode points to itself
                            newnode->next=newnode;  // the next pointer of the newnode points to itself
                            head=newnode;
                        }
                        else  // list is not empty
                        {
                            temp=head;
                            while(temp->next!=head)
                            {
                                temp=temp->next;  // traversing to the last node
                            }
                            temp->next=newnode;  // the next pointer of the last node points to newnode
                            newnode->prev=temp;  // the previous pointer of the newnode points to the last node
                            newnode->next=head;  // newnode will point to the starting node
                            head->prev=newnode;  // previous part of the starting node points to newnode
                            head=newnode;  // haed will start from newnode
                        }
                        return ;
                    }
                    
                    void insert_end()
                    {
                        newnode=(struct node*)malloc(sizeof(struct node));  // creating the node
                        printf("Enter the data:");
                        scanf("%d",&newnode->data);  // asking for the data 
                        if(head==NULL)  // list is empty
                        {
                            newnode->prev=newnode;  // the previous pointer of the newnode points to itself
                            newnode->next=newnode;  // the next pointer of the newnode points to itself
                            head=newnode;
                            return;
                        }
                        temp=head;  // list is not empty
                        while(temp->next!=head)
                        {
                            temp=temp->next;  // traversing to the last node
                        }
                        temp->next=newnode;  // the next pointer of the last node points to newnode
                        newnode->prev=temp; // previous pointer of the newnode will point to the last node
                        newnode->next=head;  // the next pointer of the newnode points to head node
                        head->prev=newnode;  // previous pointer of the head node will point to the last node or newnode
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
                            ptr=head;  // storing the value of the head node
                            temp=head;
                            while(temp->next!=head)
                            {
                                temp=temp->next;  // traversing to the last node
                            }
                            if(temp==head)  // list has only one node
                            {
                                head=NULL;  // list will be empty
                            }
                            else  // list has more than one node
                            {
                                head=head->next;  // head pointer goes to the next node
                                temp->next=head;  // the next pointer of the last node points to new head
                                head->prev=temp;  // the previous pointer of the head node points to last node
                            }
                            free(ptr);  // deallocating the memory for the previous head node
                        }
                        return ;
                    }
                    
                    void delete_end()
                    {
                        if(head==NULL)  // list is mepty
                        {
                            printf("List is empty\n\n");
                            return ;
                        }
                        temp=head; 
                        while(temp->next!=head)
                        {
                            temp=temp->next;  // traversing to the last node
                        }
                        if(temp == head)  // list has only one node
                            head=NULL;
                        else  // list has more than one node
                        {	
                            ptr=temp->prev;  // storing the address of the 2nd last node
                            ptr->next=head;  // the next pointer of the 2nd last node points to head
                            head->prev=ptr;  // the prvious pointer of the head node points to the 2nd last node
                        }
                        free(temp);
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
                        do
                        {
                            printf("%d ",temp->data);  // printing the data for each node
                            temp=temp->next;  // traversing to the last node
                        }while(temp!=head);
                        printf("\n\n");
                        return;
                    }

                
