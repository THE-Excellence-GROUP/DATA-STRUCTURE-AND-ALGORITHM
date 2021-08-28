//circular linked list
    #include <stdio.h>
    #include<stdlib.h>
    #include <malloc.h>
    void insert_beg(); 
    void insert_end();
    void display();
    void delete_beg();
    void delete_end();
    struct node  // creating node type
    {
        int data;
        struct node *next;  // pointer member for pointing to the next node
    };
    struct node *start=NULL,*ptr,*temp;  // declaring the global variables
     
    int main()
    {
        int ch;
        while(1)
        {
            printf("\n\n---- Circular Linked List  ----");  // main menu
            printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
            printf("Enter your choice:");
            scanf("%d",&ch);
     
            switch(ch)
            {
                case 1:
                        printf("\n---- Insert Menu ----");  // insert menu
                        printf("\n1.Insert at beginning\n2.Insert at end");
                        printf("\n\nEnter your choice:");
                        scanf("%d",&ch);
     
                        switch(ch)
                        {
                            case 1: insert_beg();
                                    break;
                            case 2: insert_end();
                                    break;
                            default: printf("Wrong Choice!!");
                        }
                        break;
     
                case 2: display();
                        break;
                case 3: printf("\n---- Delete Menu ----");  // delete menu
                        printf("\n1.Delete at beginning\n2.Delete at end");
                        printf("\n\nEnter your choice:");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                            case 1: delete_beg();
                                    break;
                            case 2: delete_end();
                                    break;
                            default: printf("Wrong Choice!!");
                        }
                        break;     
                case 4: exit(0);
                default: printf("Wrong Choice!!");
    
    }
    }
    return 0;
                
    }
     
    void insert_beg()
    {
        int num;
        ptr=(struct node*)malloc(sizeof(struct node));  // creating new node
        printf("Enter data:");
        scanf("%d",&num);
        ptr->data=num;  //putting the data in the new node
     
        if(start==NULL) // if list is empty
        {
            ptr->next=ptr;  // the next pointer of the first node point to itself
            start=ptr;      // new pointer will be the start pointer
        }
        else  // list is not empty
        {
            ptr->next=start; // new node point to start node
            temp=start;
            while(temp->next!=start)  // traversing to the last node
            {
                temp=temp->next;
            }
            temp->next=ptr;  // last node point to the first node
            start=ptr;  // new node is the first node
        }
    }
     
    void insert_end()
    {
        int num;
        ptr=(struct node*)malloc(sizeof(struct node));  // creating new node
        printf("Enter data:");
        scanf("%d",&num);
        ptr->data=num;  // putting the data in the new node
        if(start==NULL)  // if list is empty
        {
            ptr->next=ptr; // first node point to itself
            start=ptr;
        }
        else  //  list is not empty
        {
            temp=start;
            while(temp->next!=start)  // traversing to ten last node
            {
                temp=temp->next;
            }
            temp->next=ptr;  // last node point to the new node
            ptr->next=start;  // new node point to the start node
        }
    }
     
    void display()
    {
        if(start==NULL) // list is empty
        {
            printf("List is empty!!");
        }
        else  // list is not empty
        {
            ptr=start;
            printf("The linked list is:\n");
            do
            {
                printf("%d->",ptr->data);  
                ptr=ptr->next;  // traversing through the whole list
            }
            while(ptr!=start);
        }
    }
    
    void delete_beg()  
    {  
        if(start == NULL)  // list is empty
        {  
            printf("\nUNDERFLOW\n");      
        }  
        else // list is not empty
        {  
            ptr=start;  // storing the startign pointer
            temp=start;
            while(temp->next!=start)  // traversing to the last node
            {
                temp=temp->next;
            }
            if(temp==start) // list has only one node
            {
                start=NULL;
            }
            else
            {
                start=start->next;  // start pointer goes to the next node
                temp->next=start;  // last node points to start node
            }
            free(ptr);   
        }
    }
        
    void delete_end()
    { 
        if (start == NULL) // list is empty
        { 
            printf("\nList is empty\n"); 
            return; 
        } 
      
        else // list is not empty
        {
            ptr=start;
            while (ptr->next != start) // traversing to the last node
            { 
                temp=ptr;  // storing the previous value of ptr for getting 2nd last node
                ptr=ptr->next;
            } 
            if(ptr==start)  // list has only one node
            {
                start=NULL;
            }
            else
            {
                temp->next=start; // 2nd last node points to the start node
            }
            free(ptr);
            return;
       }
    }
