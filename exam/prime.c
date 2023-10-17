#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isprime(int n){
    if(n==0||n==1){
        return 0;
    }
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0; 
        }
    }
    return 1;
}

void main(){
    int n=10000;
    int prime[100];

    double start=omp_get_wtime();

    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        
        if(isprime(i)){
            int t=omp_get_thread_num();
            printf("Thread : %d  ,%d\t",t,i);
        }
    }
    double end=omp_get_wtime();
    printf("time taken : %lf",end-start);
}