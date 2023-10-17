#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int fib(int n){
    int i,j;
    if(n<2)
    return n;
    else{
        #pragma omp task shared(i) firstprivate(n)
        i=fib(n-1);

        #pragma omp task shared(j) firstprivate(n)
        j=fib(n-2);

        #pragma omp taskwait
        return i+j;
    }
}

void main(){
    int n=20;
    double s=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<=n;i++){
        int t=omp_get_thread_num();
        printf("thread : %d  fib(%d)=%d\n",t,i,fib(i));
    }
    double e=omp_get_wtime();
    printf("time taken = %lf", e-s );
}