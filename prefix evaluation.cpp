#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 20

char prefix[MAX];
int top=-1;
int Stack[MAX];

int push(int n)
{
    if (!(top==MAX-1)) //Not Full condition
    {
        top++;
        Stack[top]=n;
    }
}

int pop()
{
    int n;
    if (!(top==-1)) //Not empty condition
    {
        n=Stack[top];
        top--;
        return n;
    }
}

int main ()
{
    int i,a,b,result,Eval;
    char ch;
    cout<<"Enter prefix expression: ";
    cin>>prefix;
    strrev(prefix);
    for (i=0;prefix[i]!='\0';i++)
    {
        ch=prefix[i];
        if (isdigit(ch))
            push(ch-'0');
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            b=pop();
            a=pop();
            switch(ch)
            {
            case '+':
                result=a+b;
                break;
            case '-':
                result=a-b;
                break;
            case '*':
                result=a*b;
                break;
            case '/':
                result=a/b;
                break;
            }
            push(result);
        }
    }
    Eval=pop();
    cout<<"Result= "<<Eval<<endl;
    return 0;
}





