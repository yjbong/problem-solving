#include <cstdio>
int s[1000];
int main(void){
    int n,sol;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&s[i]);
    sol=s[0];
    for(int i=1; i<n; i++){
        if(i%2) sol-=s[i];
        else sol+=s[i];
    }
    sol/=2;
    printf("%d\n",sol);
    for(int i=0; i<n-1; i++){
        sol=s[i]-sol;
        printf("%d\n",sol);
    }
    return 0;
}