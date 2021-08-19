//program to find the Determinant of given matrix

#include<stdio.h>
#include<stdlib.h>

int det(int*,int); 					// returns determinant value
void get_val(int*,int); 				// gets the matrix values from user
int* m_alloc(int*,int,int);				// allocates new dymamic array using malloc

int main()
{
	int n,deta=0,sum=0;
	printf("Enter the array length: ");
	scanf("%d",&n);
	int a[n][n],i=0;
	
	get_val(*a,n);
	
	deta = det(*a,n);
	
	printf("the Det Value is : %d ",deta);	
	
	return 0;
	
}
	
int det(int *a,int n)
{
	int i=0,sum=0,*ptr;
	for(;i<n;i++)	
	{
		if(n==1)
		{
			return *(a);
			
		}
		else
		{
			ptr = m_alloc(a,n,i);
			if(i%2==0)
			{

				sum = sum+ (*(a+i)*det(ptr,n-1));	
			}
			else
			{
				sum = sum- (*(a+i)*det(ptr,n-1));
			}
		}
	}
	return sum;
	
}

int* m_alloc(int* a,int n,int i)
{
	int *ptr,k=0,j=0;
	
	ptr = (int*)malloc(((n-1)*(n-1))*sizeof(int));
	
	for(k=n;k<(n*n);k++)
	{
		if(k%n==i)
		{
			continue;
		}
		else
		{
			*(ptr+j)= *(a+k);
			j++;
		}
	}	

	return ptr;
}


void get_val(int* a,int n)
{
	int i =0 ;
	printf("\n Enter the Array items but %d x %d order : ",n,n);
	for(i=1;i<=(n*n);i++)
	{
		if(i%n==0 && i!=0)
		{
			printf("\t\t\t\t\t ");
		}
		scanf("%d",a+(i-1));
	}
}
