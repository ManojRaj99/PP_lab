#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
    int n=100,sum=0;
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        #pragma omp critical
        sum+=i;
    }

    printf("The sum is %d\n",sum);
}