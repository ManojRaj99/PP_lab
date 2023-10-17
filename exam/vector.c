#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void vector_add(int n,int *res,int *vector_a,int *vector_b){

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        res[i]=vector_a[i]+vector_b[i];

    }
}

    void main(){
        int n=100000;
        int vector_a[100000],vector_b[100000],res[100000];
        for(int i=0;i<n;i++){
            vector_a[i]=rand()%10;
            vector_b[i]=rand()%10;
        }
        double s=omp_get_wtime();
            vector_add(n,res,vector_a,vector_b);
        double e=omp_get_wtime();
        for (int i = 0; i < n; i++)
		printf("%d + %d = %d\n",vector_a[i],vector_b[i],res[i]);
        printf("total time=%f",e-s);
}