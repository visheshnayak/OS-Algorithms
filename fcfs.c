#include<stdio.h>

struct process
{
	int at, bt;
	int st, ft;
	int wt, tat;
	char name;
};

int max(int a, int b)
{
	//Declarations
	
	//Initializations
	
	//Logic
	if (a>b)
		return (a);
	else
		return (b);
}

void main()
{
	//Declarations
	struct process pr[5];
	int i;
	float avgtat, avgwt;
	char temp;

	//Initializations
	avgtat = 0.0; avgwt = 0.0;

	//Logic
	printf("\nEnter the details of the process :\n");
	
	for(i=0;i<5;i++)
	{
		//initializations to be done here

		printf("\nName of process %d : ", i+1);
		scanf("%c",&(pr[i].name));

		/*
		(printf("\nArrival time of process %d : ",i+1);
		scanf("%d",&(pr[i].at));
		*/
		pr[i].at = 0;

		printf("\nBurst time of the process %d : ",i+1);
		scanf("%d",&(pr[i].bt));

		//for the first iteration the finish time should be 0
		if ( i==0 )
		{
			pr[i].st = max(0 , pr[i].at);
		}
		else
		{
			pr[i].st = max(pr[i-1].ft , pr[i].at);
		}
		
		pr[i].wt = pr[i].st - pr[i].at;
		pr[i].tat = pr[i].wt + pr[i].bt;
		pr[i].ft = pr[i].st + pr[i].bt;
		
		//for averages
	
		avgtat = avgtat + pr[i].tat;
		avgwt = avgwt + pr[i].wt;

		//For character buffer (can be removed if the code is working properly without it)
		scanf("%c",&temp);
	}
		avgtat = avgtat/5.0;
		avgwt = avgwt/5.0;
	
	//for printing the table
	
	printf("\nPR\tAT\tBT\t|\tST\tFT\t|\tWT\tTAT\t|");
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%c\t", pr[i].name);
		printf("%d\t", pr[i].at);
		printf("%d\t|\t", pr[i].bt);

		printf("%d\t", pr[i].st);
		printf("%d\t|\t", pr[i].ft);

		printf("%d\t", pr[i].wt);
		printf("%d\t|\t\n", pr[i].tat);
	}
	printf("\n\nAverage waiting time: %f", avgwt);
	printf("\n\nAverage turn around time: %f\n", avgtat);
}
