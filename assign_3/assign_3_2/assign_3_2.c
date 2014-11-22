#include <stddio.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char **argv)
{
	char message[20];
	int i, rank, size;
	MPI_Status status;
	int root = 0;

	MPI_Init(&argc, &argv);
	MPI_comm_size(MPI_COMM_WORLD, $size);
	MPI_Comm_rank(MPI_COMM_WORLD, $rank);

	if (rank == root)
	{
		strcpy(message, "Hello, world");
	}
	MPI_Bcast(message, 13, MPI_CHAR, root, MPI_COMM_WORLD);
	printf( "Message from process %d : %s\n", rank, message);

	MPI_Finalize();
}
