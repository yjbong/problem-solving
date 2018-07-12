#include <cstdio>
#include <cmath>
int n,m;
int sqrn;
int a[250000];
int rot[500];
int sum[500];
int f[500][10];

void update(int l, int r){ // a[i] = (a[i]+1)%10 for i=(l ~ r)

        if(l>r) return;

        int lg,li;
        int rg,ri;
        lg = l/sqrn; li = l%sqrn;
        rg = r/sqrn; ri = r%sqrn;

        if(lg==rg){
                if(li==0 && ri==sqrn-1) rot[lg]=(rot[lg]+1)%10;
                else{
                        for(int i=li; i<=ri; i++){
                                f[lg][a[lg*sqrn+i]]--;
                                a[lg*sqrn+i]=(a[lg*sqrn+i]+1)%10;
                                f[lg][a[lg*sqrn+i]]++;
                        }

                        sum[lg]=0;
                        for(int i=0; i<sqrn; i++) sum[lg]+=a[lg*sqrn+i];
                }
        }
        else{
                int s,e;
                if(li==0) s=lg;
                else{
                        sum[lg]=0;
                        for(int i=li; i<sqrn; i++){
                                f[lg][a[lg*sqrn+i]]--;
                                a[lg*sqrn+i]=(a[lg*sqrn+i]+1)%10;
                                f[lg][a[lg*sqrn+i]]++;
                        }

                        sum[lg]=0;
                        for(int i=0; i<sqrn; i++) sum[lg]+=a[lg*sqrn+i];

                        s=lg+1;
                }

                if(ri==sqrn-1) e=rg;
                else{
                        sum[rg]=0;
                        for(int i=0; i<=ri; i++){
                                f[rg][a[rg*sqrn+i]]--;
                                a[rg*sqrn+i]=(a[rg*sqrn+i]+1)%10;
                                f[rg][a[rg*sqrn+i]]++;
                        }

                        sum[rg]=0;
                        for(int i=0; i<sqrn; i++) sum[rg]+=a[rg*sqrn+i];

                        e=rg-1;
                }

                for(int i=s; i<=e; i++) rot[i]=(rot[i]+1)%10;
        }
}

int get_sum(int l, int r){

        if(l>r) return 0;

        int lg,li;
        int rg,ri;
        lg = l/sqrn; li = l%sqrn;
        rg = r/sqrn; ri = r%sqrn;

        int ret;

        if(lg==rg){

                if(li==0 && ri==sqrn-1){
                        ret=sum[lg]+rot[lg]*sqrn;
                        for(int i=10-rot[lg]; i<10; i++) ret -= f[lg][i]*10;
                }
                else{
                        ret=0;
                        for(int i=li; i<=ri; i++) ret += (a[lg*sqrn+i]+rot[lg])%10;
                }
        }
        else{
                int s,e;
                ret=0;

                if(li==0) s=lg;
                else{
                        for(int i=li; i<sqrn; i++) ret += (a[lg*sqrn+i]+rot[lg])%10;
                        s=lg+1;
                }

                if(ri==sqrn-1) e=rg;
                else{
                        for(int i=0; i<=ri; i++) ret += (a[rg*sqrn+i]+rot[rg])%10;
                        e=rg-1;
                }

                for(int i=s; i<=e; i++){
                        ret += sum[i]+rot[i]*sqrn;
                        for(int j=10-rot[i]; j<10; j++) ret -= f[i][j]*10;
                }
        }
        return ret;
}

int main(void){

        scanf("%d %d",&n,&m);
        sqrn = (int)sqrt(n);

        for(int i=0; i<n; i++) scanf("%1d",&a[i]);
        for(int i=0; i<n; i++){
                f[i/sqrn][a[i]]++;
                sum[i/sqrn]+=a[i];
        }

        for(int i=0; i<m; i++){
                int t1,t2;
                scanf("%d %d",&t1,&t2);
                t1--; t2--;
                printf("%d\n",get_sum(t1,t2));
                update(t1,t2);
        }
        return 0;
}