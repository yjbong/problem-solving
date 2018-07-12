#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int sqrn;
int a[111111];
int p[333];

int lower_bound(int key){ // return smallest idx i that (a[i]+p[i/sqrn]>=key)
        int left,mid,right;
        int ret=-1;

        left=0; right=n-1;
        while(left<=right){
                mid=(left+right)/2;
                int midg = mid/sqrn;
                if(a[mid]+p[midg] >= key){
                        if(ret<0 || ret>mid) ret=mid;
                        right=mid-1;
                }
                else left=mid+1;
        }
        return ret;
}

int upper_bound(int key){ // return biggest idx i that (a[i]+p[i/sqrn]<=key)
        int left,mid,right;
        int ret=-1;

        left=0; right=n-1;
        while(left<=right){
                mid=(left+right)/2;
                int midg = mid/sqrn;
                if(a[mid]+p[midg] <= key){
                        if(ret<0 || ret<mid) ret=mid;
                        left=mid+1;
                }
                else right=mid-1;
        }
        return ret;
}

void update(int l, int r){ // add 1 for a[l~r]
        if(l>r) return;

        int lg,li;
        int rg,ri;
        lg = l/sqrn; li = l%sqrn;
        rg = r/sqrn; ri = r%sqrn;

        if(lg==rg){
                if(li==0 && ri==sqrn-1) p[lg]++;
                else for(int i=li; i<=ri; i++) a[lg*sqrn+i]++;
        }
        else{
                int s,e;
                if(li==0) s=lg;
                else{
                        for(int i=li; i<sqrn; i++) a[lg*sqrn+i]++;
                        s=lg+1;
                }

                if(ri==sqrn-1) e=rg;
                else{
                        for(int i=0; i<=ri; i++) a[rg*sqrn+i]++;
                        e=rg-1;
                }

                for(int i=s; i<=e; i++) p[i]++;
        }
}

int main(void){

        scanf("%d %d",&n,&m);
        sqrn = (int)sqrt(n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        getchar();
        sort(a,a+n);

        for(int i=0; i<m; i++){
                char o;
                int t1,t2;
                scanf("%c %d %d\n",&o,&t1,&t2);

                if(o=='F'){
                        int low = lower_bound(t2);
                        if(low<0) continue;

                        int up = low+t1-1;
                        if(up>=n) up = n-1;

                        int up_nums = up - lower_bound(a[up]+p[up/sqrn]) + 1;
                        update(low, upper_bound(a[up]+p[up/sqrn]-1));
                        update(upper_bound(a[up]+p[up/sqrn])-up_nums+1, upper_bound(a[up]+p[up/sqrn]));
                }
                else{
                        int low = lower_bound(t1);
                        int up = upper_bound(t2);

                        if(low>=0 && up>=0 && low<=up) printf("%d\n",up-low+1);
                        else printf("0\n");
                }
        }

        return 0;
}