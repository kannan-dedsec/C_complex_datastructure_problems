#include<stdio.h>
#include<stdlib.h>
void filler(int *a,int n)
{
	int i=0;
	for(;i<n;i++)
	{
		*(a+i)=99291;
	}
}
void display(int *a,int n)
{
	int i=0;
	printf("\n the updated array que is : ");
	for(;i<n;i++)
	{
		if(*(a+i)==99291)
		{
			printf(" _ ");
		}
		else
		{
			printf(" %d ",*(a+i));	
		}		
	}
}
void frnt(int *a,int n, int front)
{
	int i=0,j=0,temp,t;
	
	if(*(a+i)==99291)
	{
		*(a+i)=front;			
	}
	else
	{	
		for(;i<n;i++)
		{
			if(*(a+i)==99291)
			{
				t=i;
				for(;j<t;j++)
				{
					temp = *(a+(i-1));
					*(a+(i-1)) = 99291;
					*(a+i)= temp;
					i--;
				}
				*(a)= front;
				break;	
			}
			if(i==n-1)
			{
				printf("\n the array is full!!(enter 'r'' to reload)");
				scanf("%d");
			}
		}
	}
	
}
void bck(int *a,int n,int back)
{
	int i;
	
		for(i=n-1;i>=0;i--)
		{
			if(*(a+i)==99291)
			{
				continue;			
			}
			else
			{
				*(a+(i+1))=back;
				break;
			}	
		}
}
void del_front(int *a,int n, int front)
{
	
}
void del_back(int *a,int n,int back)
{
	
}


int main()
{
	int n,dec,loop=0,front=0,back=0;
	printf("Enter the double ended que length: ");
	scanf("%d",&n);
	
	int a[n];
	
	filler(a,n); // fill the array with zero 
	
	do
	{
		system("cls");	
	display(a,n); // display the array elements 
	
	printf(" \n\nEnter \n1. to add elements in front \n 2. to add elements in rear \n 3. to delete an element in front \n 4. to delete an element in rear \n 5. Quit  \n\n\t\t");
	scanf("%d",&dec);
	
	switch(dec)
	{
		case 1:
			printf(" \n Enter the element to add : ");
			scanf("%d",&front);
			frnt(a,n,front);
			break;
		case 2:
			printf(" \n Enter the element to add : ");
			scanf("%d",&back);
			bck(a,n,back);
			break;
		case 3:
			printf(" \n Enter the element to delete : ");
			scanf("%d",&front);
			del_front(a,n,front);
			break;
		case 4:
			printf(" \n Enter the element to delete : ");
			scanf("%d",&back);
			del_back(a,n,back);
			break;
		case 5:
			loop=1;
			break;
		default:
			printf("\n wrong input, try again!!!");		 			
	}
	
	}while(loop==0);
	
}
