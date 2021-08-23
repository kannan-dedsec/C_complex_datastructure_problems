#include<stdio.h>
#include<stdlib.h>


int row_check(int (*a)[9])
{
	int i,j,t,k=0;
	for(i=0;i<9;i++)
	{
		for(j=1;j<=9;j++)
		{
			for(t=0;t<9;t++)
			{
				if(*(*(a+i)+t)==j)
					{
						//printf(" %d ",*(*(a+i)+t));
						k++;
						break;	
					}                              	
			}		
		}
		//printf(" %d ",k);	
	}
	if(k==9*9)
		return 1;
		else
		return 0;
	
	
}
int col_check(int (*a)[9])
{
	int i,j,t,k=0;
	for(i=0;i<9;i++)
	{
		for(j=1;j<=9;j++)
		{
			for(t=0;t<9;t++)
			{
				//printf(" %d ",*(*(a+t)+i));

				if(*(*(a+t)+i)==j)
					{
						//printf(" %d ",*(*(a+i)+t));
						k++;
						break;	
					}                              	
			}
		//	printf("\n");		
		}
		//printf(" %d ",k);	
	}
	if(k==9*9)
		return 1;
		else
		return 0;
		
		return 0;	
}
int grid_check(int (*a)[9])
{
	int i,j,k,l,m,t=0;
	
	for(i=0;i<9;i=i+3)
	{
		for(j=0;j<9;j=j+3)
		{
			for(k=1;k<=9;k++)
			{
				//printf("\n %d \n",k);
				for(l=0;l<3;l++)
				{
					for(m=0;m<3;m++)
					{
						//printf(" %d ",*(*(a+i+l)+(m+j)));
						if(*(*(a+i+l)+(m+j)) ==k)
						{
								t++;
							//	break; 
						}		
					}
				//	printf("\n");	
				}
				//	printf("\n");
			}
				
		}
		//printf("-%d-",t);
	}
	//printf("-%d-",t);
	if(t == 9*9)
	return 1;
	else
	return 0;
}
int check(int (*a)[9])
{
	int row,col,grid;
	row=col=grid=0;
	
	row = row_check(a);
	col = col_check(a);
	grid = grid_check(a);
	printf(" row = %d col = %d grid = %d",row,col,grid);
	return row+col+grid;	
}
int main()
{
	int a[9][9]={
					5,3,4,6,7,8,9,1,2,
					6,7,2,1,9,5,3,4,8,
					1,9,8,3,4,2,5,6,7,
					8,5,9,7,6,1,4,2,3,
					4,2,6,8,5,3,7,9,1,
					7,1,3,9,2,4,8,5,6,
					9,6,1,5,3,7,2,8,4,
					2,8,7,4,1,9,6,3,5,
					3,4,5,2,8,6,1,7,9
				};
				
	int is_comp = check(a);	
	
	//printf(" %d ",is_comp);
	if(is_comp==3)
	printf("\n\n the sudoku is solved !!!");	
	else
	printf("\n\n sudoku not solved yet :(");
	
	return 0;
}

