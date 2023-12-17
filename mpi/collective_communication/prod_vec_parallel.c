#include <mpi.h>
#include <stdio.h>

#define N_ 1000000 

int main(){
int rank,size;
double start,end_;
int t1[N_];
int t2[N_];
for(int i=0;i<N_;i++){
t1[i]=i;
t2[i]=i;
}

int global_sum;
MPI_Init(NULL,NULL);
MPI_Barrier(MPI_COMM_WORLD);
start=MPI_Wtime();
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

int begin,end;

begin=rank*(N_/size);
end=(rank+1)*(N_/size);

int local_sum=0;
for(int i=begin;i<end;i++){
local_sum=local_sum+t1[i]*t2[i];
}

MPI_Allreduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
end_=MPI_Wtime();
MPI_Finalize();

if(rank==0){
printf("\n the final result %d\n time : %f",global_sum,end_-start);
}
return 0;

}
