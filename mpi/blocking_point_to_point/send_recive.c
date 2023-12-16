#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc,int **argv){
MPI_Init(NULL,NULL);
int rank,size;
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(size<2){
fprintf(stderr,"error , we need more than 2 process");
MPI_Abort(MPI_COMM_WORLD,1);
}

if(rank==0){
//process 1 , sender
char *data="hey cv";
MPI_Send(data,6,MPI_BYTE,1,0,MPI_COMM_WORLD);
fprintf(stdout,"message sended");
}
else if(rank==1){
char* receive=malloc(6*sizeof(char));
MPI_Recv(receive,6,MPI_BYTE,0,0,MPI_COMM_WORLD,NULL);
printf("message is : %s \n",receive);

}

MPI_Finalize();

return 0;
}
