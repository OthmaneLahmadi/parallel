#include <mpi.h>
#include <stdio.h>


int main(){
MPI_Init(NULL,NULL);
int rank,size;
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
printf("process %d the number of cpu %d\n",rank,size);
MPI_Finalize();
return 0;
}
