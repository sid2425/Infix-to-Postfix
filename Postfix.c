#include<stdio.h>
#define SIZE 100
int top=-1;
char item[SIZE];
void push(char data)
{
    if(top==SIZE-1)
    {
        printf("Stack is Full\n");
    }
    else 
    {
        top++;
        item[top]=data;
    }
}
char pop()
{
    if(top==-1)
        printf("Stack is Empty\n");
    else 
    {
        char data=item[top];
        top--;
        return data;
    }
    return 0;
}
int isOperand(char x)
{
    if(x=='+' || x=='-'||x=='$'||x=='*'||x=='/'||x=='('||x==')')
        return 0;
    else 
        return 1;
}
int prec(char left,char right)
{
    if(left=='('||right=='(')
        return 0;
    if(right==')')
        return 1;
    
    if(left=='*' || left=='/')
        {
            if(right=='*' ||right=='/'  ||right=='+' ||right=='-' )
                return 1;
            else 
                return 0;
        }
        if(left=='+' || left=='-')
        {
            if(right=='+' ||right=='-' )
                return 1;
            else 
                return 0;
        }
        if(left=='$')
        {
            return 1;
        }
        else 
            return 0;
}
void convert(char infix[],char postfix[])
{
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        /* code */
        if(isOperand(infix[i]))
            {
                postfix[j++]=infix[i];
            }
        else 
        {
            while (top!=-1 && prec(item[top],infix[i]))
            {
                /* code */
                postfix[j++]=pop();
            }
            if(infix[i]==')')
                pop();
            else 
                push(infix[i]);
        }
    i++;
    }
    while (top!=-1)
    {
        /* code */
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void main()
{
    char infix[SIZE],postfix[SIZE];
    printf("Please enter the infix string:");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("Postfix expression is:%s",postfix);
}
