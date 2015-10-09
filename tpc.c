#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<time.h>

int products[10];	//IF want to use then can store values, but not used in this program
int top;

void producers( void );
void consumers( void );

void sleep( void )
{
	int p, q;
	for ( p=0;p<32767;p++ )
		for ( q=0;q<32767;q++ )
		{}
}

void main()
{
	//Initializations
	int id;
	
	//Declarations
	top = -1;
	
	//Logic
	id = fork();	//To fork the processes
	
	if ( id < 0 )
	{
		printf("Something went wrong...Exiting!!!");
		exit(1);
	}
	
	else if ( id == 0 )
	{
		printf("\nInside the child part");
		while ( 1 )
			consumers();
		//sleep();
	}
	
	else 
	{
		printf("\nInside the parents part");
		while ( 1 )
			producers();
		//sleep();
	}
}

void producers( void )
{
	//Initializations
	
	//Declarations
	
	//Logic
	printf("\nInside the producers...");
	if ( top == 9 )
	{
		printf("\nThe queue is full, hence, waiting for the consumer to consume.");
		sleep();
	}
	else
	{
		printf("\nFilled the queue by one...");
		top ++;
	}
}

void consumers( void )
{
	//Initializations
	
	//Declarations
	
	//Logic
	printf("\nInside the consumer...");
	if ( top == -1 )
	{
		printf("\nThe queue is empty, hence, waiting for the producer to fill the queue.");
		sleep();
	}
	printf("\nConsumed by one...");
	top --;
	sleep();	//To synchronize the consumer with producer.
	
}
