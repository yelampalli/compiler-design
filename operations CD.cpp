#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int i,ic=0,m,cc=0,oc=0,j;
	char b[30],op[30],id[30],con[30];
	printf("Enter the string: ");
	scanf("%[^\n]s",&b);
	for(i=0;i<strlen(b);i++)
	{
		if(isspace(b[i]))
		{
			continue;
		}
		else if(isalpha(b[i]))
		{
			id[ic]=b[i];
			ic++;
		}
		else if(isdigit(b[i]))
		{
			m=b[i]-'0';
			i=i+1;
			while(isdigit(b[i]))
			{
				m=m*10+(b[i]-'0');
				i++;
			}
			i=i-1;
			con[cc]=m;
			cc++;
		}
		else
		{
			if(b[i]=='*')
			{
				op[oc]='*';
				oc++;
			}
			else if(b[i]=='-')
			{
				op[oc]='-';
				oc++;
			}
			else if(b[i]=='+')
			{
				op[oc]='+';
				oc++;
			}
			else if(b[i]=='=')
			{
				op[oc]='=';
				oc++;
			}
		}
	}
	printf("Identifiers: ");
	for(j=0;j<ic;j++)
	{
		printf("%c ",id[j]);
	}
	printf("\n Constants: ");
	for(j=0;j<cc;j++)
	{
		printf("%d ",con[j]);
	}
	printf("\n Operators: ");
	for(j=0;j<oc;j++)
	{
		printf("%c ",op[j]);
	}
}
