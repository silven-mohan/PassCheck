/** PassCheck: Password Strength Checker **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main()
{
	int len, strength;
	char pass[100];
	system("cls");
	printf("Enter your password:");
	gets(pass);
	strength=Passchecks(pass);
	if (strength<3)
	{
		printf("\nYour Password Strength is: Poor.");
	}
	else if ((strength<=4)&&(strength>3))
	{
		printf("\nYour Password Strength is: Moderate.");
	}
	else if (strength>4)
	{
		printf("\nYour Password Strength is: Strong.");
	}
}

int Passchecks(char passc[100])
{
	/* Checks */
	int f=0, i, len, lt=1, u=0, l=0, d=0, p=0, s=0;
	len=strlen(passc);
	if (len>=8)
	{
		f++;
		lt=0;
	}
	for(i=0;i<=len;i++)
	{
		if ((islower(passc[i]))!=0)
		{
			f++;
			l=1;
			break;
		}
	}
	for(i=0;i<=len;i++)
	{
		if ((isupper(passc[i]))!=0)
		{
			f++;
			u=2;
			break;
		}
	}
	for(i=0;i<=len;i++)
	{
		if ((isdigit(passc[i]))!=0)
		{
			f++;
			d=3;
			break;
		}
	}
	for(i=0;i<=len;i++)
	{
		if ((ispunct(passc[i]))!=0)
		{
			f++;
			p=4;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if ((isspace(passc[i]))!=0)
		{
			f++;
			s=5;
			break;
		}
	}
	
	if(lt!=0)
	{
		printf("\nYour Password length is less than 8 Characters.");
	}
	if(l!=1)
	{
		printf("\nYour Password is missing Lowercase Letters.");
	}
	if(u!=2)
	{
		printf("\nYour Password is missing Uppercase Letters.");
	}
	if(d!=3)
	{
		printf("\nYour Password is missing Digits.");	
	}
	if(p!=4)
	{
		printf("\nYour Password is missing Special Characters.");
	}
	if(s!=5)
	{
		printf("\nYour Password is missing Spaces.");
	}
	return(f);	
}
