#include<iostream>
#include<string.h>
using namespace std;
#define MAX 20

char stack[MAX],infix[MAX],prefix[MAX];
int top=-1;

int precedence(char ch)
{
    if(ch == '+' || ch =='-')
        return(1);
    if(ch == '*' || ch =='/')
        return(2);
    return 0;
}

void push(int pos)
{
    if(top==MAX-1)
        cout<<"Stack is Full"<<endl;
    else
    {
        top++;
        stack[top] = infix[pos];
    }
}

char pop()
{
    char ch;
    if(top<0)
        cout<<"Stack is Full"<<endl;
    else
    {
        ch=stack[top];
        stack[top]='\0';
        top--;
        return(ch);
    }
}

void infixTOprefix()
{
    int i=0,j=0;
    strrev(infix); // Reverse the infix expression
    while(infix[i]!='\0')
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            prefix[j]=infix[i];
            j++;
            i++;
        }
        else if(infix[i]==')')
        {
            push(i);
            i++;
        }
        else if(infix[i]=='(')
        {
            while(stack[top]!=')') // pop till opening bracket is found
            {
                prefix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else  // if the stack if empty, put the operator in stack
        {
            if(top==-1)
            {
                push(i);
                i++;
            }
            else if( precedence(infix[i])<precedence(stack[top]))
            {
                prefix[j] = pop();  // pop the stack top and add it to the prefix string
                j++;
                while(precedence(stack[top])>precedence(infix[i]))
                {
                    prefix[j]=pop();    // Pop the operator
                    j++;
                    if(top < 0)
                        break;
                }
                push(i);
                i++;
            }
            else if(precedence(infix[i])>=precedence(stack[top]))
            {
                push(i);
                i++;
            }
        }
    }
    while(top!=-1)  // At the end remove all the operators from the stack
    {
        prefix[j]=pop();
        j++;
    }
    strrev(prefix);  // Reverse the final string before output
    prefix[j]='\0';
    cout<<"Prefix Expression: "<<prefix<<endl;
}

int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infixTOprefix();
    return 0;
}











