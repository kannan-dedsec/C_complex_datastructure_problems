#include<stdio.h>
#include<stdlib.h>


int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int length = sizeof(a)/4;
	int b[length],i,j, max=0 , min=100000000,maxflag = length,minflag = length;
	
	for(i=0;i<length;i++)
	{
		max =0 ,min = 100000000;
		for(j=0;j<length;j++)
		{
			if(a[j]>max && j != maxflag && a[j]!=0)
			{
				max = a[j];
				maxflag = j;
			}
			if(a[j]<min && j !=minflag&&a[j]!=0)
			{
				min = a[j];
				minflag = j;
			}
		}
		b[i+i] = a[maxflag];
		b[i+i+1] = a[minflag];
		
		a[maxflag]= a[minflag]= 0;
		//printf("max = %d min = %d maxflag = %d minflag = %d \n",max,min,maxflag,minflag);
		printf("%d ",b[i]);
	}
	
	
	
	return 0;
}
