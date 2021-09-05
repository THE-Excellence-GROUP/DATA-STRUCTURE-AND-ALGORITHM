#include <stdio.h>

void tower(int n,char beg,char aux,char end)
{
    if(n==1)
    {
        printf("Shift %d from %c to %c\n",n,beg,end);
        return;
    }
    tower(n-1,beg,end,aux);
    printf("Shift %d from %c to %c\n",n,beg,end);
    tower (n-1,aux,beg,end);
}

int main()
{
    int n;
    char beg='b',aux='a',end='d';
    printf("Enter the no of plates: ");
    scanf("%d",&n);
    tower(n,beg,aux,end);
    return 0;
}