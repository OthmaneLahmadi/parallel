//#include <mpi.h>
#include <stdio.h>
#include <time.h>


#define N_ 1000000

int main(){
int t1[N_];
int t2[N_];
for(int i=0;i<N_;i++){
t1[i]=i;
t2[i]=i;
}
clock_t start=clock();
int s=0;

for(int i=0;i<N_;i++){
s=s+t1[i]*t2[i];
}
clock_t end=clock();
double elapsed_time=((double)(end-start)/CLOCKS_PER_SEC);
printf("sum = %d \ntime : %f",s,elapsed_time);
return 0;

}
