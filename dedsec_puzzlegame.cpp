 #include<stdio.h>
 #include<windows.h>
 #include<stdlib.h>
 #include<conio.h>

 
static int High_score = 500;
int print_A(int a[4][4],int);
int sorted(int a[4][4]);
int getkey( );
int* zero(int a[4][4]);
int move_check(int*,int arrow);
int *b[4][4]; int address(int a[4][4]); int retry (int m,int h);
int start_menu();
int main( )
{	
int moves = 0,*place,arrow ;
if(start_menu()==0)
{
	exit(0);
}
do{
	int a[4][4] = {
					1,4,15,7,
					8,10,2,11,
					14,3,6,13,
					12,9,0,5
//					1,2,3,4,
//					5,6,7,8,
//					9,10,11,12,
//					13,14,15,0
					}; moves = 0; address(a); 

	do{
		 system("CLS");
		 print_A(a,moves);
		  place = zero(a); 
		 switch(getkey())
		 {
		 	case 72:  									//up arrow
			    arrow = 72; printf("\n \t\t\t\t\t\t\t\t\t\t Up arrow is clicked");
			   if(move_check(place,arrow))
			   	{  moves++; 
				   printf(" %d ",*place);
			   		*place = *(place+4);
					 *(place+4) = 0 ;  	
				}                             
		 		break;
		 	case 80:
		 		arrow = 80; printf("\n \t\t\t\t\t\t\t\t\t\t Down arrow is clicked");
			 	if(move_check(place,arrow))
			   	{   moves++;
			   		*place = *(place-4);
					*(place-4) = 0 ;  	
				}                                                                  //down arrow
			 	break;
			case 75:
				arrow= 75;  printf("\n \t\t\t\t\t\t\t\t\t\t left arrow is clicked");
				if(move_check(place,arrow))
				{ moves++;
				  *place= *(place+1);
				  *(place+1) = 0;	
				} 									  //left arrow
				break;
			case 77:
			    arrow=77;  printf("\n \t\t\t\t\t\t\t\t\t\t right arrow is clicked");
				if(move_check(place,arrow))
				{ moves++;
				  *place= *(place-1);
				  *(place-1) = 0;
				}                                       //right arrow
				break;
			default:
				break;			 	
		 }
		
		
	}while(sorted(a)==0);
		
	if(moves<=High_score)
	High_score = moves;
	system("CLS");
	//print_A(a,moves);
	
} while(retry(moves,High_score)==1); 
return 0 ;
}

int print_A(int a[4][4],int moves)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		
		if(i==0)
		{
				printf("\n \t\t\t\t\t   DEDSEC'S  PUZZLE");
				printf("\n\n\n\n");
				printf("\t\t\t\t\t");
				printf("---------------------");
				printf("\n");
		}
			
		for(j=0;j<4;j++)
		{ 	if(j==0)
			printf("\t\t\t\t\t");
			printf("|");
			if(a[i][j]==0)
			{
				printf("    ");
			}
			else if(a[i][j]>9)
			printf(" %d ",a[i][j]);
			else
			printf("  %d ",a[i][j]);
		}
		printf("|");
		printf("\n");printf("\t\t\t\t\t");
		printf("---------------------");
		printf("\n");	
		
	}
	printf("\t\t\t\t\t\t\t\t\t\t Moves = %d \n\n\t\t\t\t\t\t\t\t\t\t HIGH SCORE = %d (moves)",moves,High_score);
}

int sorted(int a[4][4])
{
	int i,j,flag=0,t=0;
	for(i=0;i<16;i++)
	{
		if(*(*a+i)!=0)
			{
				for(j=0;j<16-i;j++)
				{
					if( *(*a+(i+j+1)) !=0)
					{
//						printf(" %d < %d  i =%d j=%d \n",*(*a+i), *(*a+(i+j+1)),i,j);
						if(*(*a+i)<*(*a+(i+j+1)) )
							t=0; 
						else{
							t=1; break;
							}
					}
				}
			} 
	    if(t==1) break;
	}
	//printf(" %d \n",t);
	if(t==0 && a[3][3]==0)
	{
		return 1 ;
	}
	else
	{
		return 0;
	}
}

int getkey( )
{
int ch ;
ch = getch( ) ;
if ( ch == 0 )
{
ch = getch( ) ;
return ch ;
}
return ch ;
}

int* zero(int a[4][4])
{
	int i ,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0)
			return &(a[i][j]);	
		}
	}
}

int address(int a[4][4])
{
	int i, j ;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			b[i][j] = &a[i][j];
		}
	}
}

int move_check(int *p,int arrow)
{
	int i=0,j=0;
	if(arrow==72)  //up arrow
	{
		//printf(" \n*b[3][3]= %d, *b[0][0] = %d, b[3][3]= %d, b[0][0]=%d, p = %d, *p=%d, p+4 =%d, *p+4= %d \n",*b[3][3],*b[0][0],b[3][3],b[0][0],p,*p,p+4,*(p+4));
		if( p+4 <= b[3][3] && p+4 >= b[0][0])
		{
		return	1;
		}		
	}
	else if(arrow==80)  //down arrow
	{
		if( p-4 <= b[3][3] && p-4 >= b[0][0])
		return	1;
	}
	else if(arrow==75)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(b[i][j]==p)
				{
					if(p<=b[i][2]&&p>=b[i][0])
					return 1;
				}
			}	
		}	
	}
	else if(arrow==77)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(b[i][j]==p)
				{
					if(p<=b[i][3]&&p>=b[i][1])
					return 1;
				}
			}	
		}	
	}
		return 0 ;
}

int retry(int m,int h)
{
		int ch = 'n';
	
	printf("\n\n\n\n\t\t\t\t\t\t       CONGRATULATIONS!!!");
	if(m<=h)
	printf("\n\n\t\t\t\t\t   You have completed puzzle at High score!!!");
	else
	printf("\n\n\t\t\t\t\t\tYou have completed the puzzle...");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t score = %d",m);
	printf("\n\n\n\n\t\t\t\t\t\t\tRetry(y/n) ?\n\n\t\t\t\t\t\t\t");
	scanf("%c",&ch);
	if(ch=='n')
	{
		return 0;
	}
	else if(ch=='y')
	{
		return 1;
	}
}

int start_menu()
{
	char ch = '>'; int t =3;
//	char a[2][5];
//	strcpy(a[0],"Start");
//	strcpy(a[1],"Quit");
	do{
		system("CLS");
	printf("\n\n\n\n\n\n\n");
	printf("\n\n\t\t\t\t\t\t\tWELCOME !!!");
	printf("\n\n\t\t\t\t\t\t     DEDSEC'S PUZZLE");
	do{ printf("\n\n\n\t\t\t\t\t\t    %c   START ",ch);
	printf("\n\n\t\t\t\t\t\t        Quit "); t=0;
	}while(1==0);
	switch(getkey())
	{
	case 72:
	printf("\n\n\n\t\t\t\t\t\t    %c   START ",ch);
	printf("\n\n\t\t\t\t\t\t        Quit "); t=0;
		break;
	case 80:
	printf("\n\n\n\t\t\t\t\t\t       START ",ch);
	printf("\n\n\t\t\t\t\t\t      %c  Quit "); t=1;
	break;
	default:
		break;
	}
	printf("\n\n\n\n\n\n\n");
	}while(getkey()==13);
	if(t==0)
	return 1;
	else if(t==1)
	return 0;
}
