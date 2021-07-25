#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int create_account();
void balance();
void deposit();
void withdrwal();
int validation(char* temp_acc_name,char* temp_acc_password);
int check_account(char* temp_acc_name,int temp_acc_no,char* temp_acc_password);
int x,y,t=0,z;
int temp_acc_no,temp_amount;
char temp_acc_name[20],temp_acc_password[30];
struct banking
{
	int acc_no;
	char acc_name[50];
	char acc_password[20];
	int amount;
}obj[100];
int main()
{
	while(1)
	{
		int choice;
		printf("BANKING\n1.Create Account\n2.Check Balance\n3.Deposit\n4.Withdrawl\n5.Exit\n");
		printf("enter the choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				create_account();
				break;
			}
			case 2:
			{
			    balance();
				break;
			}
			case 3:
			{
				deposit();
				break;
			}
			case 4:
			{
				withdrawl();
				break;
			}
			case 5:exit(1);
			default:printf("Enter valid choice!!");
		}
	}
}
int create_account()
{
	printf("Enter Account holder's name\t");
	scanf("%s",temp_acc_name);
	printf("Enter Account number\t");
	scanf("%d",&temp_acc_no);
	printf("Enter Account password\t");
	scanf("%s",&temp_acc_password);
	x=check_account(temp_acc_name,temp_acc_no,temp_acc_password);
	//y=validation(temp_acc_name,temp_acc_password);
//	printf("%d,%d",x,y);
	if(z!=1)
	{
		strcpy(obj[t].acc_name,temp_acc_name);
		strcpy(obj[t].acc_password,temp_acc_password);
		obj[t].acc_no=temp_acc_no;
		obj[t].amount=0;
		printf("Account created successfully\n");
		t++;
	}
	return 0;
	
}
int check_account(char* temp_acc_name,int temp_acc_no,char* temp_acc_password)
{
	int i;
	for(i=0;i<t;i++)
	{
		if(!(strcmp(obj[i].acc_name,temp_acc_name)))
		{
			if(obj[i].acc_no==temp_acc_no)
			{
				if(!(strcmp(obj[i].acc_password,temp_acc_password)))
				{
					z=1;
					return i;
					
				}
				else
				{
					z=2;
					printf("Password Mismatch\n");
				}
			}
		}
	}
}
void deposit()
{
	printf("enter account holder name\t");
	scanf("%s",&temp_acc_name);
	printf("\nEnter account number\t");
	scanf("%d",&temp_acc_no);
	printf("\nEnter account password\t");
	scanf("%s",&temp_acc_password);
	printf("\nEnter amount to deposit\t");
	scanf("%d",&temp_amount);
	x=check_account(temp_acc_name,temp_acc_no,temp_acc_password);
	if(z==1)
	{
		obj[x].amount+=temp_amount;
		printf("\nRs.%d is deposited successfully\n",temp_amount);
	}
	else if(z==0)
	{
		printf("Sorry!Cannot deposit amount as account doesn't exist!!!\n");
	}
}
void withdrawl()
{
	printf("enter account holder name\t");
	scanf("%s",&temp_acc_name);
	printf("\nEnter account number\t");
	scanf("%d",&temp_acc_no);
	printf("\nEnter account password\t");
	scanf("%s",&temp_acc_password);
	printf("\nEnter amount to withdraw\t");
	scanf("%d",&temp_amount);
	x=check_account(temp_acc_name,temp_acc_no,temp_acc_password);
	if(z==1)
	{
		if(obj[x].amount>temp_amount)
		{
			obj[x].amount-=temp_amount;
			printf("\nRs.%d is withdrawed successfully\n",temp_amount);
			printf("Available balance=%d\n",obj[x].amount);
		}
		else
		{
			printf("Unable to withdraw due to unsufficient balance!!!\n");
		}
	}
	else if(z==0)
	{
		printf("Sorry!Cannot withdraw amount as account doesn't exist!!!\n");
	}
}
void balance()
{
	printf("enter account holder name\t");
	scanf("%s",&temp_acc_name);
	printf("\nEnter account number\t");
	scanf("%d",&temp_acc_no);
	printf("\nEnter account password\t");
	scanf("%s",&temp_acc_password);
	x=check_account(temp_acc_name,temp_acc_no,temp_acc_password);
	if(z==1)
	{
		printf("Available Balance:%d\n",obj[x].amount);
	}
	else if(z==0)
	{
		printf("Sorry!!Account doesn't exist\n");
	}
}
