#include<stdio.h>
#include<stdlib.h>
char *stack=NULL;
int top=-1;
int n=-1;

void push(char c)
{
    if(top==n-1)
    {
        printf("overflow ! ");
        return;
    }
    else
        stack[++top]=c;
}
char pop()
{
    if(top==-1)
    {
        printf(" underflow ! ");
        return '0';
    }
    else
        return stack[top--];
}
char peek()
{
    if(top==-1)
    {
        printf(" underflow ! ");
        return '0';
    }
    else 
        return stack[top];
}
int precedence (char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/'||c=='%')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
void infix_postfix(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        char c=exp[i];
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9')
            printf("%c",c);
        else if(c=='(')
            push(c);
        else if(c==')')
        {
            while(peek()!='('&& top!=-1)
                printf("%c",pop());
            pop();
        }
        else{
            while(top!=-1&&precedence(c)<=precedence(peek()))
                printf("%c",pop());
            push(c);
        }
    }
    while(top!=-1)
        printf("%c",pop());
}
int main()
{
    char exp[100];
    printf("enter string :");
    scanf("%s",&exp);
    int n=0;
    while(exp[n]!='\0')
        n++;
    stack=(char*) calloc(n, sizeof(char));
    printf(" infix: %s  postfix:",exp);
    infix_postfix(exp); 
    return 0;
}