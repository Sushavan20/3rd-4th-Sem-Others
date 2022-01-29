#include <iostream>
using namespace std;
#define SIZE 10

char postfix[SIZE];
int top=-1;
int stack[SIZE];

void push (int n)
{
    if (top<SIZE-1)
        stack[++top]=n;
    else
        cout<<"Stack is full."<<endl;
}

int pop()
{
    int n;
    if (top>-1)
    {
        n=stack[top];
        stack[top--]=-1;
        return n;
    }
    else
        cout<<"Stack is Empty."<<endl;
}

int main ()
{
    int i,a,b,result,Eval;
    char ch;
    for (i=0;i<SIZE;i++) //initialize by -1
        stack[i]=-1;
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    for (i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
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



