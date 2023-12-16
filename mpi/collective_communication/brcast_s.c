#include <mpi.h>
#include <stdio.h>
#include <unistd.h>
int main(){
int rank,size;
int buffer;
MPI_Init(NULL,NULL);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
//MPI_Barrier(MPI_COMM_WORLD);
if(rank==5){
buffer=rank*rank;
}

MPI_Bcast(&buffer,1,MPI_INT,5,MPI_COMM_WORLD);
printf("data : %d\n",buffer);
MPI_Finalize();
return 0;

}
