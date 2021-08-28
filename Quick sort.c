//quick sort
                #include <stdio.h>
                #include<stdlib.h>
                
                int partition(int A[],int start,int end)
                {
                    int pivot=A[end],temp;  // pivot is the last element of the given list
                    int pIndex=start;
                    for(int i=start;i<end;i++)
                    {
                        if(A[i]<pivot)
                        {
                            // swapping two elements
                            temp=A[pIndex];
                            A[pIndex]=A[i];
                            A[i]=temp;
                            pIndex++;
                        }
                    }
                    // swapping the pivot and the indexed element
                    A[end]=A[pIndex];
                    A[pIndex]=pivot;
                    return pIndex;
                }
                
                void quickSort(int A[],int start,int end)
                {
                    int pIndex;
                    if(start<end)
                    {
                        pIndex=partition(A,start,end);  // finding pivot element index
                        quickSort(A,start,pIndex-1);  // recursively calling for the left part
                        quickSort(A,pIndex+1,end);  // recursively calling for the right part
                    }
                }
                
                int main()
                {
                    int n,i;
                    printf("Enter the no of elements: ");
                    scanf("%d",&n);
                    int *A=(int *)malloc(n*sizeof(int));
                    printf("Enter the values: ");
                    for(i=0;i<n;i++)
                        scanf("%d",&A[i]);
                    quickSort(A,0,n-1);  // calling the function
                    printf("New sorted array is:\n");
                    for(i=0;i<n;i++)
                    printf("%d ",A[i]);
                    return 0;
                }
