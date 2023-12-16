#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
int rank,size;
int* sendbuffer=malloc(40*sizeof(int));
int* recive=malloc(10*sizeof(int));

MPI_Init(NULL,NULL);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0){
for(int i=0;i<size*4;i++){
*(sendbuffer+i)=i;
}
}
MPI_Scatter(sendbuffer,4,MPI_INT,recive,4,MPI_INT,0,MPI_COMM_WORLD);
printf("process %d  recived : ",rank);
for(int i=0;i<4;i++){
printf("%d  ",*(recive+i));
}
printf("\n");

MPI_Finalize();
return 0;

}
