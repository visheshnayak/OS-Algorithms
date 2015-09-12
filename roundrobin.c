#include<stdio.h>

struct process
{
	int at, bt;
	int st, ft, tat, wt, rt;
	char name;
} pr[5], iproc[5];

int ts;
float avgwt, avgtat;

void displaytable()
{
	//Declarations
	int i;
	
	//Initializations
	
	//Logic
	printf("\nPR\tAT\tBT\t|\tRT\t|\tWT\tTAT\t|");
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%c\t", iproc[i].name);
		printf("%d\t", iproc[i].at);
		printf("%d\t|\t", iproc[i].bt);

		printf("%d\t", iproc[i].rt);
		printf("|\t");

		printf("%d\t", iproc[i].wt);
		printf("%d\t|\t\n", iproc[i].tat);
	}
	printf("\nAverage Waiting time: %f", avgwt);
	printf("\nAverage Turn Around Time: %f", avgtat);
}

void input()
{
	//Declarations
	int i;
	char dummy;
	
	//Initializations
	
	//For input
	printf("\nEnter the time slice to be given to each of the process : ");
	scanf("%d",&ts);
	printf("\nEnter the process details: (all arrival time is assumed to be zero) \n");
	for ( i=0;i<5;i++ )
	{
			
		//buffer
		scanf("%c", &dummy);
		
		printf("\nName of process %d : ", i+1);
		scanf("%c",&(pr[i].name));

		pr[i].at = 0;	//Static

		printf("\nBurst time of the process %d : ",i+1);
		scanf("%d",&(pr[i].bt));
		
	}
	
	//To make another copy of the array
	for(i=0;i<5;i++)
		iproc[i] = pr[i];
}

void displayq()
{
	//Declarations
	int i;
	
	//Initializations
	
	//Logic
	printf("\n\t");
	for(i=0;i<5;i++)
	{
		printf("%c --> ", pr[i].name);
	}
	printf("END");
}

void roundrobin()
{
	//Declarations
	struct process temp;
	int i, j, k, l, present, clock;
	
	//Initializations
	i=0;
	present = 5;
	clock = 0;
	
	//Logic
	while( present != 0 )
	{		
		for( i=0;i<present;i++ )
		{
			clock++;	// increase the clock for each iteration
			pr[i].bt --;	//decrease the burst time by time slice
			
			if( pr[i].bt <= 0 )
			{
				present--;	//to decrease the number of present processes in the queue
				
				temp = pr[i];
				
				//calculations
				for(l=0;l<5;l++)
				{
					if( pr[i].name == iproc[l].name )
					{
						iproc[l].tat = clock;      //for turn around time
						iproc[l].wt = iproc[l].tat - iproc[l].bt - ts;	//for waiting time
					}
				}
				
				for( j=i;j<4;j++ )
					pr[j] = pr[j+1];
				
				pr[4] = temp;
				pr[4].name = 'x';
				
				displayq();
			}
			
			//calculations
			if( clock <= 5 )
			{
			        iproc[i].rt = clock - 1;    //for response time
			}
		}
		
		//calculations
		
		
	}
	printf("\nclock: %d", clock);
	
	//To calculate average waiting time and turn around time
	for(i=0;i<5;i++)
	{
		avgwt = avgwt + iproc[i].wt;
		avgtat = avgtat + iproc[i].tat;
	}
	avgwt /= 5.0;
	avgtat /= 5.0;
}

void main()
{
	//Declarations
	
	//Initializations
	
	//Logic
	input();
	roundrobin();
	displaytable();
	
	printf("\n");
}
