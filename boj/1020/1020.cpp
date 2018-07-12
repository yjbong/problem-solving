#include <cstdio>
#include <cstring>
const int l[10]={6,2,5,5,4,5,6,3,7,5};
int d[22][222];
long long pw[19];

long long atoi2(char num[]){

    int len=strlen(num);
    long long ret=0;
    for(int i=0; i<len; i++){
        ret*=10ll;
        ret+=(num[i]-'0');
    }
    return ret;
}

int main(void){

    pw[0]=1;
    for(int i=1; i<=18; i++) pw[i]=pw[i-1]*10;
    d[0][0]=1;
    for(int i=1; i<22; i++){
        for(int j=0; j<222; j++){
            for(int k=0; k<10; k++){
                if(j-l[k]>=0 && d[i-1][j-l[k]]==1){
                    d[i][j]=1;
                    break;
                }
            }
        }
    }

/*
    for(int i=0; i<=15; i++){
        for(int j=0; j<=111; j++){
            if(d[i][j]==1) printf("len %d lines %d\n",i,j);
        }
    }
*/
    char num[20];
    char sol[20];
    bool ok;
    long long numn,soln,ans;
    scanf("%s",num);
    strcpy(sol,num);

    int n=strlen(num);
    if(n==1){
        ok=false;
        for(int i=(num[0]-'0'+1)%10; i!=num[0]-'0'; i=(i+1)%10){
            if(l[num[0]-'0']==l[i]){
                ans=i-(num[0]-'0');
                ok=true;
                break;
            }
        }
        if(!ok) ans=10;
        else{
            if(ans<=0) ans+=10;
        }
        printf("%lld\n",ans);
    }
    else{
        int totl=0;
        for(int i=0; i<n; i++) totl+=l[num[i]-'0'];

        ok=false;
        int strt;
        for(int i=n-1, k=0; i>=0; i--,k++){

            int curl=totl;
            for(int j=n-1; j>=i; j--) curl-=l[num[j]-'0'];

            if(i>0){
                for(int j=num[i]-'0'+1; j<=9; j++){
                    if(k>=0 && totl-curl-l[j]>=0 && d[k][totl-curl-l[j]]==1){

                        ok=true;
                        sol[i]=j+'0';
                        strt=i+1;
                        goto out;
                    }
                }
            }
            else{
                for(int j=(num[i]-'0'+1)%10; j!=num[i]-'0'; j=(j+1)%10){
                    if(k>=0 && totl-curl-l[j]>=0 && d[k][totl-curl-l[j]]==1){

                        ok=true;
                        sol[i]=j+'0';
                        strt=i+1;
                        goto out;
                    }
                }
            }
        }
        out:

        if(ok){
            int curl=0;
            for(int i=0; i<strt; i++) curl+=l[sol[i]-'0'];

            int reml=totl-curl;

            for(int i=strt; i<n; i++){
                int k=n-1-i;
                for(int j=0; j<=9; j++){
                    if(k>=0 && reml-l[j]>=0 && d[k][reml-l[j]]==1){
                        sol[i]=j+'0';
                        reml-=l[j];
                        break;
                    }
                }
            }
            numn=atoi2(num);
            soln=atoi2(sol);
//          printf("%lld %lld\n",numn,soln);

            ans=soln-numn;
            if(ans<=0) ans+=pw[n];
        }
        else ans=pw[n];
        printf("%lld\n",ans);
    }
    return 0;
}