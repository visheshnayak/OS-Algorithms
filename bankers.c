#include<stdio.h>
#include<stdlib.h>

int claim[10][3], allocn[10][3], need[10][3];
int resource[3], available[3], check[10];
int n;

void input(void)
{
	//Declarations
	int i, j;
	
	//Initializations
	
	//Logic
	printf("\nEnter the no. of processes: ");
	scanf("%d", &n);
	printf("\nEnter the values for the processes' claim: ");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",i);
		for(j=0;j<3;j++)
		{
			scanf("%d",&(claim[i][j]));
		}
	}
	
	printf("\nEnter the values that are allocated for the processes: ");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",i);
		for(j=0;j<3;j++)
		{
			scanf("%d",&(allocn[i][j]));
		}
	}
	
	printf("\nNow enter the resource vector : ");
	for(i=0;i<3;i++)
		scanf("%d", &resource[i]);
}

void calculations(void)
{
	//Declarations
	int i, j;
	int total[3] = {0,0,0};
	
	//Initializations
	
	//Logic	
	for(i=0;i<n;i++)	//for need matrix
	{
		for(j=0;j<3;j++)
		{
			need[i][j] = claim[i][j] - allocn[i][j];
		}
	}
	
	for(i=0;i<n;i++)	//to find the total allocated matrix
	{
		for(j=0;j<3;j++)
		{
			total[j] = total[j] + allocn[i][j];
		}
	}
	
	for(j=0;j<3;j++)	//to subtract from the resource matrix
	{
		available[j] = resource[j] - total[j];
	}
}

void show(void)
{
	//Declarations
	int i, j;
	
	//Initializations
	
	//Logic
	printf("\nNeed matrix: \n");	//Need matrix
	for(i=0;i<n;i++)
	{
		printf("P%d\t", i);
		for(j=0;j<3;j++)
		{
			printf("%d\t", need[i][j]);
		}
		printf("\n");
	}
	
	printf("\nAvailable matrix: \n");	//Resource matrix
	for(i=0;i<3;i++)
		printf("\t%d",available[i]);
}

void banker(void)
{
	//Declarations
	int i, j, flag, count, prevcount;
	char dummy;
	
	//Initializations
	prevcount = -1;
	flag = 0;
	count = 0;
	
	//Logic
	printf("\n\n***Bankers Algorithm***\n");
	while( flag == 0 )
	{
		for(i=0;i<n;i++)
		{
			prevcount = count;	//For deadlock detection
			if( need[i][0] <= available[0] && need[i][1] <= available[1] && need[i][2] <= available[2]  )
			{
				if ( check[i] != 1 )
				{
					printf("\nAllocating to process P%d", i);
					for(j=0;j<3;j++)
					{
						available[j] = available[j] + need[i][j];	//adding the required resource
						need[i][j] = need[i][j] - available[j];		//subtracting from the need matrix
					}
					check[i] = 1;	//Making the process marked as completed
					
					count++;	//To stop the loop
					if( count == n )
						flag = 1;
				}
				
				if ( prevcount == count )	//For deadlock detection
				{
					if ( check[n-1] = 1 )
						exit(1);
					
					printf("\nDeadlock has been encountered!!! Exiting...\n");
					exit(2);
				}
			}
		}
	}
}

void main()
{
	input();
	calculations();
	show();
	banker();
	
	printf("\n");
}
