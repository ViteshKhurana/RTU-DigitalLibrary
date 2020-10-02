#include<stdio.h>
char stack[50];
int top=-1;
main()
{
	char exp[50],*p,*t;
	char postfix[50],n1;
	int priority(char);
	int i;
	printf("enter an infix exp");
	gets(exp);
	p=exp;
	t=postfix;
	while(*p!=NULL)
	{
		if(*p=='(')
		{
			top++;
			stack[top]=*p;
			p++;
		}
		else if(*p=='+'||*p=='-'||*p=='*'||*p=='/')
		{
			if(top==-1||stack[top]=='(')
			{
				top++;
				stack[top]=*p;
				p++;
			}
			else
			{
				n1=stack[top];
				top--;
				while(priority(n1)>=priority(*p))
				{
					*t=n1;
					t++;
					if(top==-1||stack[top]=='(')
					break;
					else
					{
						n1=stack[top];
						top--;
					}
				}
				if(priority(*p)>priority(n1))
				{
					top++;
					stack[top]=n1;
				}
				top++;
				stack[top]=*p;
				p++;
			}
		}
		else if(isalpha(*p)||isdigit(*p))
		{
			*t=*p;
			t++;
			p++;
		}
		else if(*p==')')
		{
			n1=stack[top];
			top--;
			while(stack[top]!='(')
			{
				*t=n1;
				t++;
				n1=stack[top];
				top--;
			}
			p++;
		}
	}
	while(top!=-1)
	{
		n1=stack[top];
		top--;
		*t=n1;
		t++;
	}
	*t=NULL;
	printf("resultant postfix exp");
	puts(postfix);
}
int priority(char x)
{
	if(x=='+'||x=='-')
	return(1);
	if(x=='*'||x=='/')
	return(2);
}
