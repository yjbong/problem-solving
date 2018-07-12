#include <cstdio>
#define INF 1000000000
int a[18][18];
int b[18][18];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) scanf("%d",&a[i][j]);

    int sol=INF;
    for(int i=0; i<(1<<m); i++){

        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++) b[j][k]=a[j][k];

        bool cok=true;
        int colch=0;
        int t=i;
        for(int j=0; j<m; j++, t/=2){
            if(t%2){
                colch++;
                for(int k=0; k<n; k++) b[k][j]*=(-1);
            }
        }

        int rowch=0;
        for(int j=0; j<n; j++){
            int sum=0;
            for(int k=0; k<m; k++) sum+=b[j][k];
            if(sum==0){
                cok=false;
                goto out;
            }
            else if(sum<0){
                rowch++;
                for(int k=0; k<m; k++) b[j][k]*=(-1);
            }
        }

        for(int j=0; j<m; j++){
            int sum=0;
            for(int k=0; k<n; k++) sum+=b[k][j];
            if(sum<=0){
                cok=false;
                break;
            }
        }

        out:
        if(cok && sol>colch+rowch) sol=colch+rowch;
    }
    if(sol>=INF) printf("-1\n");
    else printf("%d\n",sol);
    return 0;
}