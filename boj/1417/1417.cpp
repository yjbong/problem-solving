#include <cstdio>
int p[1000];
int n;
int main(void){
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&p[i]);
    int sol=0;
    while(1){
        int max=1;
        for(int i=2; i<n; i++)
            if(p[max]<p[i]) max=i;

        if(p[0]>p[max]) break;
        p[max]--;
        p[0]++;
        sol++;
    }
    printf("%d\n",sol);
    return 0;
}