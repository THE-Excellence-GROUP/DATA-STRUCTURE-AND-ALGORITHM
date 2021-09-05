#include <iostream>
using namespace std;
int main()
{
    string ex,temp;
    int top=-1,i;
    string st[10];
    cout<<"Enter the prefix expression: ";
    cin>>ex;
    for(i=ex.length()-1;i>=0;i--)
    {
        if(ex[i]=='^' || ex[i]=='/' || ex[i]=='*' || ex[i]=='+' || ex[i]=='-')
        {
            temp=st[top];
            top--;
            temp+=st[top];
            top--;
            temp+=ex[i];
            top++;
            st[top]=temp;
        }
       else
       {
            top++;
            st[top]=ex[i];
       }
    }
    cout<<"Postfix expression: "<<st[top];
    return 0;
}