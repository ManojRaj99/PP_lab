#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
    int itns,itn[8],i;
    printf("Enter th no of intertions\n");
    scanf("%d",&itns);

    #pragma omp parallel for schedule(static,2)
    for(i=1;i<=itns;i++){
        int t=omp_get_thread_num();
        itn[t]+=1;
        printf("threads = %d  iteration = %d  value = %d\n",t,itn[t],i);
    }
}
