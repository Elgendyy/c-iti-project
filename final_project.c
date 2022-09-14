
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

 #include "project.h"






struct pass {
    char username[50];
    int age;
    char fname[20];
    char lname[20];
    char fathname[20];
	char Guardian[50];
	long int  Guardian_National_ID;
    char address[50];
	
	int NationalID;
	
    char ACCOUNT_STATUS[20];
};
 
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};
 
struct userpass {
    char password[50];
};

 
int main(void)
{
    int choice=0;
    int x =0;
    int y=0;
    
 
    
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
   
 
    printf("**********************************\n\n");
 
    printf("PLEASE CHOOSE \n");
	printf("1-ADMIN..\n");
	printf("2-USER..\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1 :
		
    printf("1.... CREATE A BANK ACCOUNT\n\n");
 
    printf("2.... OPEN EXISTING ACCOUNT\n\n");
   
	printf("3.... MAKE TRANSACTION\n\n");
	
	printf("4.... DEPOSIT\n\n");
	
	printf("5.... GET CASH\n\n");
	
    printf("6.... EXIT SYSTEM\n\n");
 
    printf("\n\nENTER YOUR CHOICE..");
 
    scanf("%d", &choice);
	
    switch (choice) {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        transfermoney();
        break;
	case 4:
		login_user();
		deposit();
	break;	
	case 5:
	login_user();
	Get_cash();
		
		
		break;
		case 6: 
		exit(0);
		break;
	}
        getch();
		 case 2:
			login_user();
			printf("1....MAKE TRANSACTION\n\n");
			printf("2....CHANGE ACCOUNT PASSWORD\n\n");
			printf("3....Deposit IN ACCOUNT\n\n");
			printf("4....Exit SYSTEM\n\n");
			printf("PLEASE CHOOSE ......");
			
		scanf("%d",&y);
		switch(y)
		{
			case 1 :
				transfermoney();
			break;
			
			case 2: 
			change_password();
			break;
			case 3:
			login_user();
			deposit();
			break;
			
			case 4:
			login_user();
			Get_cash();
		
			break;
			case 5:
			exit(0);
			break;
		}
			 
    }
	}

		
 
void account(void)
{
    char password[20];
	static long int BANK_ID = 123456789;
    char ch;
    FILE *fp;
    struct pass u1;
 
    struct userpass u2;
 
    
    fp = fopen("username.txt", "ab");
 
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
 
    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname);
 
    printf("\n\n\nLAST NAME..");
    scanf("%s", &u1.lname);
 
    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fathname);

 
    printf("\n\nADDRESS..");
    scanf("%s", &u1.address);
 
    printf("\n\nNATIONAL ID..");
    scanf("%s", &u1.NationalID);
 
 
    
    printf("\nAGE-");
    scanf("%d", &u1.age);
   if (u1.age < 21)
   {
	   printf("\n\nENTER Guardian NAME");
	   scanf("%s",&u1.Guardian);
	   
	   printf("\n\nENTER Guardian_National_ID");
	   scanf("%d",&u1.Guardian_National_ID);
	   
	   
   }
    printf("\n\nYOUR BANK ID..%d",BANK_ID);
   
 
	BANK_ID ++;
	
	printf("\n\n ACCOUNT STATUS IS ACTVE");
	
    printf("\n\nUSERNAME.. ");
    scanf("%s", &u1.username);
 
    printf("\n\nPASSWORD..");
 
   
    for (int i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            u2.password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
 
  
    fwrite(&u1, sizeof(u1),1, fp);
	fwrite(&u2, sizeof(u2),1, fp);
  
    fclose(fp);
 
    
    accountcreated();
}
 

void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf(
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....\n\n");
 
 
    printf("ACCOUNT CREATED SUCCESSFULLY....\n");

 
    printf("Press enter to login\n\n");
 
    getch();
    login();
}
 

void login(void)
{
    system("cls");
 
    char username[50];
    char password[50];
 
    int i;
    char ch;
    FILE *fp;
    struct pass u1;
    struct userpass u2;
 
    fp = fopen("username.txt",
               "rb");
 
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE\n");
    }
   
    printf(" ACCOUNT LOGIN \n");
    
    printf("***********************************************"
           "********************************\n");
 
  
    printf("==== LOG IN ====");
 
    
    printf("USERNAME.. \n");
    scanf("%s", &username);
 
   
    printf("PASSWORD..\n");
 
  
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
 
        else
            break;
    }
 
    while (fread(&u1, sizeof(u1), 1, fp)&&fread(&u2, sizeof(u2), 1, fp)) {
        if (strcmp(username,u1.username) == 0 && strcmp(password,u2.password)) {
            loginsu();
            display(username);
        }
    }
 
    
    fclose(fp);
}
void login_user(void)
{
    system("cls");
 
    char username[50];
    char password[50];
 
    int i;
    char ch;
    FILE *fp;
    struct pass u1;
    struct userpass u2;
 
    fp = fopen("username.txt",
               "rb");
 
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE\n");
    }
   
    printf(" ACCOUNT LOGIN \n");
    
    printf("***********************************************"
           "********************************\n");
 
  
    printf("==== LOG IN ====");
 
    
    printf("USERNAME.. \n");
    scanf("%s", &username);
 
   
    printf("PASSWORD..\n");
 
  
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
 
        else
            break;
    }
 
    while (fread(&u1, sizeof(u1), 1, fp)&&fread(&u2, sizeof(u2), 1, fp)) {
        if (strcmp(username,u1.username) == 0 && strcmp(password,u2.password)) {
            loginsu();
            display(username);
        }
    }
 
    
    fclose(fp);
}




