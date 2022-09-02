//final_project


#include <stdio.h>
#include <stdlib.h>

 typedef struct
{
	char name[100];
	char address[50];
	int age;
	int bank_id;
	int guardian;
	int guardian_national_id;
	char activation[];
	int balance;
	int password;
	
	
}Bank_acc;

 



int main(void)
{
	
	printf("*************Welcome**************\n");
	
	printf("for admin please enter 1 \n");
	printf("for user  please enter 2 \n");
	
	int choice;
	
	scanf("%d",&choice);
	
	
	if (choice == 1)
	{
		printf("please choose");
		printf("1-Create new account\n");
		printf("2-Open existing accoun\nt");
		printf("3-exit system\n");
		int pressed;
		scanf("%d",&pressed);
		if (pressed==1)
		{
			printf("enter fullname");
			char*ptr = (char*) malloc(1 *sizeof(char));
			for(int i =0 ;i<sizeof(char);i++)
			{
				scanf("%s",&(*ptr[i]));
				
				
			}
			
			
			
		}
		else if(pressed==2)
		{
			printf("please enter the username : ")
			int username ;
			scanf("%d",&username);
			printf("please enter the password");
			int password ;
			scanf("%d",&password);
			
			if (username == )
			
		}
		else 
		{
			
			
			
			
		}
		
		
	}
	else if(choice == 2)
	{
		printf("please choose");
		printf("1-Make Transaction");
		printf("2-Change Account password");
		printf("3-Get Cash ");
		printf("4Deposit in account ");
		printf("5-Return to main menu");
		
		
	}
	else 
	{
		printf("wrong choice ..try again");
		
		};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}