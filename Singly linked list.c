//singly linked list
                    #include<stdio.h>
                    #include<stdlib.h>
                    void insert_beg(); 
                    void insert_end();
                    void insert_pos();
                    void display();
                    int countNodes();
                    void delete_beg();
                    void delete_end();
                    void delete_pos();
                    void reverse();
                    struct node // creating node type
                    {
                        int data;
                        struct node *next;
                    };
                    struct node *start=NULL,*q,*t;  // declaring global variables
                     
                    int main()
                    {
                        int ch,count;
                        while(1)
                        {
                            printf("\n\n---- Singly Linked List  ----");
                            printf("\n1.Insert\n2.Display\n3.Node count\n4.Delete\n5.Reverse\n6.Exit\n\n");
                            printf("Enter your choice:");
                            scanf("%d",&ch);
                     
                            switch(ch)
                            {
                                case 1:
                                        printf("\n---- Insert Menu ----");
                                        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position");
                                        printf("\n\nEnter your choice:");
                                        scanf("%d",&ch);
                     
                                        switch(ch)
                                        {
                                            case 1: insert_beg();
                                                    break;
                                            case 2: insert_end();
                                                    break;
                                            case 3: insert_pos();
                                                    break;
                                            default: printf("Wrong Choice!!");
                                        }
                                        break;
                     
                                case 2: display();
                                        break;
                                case 3: count=countNodes();
                                        printf("No. of nodes= %d\n",count);
                                         break;
                                case 4: printf("\n---- Delete Menu ----");
                                        printf("\n1.Delete at beginning\n2.Delete at end\n3.Delete at specified position");
                                        printf("\n\nEnter your choice:");
                                        scanf("%d",&ch);
                     
                                        switch(ch)
                                        {
                                            case 1: delete_beg();
                                                    break;
                                            case 2: delete_end();
                                                    break;
                                            case 3: delete_pos();
                                                    break;
                                            default: printf("Wrong Choice!!");
                                        }
                                        break;
                                case 5: reverse();
                                        break;	        
                                case 6: exit(0);
                                default: printf("Wrong Choice!!");
                    
                    }
                    }
                    return 0;
                                
                    }
                     
                    void insert_beg()
                    {
                        int num;
                        t=(struct node*)malloc(sizeof(struct node)); // creating new node
                        printf("Enter data:");
                        scanf("%d",&num);
                        t->data=num;  // putting the data to the new node
                     
                        if(start==NULL) // list is empty
                        {
                            t->next=NULL;
                            start=t;
                        }
                        else
                        {
                            t->next=start;  // new node points to the start node
                            start=t;
                        }
                    }
                     
                    void insert_end()
                    {
                        int num;
                        t=(struct node*)malloc(sizeof(struct node));  // creating new node
                        printf("Enter data:");
                        scanf("%d",&num);
                        t->data=num;
                        t->next=NULL;
                     
                        if(start==NULL)  // list is empty
                        {
                            start=t;
                        }
                        else
                        {
                            q=start;
                            while(q->next!=NULL) // traversing
                               q=q->next;
                            q->next=t;  // last node points to the new node
                        }
                    }
                     
                    void insert_pos()
                    {
                        int pos,i,num;
                        if(start==NULL)
                        {
                            printf("List is empty!!");
                            return;
                        }
                     
                        t=(struct node*)malloc(sizeof(struct node)); // creating new node
                        printf("Enter data:");
                        scanf("%d",&num);
                        printf("Enter position to insert:");
                        scanf("%d",&pos);
                        t->data=num;
                     
                        q=start;
                        for(i=1;i<pos-1;i++)  // traversing to the previous node of the position node
                        {
                            if(q->next==NULL)
                            {
                                printf("There are less elements!!");
                                return ;
                            }
                     
                            q=q->next;
                        }
                     
                        t->next=q->next;  // linking the new node to the next node
                        q->next=t;  // linking the previous node to the new node
                        return ;
                    }
                     
                    void display()
                    {
                        if(start==NULL)
                        {
                            printf("List is empty!!");
                        }
                        else
                        {
                            q=start;
                            printf("The linked list is:\n");
                            while(q!=NULL)  // traversing
                            {
                                printf("%d->",q->data);
                                q=q->next;
                            }
                        }
                    }
                    
                    int countNodes()
                    {
                        int count = 0;
                        struct node *temp;
                    
                        temp = start;
                    
                        while(temp != NULL)  // traversing
                        {
                            count++;
                            temp = temp->next;
                        }
                    
                        return count;
                    }
                    
                    void delete_beg() 
                    { 
                       if (start == NULL) 
                       {
                             printf("Underflow\n");
                             return;
                         }  
                        struct node *ptr= start; // storing the value of the start
                        start=start->next;  // start pointer goes to the next
                        free(ptr);
                    }
                    
                    void delete_end() 
                    { 
                       if (start == NULL) 
                       {
                             printf("Underflow\n");
                             return;
                       }  
                        struct node *temp,*ptr= start; 
                        while(ptr->next !=NULL) // traversing to the last node
                        {
                            temp=ptr;  // storing the previous value of ptr
                            ptr=ptr->next;
                        }
                        if(ptr==start)  // list has only one node
                        {
                            start=NULL;
                        }
                        else
                            temp->next=NULL;  // 2nd last node points to NULL
                        free(ptr);
                    }
                    
                    void delete_pos() 
                    { 
                       int position;
                       printf("\nEnter the position:");
                       scanf("%d",&position);
                       if (start == NULL) 
                       {
                             printf("Underflow\n");
                             return;
                         }  
                        if(position>countNodes())
                        {
                            printf("Position does not exist\n");
                            return;
                        }
                         int i=0;
                        struct node* temp,*ptr= start; 
                        // traversing to the previous node of position
                        for(i=0;i<position-1;i++) 
                         
                        { 
                             
                            temp=ptr;  
                            ptr=ptr-> next;
                        }
                        temp->next=ptr->next;  // linking two nodes skipping one node in between
                        free(ptr);
                    }
                    
                    void reverse()
                        {
                            struct node* current = start;
                            struct node *prev = NULL, *next;
                            while (current != NULL) // traversing the whole list
                            {
                                next = current->next;  // next pointer goes to the next node
                                current->next = prev;  // changing the link of the current node to previous node
                                prev = current;  // previous node goes to the current node
                                current = next;  // current node goes to the next node
                            }
                            start = prev;  // changing the starting pointer to the last node
                        }
