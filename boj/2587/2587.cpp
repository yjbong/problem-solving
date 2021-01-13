#include <cstdio>
int A[5];
int main() {
    for(int i=0; i<5; i++) scanf("%d",&A[i]);
    for(int i=0; i<5; i++){
        for(int j=0; j<4-i; j++){
            if(A[j]>A[j+1]){
                int tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
            }
        }
    }
 
    int avg=0;
    for(int i=0; i<5; i++) avg+=A[i];
    avg/=5;
    printf("%d\n%d\n",avg,A[5/2]);
    return 0;
}