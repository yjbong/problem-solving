#include <stdio.h>
#include <math.h>

int pw[20];
int len[20];
int flag[20];

double wid[65536];

double calc_wid(int a, int b, int c){

        int maxlen,sum;
        double p;
        maxlen=a;
        if(maxlen<b) maxlen=b;
        if(maxlen<c) maxlen=c;

        sum=a+b+c;
        if(sum-maxlen>maxlen){
                p=(a+b+c)/2.0;
                return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        else return -1.0;
}

int ones(int binnum){

        int n=0,i;

        for(i=0; i<20; i++) flag[i]=0;
        i=0;
        while(binnum>0){
                if(binnum%2==1){
                        n++;
                        flag[i]=1;

                }
                else flag[i]=0;
                binnum/=2;
                i++;
        }


        return n;
}

int main(void){

        int i,j,k,l,m,n;
        double cur,sol;
        pw[0]=1;
        for(i=1; i<=16; i++) pw[i]=pw[i-1]*2;

        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&len[i]);

        for(i=0; i<pw[n]; i++) wid[i]=0.0;

        for(i=0; i<n; i++){
                for(j=i+1; j<n; j++){
                        for(k=j+1; k<n; k++){
                                wid[pw[i]+pw[j]+pw[k]]=calc_wid(len[i],len[j],len[k]);
                        }
                }
        }

        for(i=6; i<=n; i+=3){
                for(j=0; j<pw[n]; j++){

                        if(ones(j)==i){
                                for(k=0; k<n; k++){
                                        for(l=k+1; l<n; l++){
                                                for(m=l+1; m<n; m++){
                                                        if(flag[k]==1 && flag[l]==1 && flag[m]==1){
                                                                if(wid[pw[k]+pw[l]+pw[m]]<0.0 || wid[j-(pw[k]+pw[l]+pw[m])]<0.0) cur=-1.0;
                                                                else cur=wid[pw[k]+pw[l]+pw[m]]+wid[j-(pw[k]+pw[l]+pw[m])];

                                                                if(wid[j]<cur) wid[j]=cur;
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }

        sol=wid[0];
        for(i=1; i<pw[n]; i++)
                if(sol<wid[i]) sol=wid[i];

        printf("%.10lf\n",sol);
        return 0;
}