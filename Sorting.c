                        #include <stdio.h>
                        #include <stdlib.h>
                        void bubble_sort();
                        void insertion_sort();
                        void selection_sort();
                        int main()
                        {
                            int choice;
                            while(1)
                            {
                                printf("1:Bubble Sort\n2:Insertion Sort\n3:Selection Sort\n4:Exit\n");
                                printf("Enter choice:");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                    case(1):
                                        bubble_sort();
                                        break;
                                    case(2):
                                       insertion_sort();
                                        break;
                                    case(3):
                                       selection_sort();
                                        break;	
                                    case(4):
                                         exit(0);
                                    default:
                                        printf("Wrong input\n");			
                                }
                            }
                            return 0;
                        }
                        void bubble_sort()
                        {
                            int n, i, j, temp; 
                            printf("Enter number of elements:");
                            scanf("%d", &n);
                            int array[n]; 
                            printf("Enter %d Numbers:\n", n); 
                            for(i = 0; i < n; i++)
                            scanf("%d", &array[i]); // scanning the values
                            for(i=0;i<n-1;i++)
                            {
                                // bringing the maximum element at the end of the list
                                for(j=0;j<n-i-1;j++)  
                                {
                                    if(array[j]>array[j+1]) 
                                    {
                                        //swapping
                                         temp=array[j];
                                         array[j]=array[j+1];  
                                         array[j+1]=temp;
                                    }
                                }
                            } 
                            printf("Sorted list in ascending order:\n"); 
                            // printing the new sorted list
                            for(i=0;i<n;i++)
                                printf("%d ",array[i]);
                            printf("\n");
                            return;
                         }
                        void insertion_sort()
                        {
                            int n, i, j, temp;
                            printf("Enter number of elements:");
                            scanf("%d", &n);
                            int array[n];
                            printf("Enter %d Numbers:\n", n);
                            // scanning the elements
                            for(i=0;i<n;i++)
                            {
                                scanf("%d",&array[i]);
                            }
                            // traversing from 2nd position to the last
                            for(i=1;i<=n-1;i++)
                            {
                                j=i;
                                // searching for the position to insert
                                while(j>0 && array[j-1]>array[j])
                                {	// swapping two adjacent elements    
                                    temp=array[j];
                                    array[j]=array[j-1];
                                    array[j-1]=temp;
                                    j--;
                                }
                                /* OR we can just shift the elemets towards right after storing the 
                                   insering element into temp (Another approach)  */  
                            }
                            printf("Sorted list in ascending order:\n");
                            // printing the new sorted list
                            for(i=0;i<=n-1;i++)
                            {
                                printf("%d ",array[i]);
                            }
                            printf("\n");
                            return;
                        }
                        void selection_sort()
                        {
                            int n,i,j,min,temp;
                            printf("Enter number of elements:");
                            scanf("%d",&n);
                            int array[n];
                            printf("Enter %d Numbers:\n", n);
                            // scanning the elements
                            for(i=0;i<n;i++)
                            {
                                scanf("%d",&array[i]);
                            }
                             
                            for(i=0;i<n-1;i++)
                            {
                                // finding the index of the minimum element
                                min=i;
                                for(j=i+1;j<n;j++)
                                {
                                    if(array[min]>array[j])
                                    min=j;
                                }
                                if(min!=i)  // minimum element is not in correct position
                                {
                                    // swapping two elements
                                    temp=array[i];
                                    array[i]=array[min];
                                    array[min]=temp;
                                }
                            }
                            printf("Sorted list in ascending order:\n");
                            // printing the new sorted list
                            for(i=0;i<n;i++)
                            {
                                printf("%d ",array[i]);
                            }
                            printf("\n");
                            return;
                        }
