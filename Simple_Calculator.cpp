#include<stdio.h>

#include<mpi.h>

int main()
{

	MPI_Init(NULL, NULL);

	int a=5,b=2,rank;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{

		printf("Rank %d Summation : %d\n",rank, a + b);

	}
	else if (rank == 1)
	{

		printf("Rank %d Subtraction : %d\n",rank, a - b);

	}
	else if (rank == 2)
	{

		printf("Rank %d Multiplication : %d\n",rank, a * b);

	}
	else if (rank == 3)
	{

		printf("Rank %d Division : %d\n",rank, a / b);

	}
	else
	{

		printf("Undefine operation\n");

	}

	MPI_Finalize();



}