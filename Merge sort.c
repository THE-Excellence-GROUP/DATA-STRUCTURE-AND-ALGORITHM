//merge sort
                        #include<stdio.h>
                        #include <stdlib.h>
                        
                        void merge(int list[],int start,int end,int mid)
                        {
                            int left=start;
                            int right=mid+1;
                            int A[end+1];  // temporary array for storing the sorted elements
                            int i=start;
                            while(left<=mid && right<=end) // traversing by two index through the two sub array
                            {
                                if(list[left]<=list[right])
                                {
                                    A[i]=list[left];
                                    left++;
                                }
                                else
                                {
                                    A[i]=list[right];
                                    right++;
                                }
                                i++;
                            }
                            if(left>mid)  // if left sub array is completed
                            {
                                while(right<=end)
                                {
                                    A[i]=list[right];
                                    i++;
                                    right++;
                                }
                            }
                            else  // if right sub array is completed
                            {
                                while(left<=mid)
                                {
                                    A[i]=list[left];
                                    i++;
                                    left++;
                                }
                            }
                            // store back the sorted elements to the main list
                            for(i=start;i<=end;i++)
                            {
                                list[i]=A[i];
                            }
                        }
                        
                        void merge_sort(int list[],int start,int end)
                        {
                            int mid;
                            if(start<end)  // base condition
                            {
                                mid=(start+end)/2;  // calculating middle index
                                merge_sort(list,start,mid);  // calling the function recursively for the left sub array
                                merge_sort(list,mid+1,end);  // calling the function recursively for the right sub array
                                merge(list,start,end,mid);  // merging two subarray
                            }
                        }
                        
                        int main()
                        {
                            int n,i;
                            printf("Enter the no of elements: ");
                            scanf("%d",&n);
                            int *list=(int *)malloc(n*sizeof(int));// allocating memory for array
                            printf("Enter the values: ");
                            for(i=0;i<n;i++)
                                scanf("%d",&list[i]);
                            merge_sort(list,0,n-1); // calling the mergesort function
                            printf("New sorted list is:\n");
                            for(int i=0;i<n;i++)
                            {
                                printf("%d ",list[i]);
                            }
                            return 0;
                        }
