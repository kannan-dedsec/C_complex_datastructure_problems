#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int t=0;

struct MyProfile{
					char Username[20];
					char Password[20];
					char name[20];
					char number[20];
					char email[20];	
					struct MyProfile* next; 	
				};

void PrintProfile(struct MyProfile *prof)
{
	system("CLS");
	printf("\nName : %s",prof->name);
	printf("\nUsername : %s",prof->Username);
	printf("\nPassword : ********",prof->Password);
	printf("\nEmail : %s",prof->email);
	printf("\nNumber : %s",prof->number);
				}	

struct MyProfile* finalnodefinder(struct MyProfile* head)
{
	struct MyProfile* temp1 = head;
	
	while(temp1->next!=NULL)
	{
		temp1= temp1->next;	
	}
	if(temp1->next==NULL)
	{
		return temp1;
	}
	else
	{
		printf("\n something wrong try again \n");
	}


}
struct MyProfile* check(char username[],char passwd[],struct MyProfile* head)
{
	struct MyProfile* temp=head;
	while(temp != NULL)
	{
		if(strcmp(temp->Username,username)==0&&strcmp(temp->Password,passwd)==0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
	
}

int forgotPasswd(struct MyProfile* head)
{
	struct MyProfile* temp5=head;

	int m=0;system("CLS");
	do
	{
		temp5=head;
	char username[20],email[20],passwd[20];
	printf("\n Enter your username : ");
	scanf("%s",username);
	printf("\n Enter your email : ");
	scanf("%s",email);
	//if(NotExist(head,1,username,NULL)==1&&NotExist(head,1,username,NULL)==1)
	//{
		while(temp5!=NULL)
		{
		//	printf("\n struct_username = %s username = %s struct_mail = %s mail = %s\n ",temp5->Username,username,temp5->email,email);
			if(strcmp(temp5->Username,username)==0&&strcmp(temp5->email,email)==0)
			{
				printf("\n Enter the New Password : ");
				scanf("%s",passwd);
				strcpy(temp5->Password,passwd);
				return 0;				
			}
			temp5= temp5->next;
	//	}
		
		}
//		printf("\n struct_username = %s username = %s struct_mail = %s mail = %s\n ",temp5->Username,username,temp5->email,email);
	//else
		printf("\nPlease check your username or email again\n");
		m=1;

 }while(m);

}

void SignIn(struct MyProfile *prof,struct MyProfile *head)
{
	int operation=0,loop=0;
	char username[20],pass[20];	
	struct MyProfile* temp2;	
			do{
				system("CLS");
				printf("\n Please Sign In with registered Credentials \t Users count = %d \n\n",t);
				printf(" Username: ");
				scanf("%s",&username);
				printf(" Password: ");
				scanf("%s",&pass);
				
				if(check(username,pass,head)!=NULL)
				{
					temp2=check(username,pass,head);
					system("CLS");
					break;
				}
				else
				{
					printf("\nWrong Password !! \n 1. try again \n 2. exit \n 3. Forgot password? \n");
					scanf("%d",&operation);
					if(operation==1)
					{
						system("CLS");
						loop=1;
					}
					else if(operation==2)
					{
						exit(0);
					}
					else if(operation==3)
					{
						forgotPasswd(head);
					}
				}
			}while(loop==1);		
		
			
		do{
			printf("\n\n HI %s !!! \n\n 1. My Profile \n 2. exit \n 3. SignIn \n 4. SignUp \n 5. Search \n \t",temp2->name);
			scanf("%d",&operation);
			system("CLS");
		switch(operation)
		{
			case 1:
				PrintProfile(temp2);
				loop=1;
				break;
			case 2:
				exit(0);
				break;
			case 3:
				SignIn(prof,head);
				break;
			case 4:
//				struct MyProfile* next= NULL;
//				next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
				prof =finalnodefinder(head);
//				PrintProfile(prof);
				SignUp(prof,head);
				break;
			case 5:
				search(head);
				loop=1;
				break;			
			default:
				printf("\nYou Have Entered the wrong number, try again :)\n\n");
				loop=1;
				break;			
		}
	}while(loop==1);
	
		
	
}

int NotExist(struct MyProfile* head, int operator,char text[],struct MyProfile* next)
{
	
	struct MyProfile* temp3= head;
	
	switch(operator)
	{
		case 1:
			while(temp3!=next)
			{
			
				if(strcmp(text,temp3->Username)==0)
				{
					//printf("\ntext = %s head->text = %s\n",text,temp3->Username);
					return 1;
					
				}
				temp3 = temp3->next;
			}
			return 0;
			break;
		case 2:
			while(temp3!=next)
			{
				if(strcmp(text,temp3->email)==0)
				{
					return 1;
				}
				temp3 = temp3->next;
			}
			return 0;
			break;
		default:
		printf("\n something wrong please try again");						
	}
}

void SignUp(struct MyProfile *prof,struct MyProfile *head)
{
	if(t==0)
	{
//		struct MyProfile* next= NULL;
//		next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
		prof->next=NULL;
			system("CLS");
	
		printf(" Full Name : ");
		scanf("%s",head->name);

		printf(" User Name : ");
		scanf("%s",head->Username);
		
			
		printf(" Email : ");
		scanf("%s",head->email);
		
		
		printf(" New Password : ");
		scanf("%s",head->Password);
	
		printf(" Mobile Number : ");
		scanf("%s",head->number);
		
		
	}
	else
	{
		struct MyProfile* next= NULL;
		next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
		prof->next=next;
		next->next=NULL;
			system("CLS");
	
		printf(" Full Name : ");
		scanf("%s",next->name);
	
		do{	
		printf(" User Name : ");
		scanf("%s",next->Username);
		
		if(NotExist(head,1,next->Username,next))
		printf("\nthis username is already taken\n");
		
		}while(NotExist(head,1,next->Username,next));
		
		do{
		printf(" Email : ");
		scanf("%s",next->email);
		
		if(NotExist(head,2,next->email,next))
		printf("\n this email is already taken \n");
		
		}while(NotExist(head,2,next->email,next));
		
		printf(" New Password : ");
		scanf("%s",next->Password);
	
		
		printf(" Mobile Number : ");
		scanf(" %s",head->number);
		
		
	}
	t++;
	SignIn(prof,head);	
}

int search(struct MyProfile* head)
{
	struct MyProfile* temp6=head;
	char string[20];
	system("CLS");
	printf("\nEnter the string : ");
	scanf("%s",string);
	
	
	while(temp6!=NULL)
	{
		if(strcmp(string,temp6->Username)==0)
		{
			printf("\n user found : ");
			printf("%s",temp6->Username);
			return 1;
		}
		temp6= temp6->next;
	}
	printf("\n User not found\n");
	
}

int main(int argc, char *argv[]) {
	
	int operation,loop=0;
	struct MyProfile prof;
	struct MyProfile* head;
	head = &prof;
	do{
		printf(" 1. Sign In\n 2. Sign up \n 3. exit \n\t");
		scanf("%d",&operation);
		system("CLS");
		switch(operation)
		{
			case 1:
				if(t==0)
				{
					printf("\n*****No Users Found*****\n");
					exit(0);
				}
				SignIn(&prof,head);
				loop=0;
				break;
			case 2:
				SignUp(&prof,head);
				loop=0;
				break;
			case 3:
				exit(0);
				break;	
			default:
				printf("\nYou Have Entered the wrong number, try again :)\n\n");
				loop=1;
				break;			
		}
	}while(loop==1);
	
	return 0;
}
