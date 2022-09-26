#include<stdio.h>
#include<mpi.h>

int main(int arv, char** argv)
{

	MPI_Init(NULL, NULL);

	int rank;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int n,sum1=0,sum2=0,sum3=0,sum4=0;
	int arr[35];


	n = 8;

	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	arr[6] = 7;
	arr[7] = 8;
	arr[8] = 9;




	if (rank == 0)
	{

		sum1 = 0;

		for (int i = 1; i <= (n / 4); i++)
		{

			sum1 = sum1 + arr[i];

		}
		printf("Sum1 = %d\n", sum1);


	}
	else if (rank == 1)
	{

		sum2 = 0;

		for (int i = (n / 4) + 1; i <= n / 2; i++)
		{

			sum2 = sum2 + arr[i];

		}
		printf("Sum2 = %d\n", sum2);


	}
	else if (rank == 2)
	{

		sum3 = 0;

		for (int i = (n / 2) + 1; i <= ((3 * n) / 4); i++)
		{

			sum3 = sum3 + arr[i];

		}
		printf("Sum3 = %d\n", sum3);


	}
	else if (rank == 3)
	{

		sum4 = 0;

		for (int i = (((3 * n) / 4) + 1); i <= n; i++)
		{

			sum4 = sum4 + arr[i];

		}
		printf("Sum4 = %d\n", sum4);


	}

	printf("Total Sum = %d\n", sum1 + sum2 + sum3 + sum4);

	MPI_Finalize();


}