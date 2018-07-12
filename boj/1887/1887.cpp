#include <cstdio>
int l[52];
int main(void){

    int t,n;
    scanf("%d %d",&t,&n);
    for(int i=0; i<n; i++){
        int z;
        scanf("%d",&z);
        for(int j=0; j<z; j++){
            int c;
            scanf("%d",&c);
            l[i]+=1<<(c-1);
        }
    }
    int sol=0;
    for(int i=0; i<(1<<t); i++){
        bool ok=true;
        for(int j=0; j<n; j++){
            if((i&l[j])==l[j]){
                ok=false;
                break;
            }
        }
        if(ok) sol++;
    }
    printf("%d\n",sol);
    return 0;
}