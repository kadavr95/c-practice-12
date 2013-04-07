//Exercise 12. Variant 1. Yaskovich Dmitry (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//defining header files
#include <stdlib.h>

int filling(int qty, int *array); //functions prototypes
int output(int qty, int *array);
int null(int qty,int *array);
int maximum(int qty, int *array, int *max);
int savetofile(int qty, int *array);
int readfromfile(int *qty, int *array);
int check(int qty, int nmax, int *n);
int replace(int n,int *array);

int main(void)//main function
{
	int *array, arraysize,n,nmax;
	printf("Enter quantity of elements in array: ");
	scanf("%d", &arraysize);
	array = malloc((n+1)*sizeof(int));
	filling(arraysize,array);
	nmax=arraysize/2;
	printf("Enter quantity of elements to be rearranged (it must be less or equal to %d): ",nmax);
	scanf("%d", &n);
	check(arraysize,nmax,&n);
	output(arraysize,array);
	savetofile(arraysize,array);
	null(arraysize,array);
	readfromfile(&arraysize,array);
	replace(n,array);
	output(arraysize,array);
	fflush(stdin);//waiting for the user
	getchar();
	return 0;
}

int replace (int n,int *array)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		array[0]=array[i];
		array[i]=array[i+n];
		array[i+n]=array[0];
	}
}
int check(int qty, int nmax,int *n)
{
	while (nmax<*n)
	{
		printf("This number is not allowed. Enter correct number: ");
		scanf("%d", &*n);
	}
}

int readfromfile(int *qty, int *array)
{
    FILE *filepointer;
	int i=1;
	*qty=0;
	filepointer = fopen("SR12", "r");
	if (filepointer==NULL)
	{
		printf("Error while opening file.\n");
		exit(1);
	}
	else
	{
		while(!feof(filepointer))
		{
			fscanf(filepointer,"%d ",&array[i]);
			i++;
			*qty=*qty+1;
		}
		fclose(filepointer);
	}
}
int savetofile(int qty, int *array)
{
	FILE *filepointer;
	int i;
	filepointer = fopen("SR12", "w");
	if (filepointer==NULL)
	{
		printf("Error while opening file.\n");
		exit(1);
	}
	else
	{
		for (i = 1; i <= qty; i++)
		{
			fprintf(filepointer, "%d ",array[i]);
		}
		fclose(filepointer);
	}
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
			for (j=4; j >=0; j--)//output of values
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
				for (j=(cycles-1); j >=0; j--)
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

