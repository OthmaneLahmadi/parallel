#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
int rank;
int s_data;

int size;
int data_size;
char str[20];
MPI_Init(NULL,NULL);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0){
for(int i=0;i<size;i++){
sprintf(str,"%d",i);
int* s=malloc(sizeof(int));
*s=strlen(str);
MPI_Send(s,1,MPI_INT,i,0,MPI_COMM_WORLD);//len of data 
MPI_Send(str,strlen(str),MPI_BYTE,i,0,MPI_COMM_WORLD);
}
}

else{
int count;
MPI_Status status;
int l;
MPI_Recv(&l,1,MPI_INT,0,0,MPI_COMM_WORLD,NULL);
char r_data[l];
MPI_Recv(r_data,l,MPI_BYTE,0,0,MPI_COMM_WORLD,&status);
MPI_Get_count(&status,MPI_BYTE,&count);
printf("process %d recive %s count %d\n",rank,r_data,count);
}
MPI_Finalize();
return 0;}