void change_password(void)
{
	char ch;
	FILE*fp;
	char password1[50];
	char password[50];
	struct userpass u2 ; 
	fp = fopen("username.txt",
               "rb");
	printf("ENTER OLD PASSWORD\n\n");
			   
	  for (int i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password1[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
		else 
		{
			break;
		}
		}
while (fread(&u2, sizeof(u2), 1, fp))
{
	 if (strcmp(password1,u2.password)){
		 
	 
		
	printf("ENTER NEW PASSWORD\n\n");
			   
	   for (int i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password1[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
		else 
		{
			break;
		}
		}
		
		}
		break;
		}
    
	strcpy((u2.password),password);
	
	system("cls");
	printf("password changed\n");
	
}
 

void loginsu(void)
{
   /*  FILE* fp;
    int i;
    struct pass u1; */
    system("cls");
    printf("Fetching account details.....\n");
   
    printf("LOGIN SUCCESSFUL....\n");

    printf("Press enter to continue\n");
 
    getch();
}
 

void display(char username1[])
{
    system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("username.txt", "rb");
    struct pass u1;
 
    if (fp == NULL) {
        printf("error in opening file\n");
    }
 
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username1,
                   u1.username)
            == 0) {
            
            printf("WELCOME\n\n, %s %s",
                   u1.fname, u1.lname);
            
            printf("..........................\n");
           
            printf("==== YOUR ACCOUNT INFO ====\n");
            
            printf("***************************\n");
         
            printf("NAME..%s %s\n\n", u1.fname,
                   u1.lname);
 
     
            printf("FATHER's NAME\n\n..%s %s",
                   u1.fathname);
 
 
           
            printf("AGE.. %d\n\n",
                   u1.age);
 
          
            printf("ADDRESS..%s\n\n", u1.address);
 
            printf("National ID..%d\n\n",
                   u1.NationalID);
        }
    }
 
    fclose(fp);
 
 
   
    printf(" HOME \n\n");

    printf("******\n\n");

    printf(" 1....CHECK BALANCE\n\n");
    printf(" 2....TRANSFER MONEY\n\n");
    printf(" 3....LOG OUT\n\n");
    printf(" 4....EXIT\n\n");
 
    printf(" ENTER YOUR CHOICES..\n\n");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalance(username1);
        break;
 
    case 2:
        transfermoney();
        break;
 
    case 3:
        logout();
        login();
        break;
 
    case 4:
        exit(0);
        break;
    }
}
 

void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
 
    fp = fopen("username.txt", "rb");
 

    fm = fopen("mon.txt", "ab");
 
   
    printf("---- TRANSFER MONEY ----\n\n");
 
    printf("========================\n\n");
 
    
    printf("FROM (your username).. \n\n");
    scanf("%s", &usernamet);
 
 
    printf(" TO (username of person)..\n\n");
    scanf("%s", &usernamep);
 
   
    while (fread(&u1, sizeof(u1),
                 1, fp))
 
    {
        if (strcmp(usernamep,
                   u1.username)
            == 0) {
            strcpy(m1.usernameto,
                   u1.username);
            strcpy(m1.userpersonfrom,
                   usernamet);
        }
    }
 

    printf("ENTER THE AMOUNT TO BE TRANSFERRED..\n\n");
    scanf("%d", &m1.money1);
 
    
    fwrite(&m1, sizeof(m1),
           1, fm);
 
    
    printf(
        "--------------------------------------------------"
        "--------------------------------------------\n\n");
 
  
    printf(
        "--------------------------------------------------"
        "--------------------------------------------\n\n");
 
    
    printf("transfering amount, ..\n\n");
 
  
   
 
  
    printf("AMOUNT SUCCESSFULLY TRANSFERRED....\n\n");
    getch();
 
    
    fclose(fp);
    fclose(fm);

    display(usernamet);
}
 

void checkbalance(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;
 
    fm = fopen("mon.txt", "rb");
 
    printf("==== BALANCE DASHBOARD ====\n\n");

    printf("***************************\n\n");

    printf("S no.\n\n");

    printf("TRANSACTION ID\n\n");

    printf("AMOUNT\n\n");
 
    while (fread(&m1, sizeof(m1),
                 1, fm)) {
        if (strcmp(username2,
                   m1.usernameto)
            == 0) {
            
            printf("%d", i);
            i++;
        
            printf("%s", m1.userpersonfrom);
 
           
            printf("%d", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }
 
   
    printf("TOTAL AMOUNT\n\n");
 
   
    printf("%d", summoney);
 
    getch();
 
    fclose(fm);
    display(username2);
}
 

void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out\n\n");
 
    

    printf("Sign out successfully..\n");
 
    printf("press any key to continue..\n\n");
 
    getch();
}
	
		void Get_cash(void)
	{
				FILE* mo;
		mo = fopen("mon.txt", "rb");
		int summoney =0 ; 
		
		int money ; 
		printf("please enter the money you need to deposit ...\n\n");
		scanf("%d",&money);
		
		 fwrite(&money,sizeof(money),1,mo);
		 if(fread(&summoney,sizeof(summoney),1,mo)<money)
		 {
			 printf("you dont have enouph money \n\n");
			 
		 }
		 else
		 {
            summoney = summoney -money;
        printf("your total money is....%d \n\n",summoney);
		 fwrite(&summoney,sizeof(summoney),1,mo);
		getch();
		 }
		
		
		
	}
	void deposit (void)
	{
		
		FILE* mo;
		mo = fopen("mon.txt", "rb");
		int summoney =0 ; 
		
		int money ; 
		printf("please enter the money you need to deposit ...\n\n");
		scanf("%d",&money);
		 fwrite(&money,sizeof(money),1,mo);
            summoney = summoney +money;
        printf("your total money is.... %d\n\n",summoney);
		fwrite(&summoney,sizeof(summoney),1,mo);
		getch();
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
