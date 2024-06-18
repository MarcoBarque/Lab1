#include <iostream>
#include <mpi.h>

int main(){
	int size, rank;
	int buff;

	int tag = 0;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	buff = rank;
	MPI_Status stat;

	for(int i=0;i<size;++i){
		if(rank == 0){
			if(size != 1){
				MPI_Sendrecv_replace(&buff,1,MPI_INT,rank+1,tag,size-1,tag,MPI_COMM_WORLD,&stat);
			}
		} else if (rank == size-1) {
			MPI_Sendrecv_replace(&buff,1,MPI_INT,0,tag,rank-1,tag,MPI_COMM_WORLD,&stat);
		} else {
			MPI_Sendrecv_replace(&buff,1,MPI_INT,rank+1,tag,rank-1,tag,MPI_COMM_WORLD,&stat);
		}

		if(rank == 0){
			std::cout << "I'm: " << rank << " and my buffer is: " << buff << std::endl;
		}
	}

	MPI_Finalize();

	return 0;
}
