//Exercise 12. Variant 1. Yaskovich Dmitry (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//defining header files
#include <stdlib.h>

int filling(int qty, int *array); //functions prototypes
int output(int qty, int *array);
int null(int qty,int *array);
int maximum(int qty, int *array, int *max);

int main(void)//main function
{
	int *array, arraysize,n;
	printf("Enter quantity of elements in array: ");
	scanf("%d", &arraysize);
	array = malloc(n*sizeof(int));
	filling(arraysize,array);
	printf("Enter quantity of elements to be rearranged: ");
	scanf("%d", &n);

	fflush(stdin);//waiting for the user
	getchar();
	return 0;
}

int filling(int qty, int *array)
{
	int i;
	int stime;
	long int ltime;
	ltime=time(NULL);
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qty ; i++)
	{
		array[i]=-RAND_MAX+2*rand();
	}
}

int output(int qty, int *array)//function of output
{
	int i,j,cycles;//declaration of variables
	printf("|   Element   |");
	for (i = 1; i <=qty; i++) //repeats for all elements
	{
		printf(" %10d |",i);//output of element number
		if ((i%5==0)&&(i!=qty)) //catching end of line
		{
			printf("|    Value    |");
			for (j=5; j >=1; j--)//output of values
			{
				printf(" %10d |",(array[i-j]));
			}
			printf("|   Element   |");
		}
		else //or last element
		{
			if (i==qty)
			{
				if (i%5!=0)
				{
					printf("\n");
				}
				printf("|    Value    |");//output of values
				if (i%5==0)
					cycles=5;
				else
					cycles=(i%5);
				for (j=cycles; j >=1; j--)
				{
					printf(" %10d |",array[i-j]);
				}
		     		printf("\n\n"); //indent before next array
		   }
  }
 }
}

int null(int qty, int *array)//function of
{
 int i;//declaration of variables
 for (i = 1; i <=qty; i++)//filling array
 {
  array[i-1]=0;
 }
}

int maximum(int qty, int *array, int *max)
{
 int i;
 *max=0;
 for (i = 1; i <=qty; i++)
 {
  if (max>array[i-1])
  {
   *max=array[i-1];
  }
 }
 printf("Maximum: %d |\n",*max);
}

