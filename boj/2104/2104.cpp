#include <cstdio>
#include <stack>
using namespace std;
long long a[100000];
typedef pair<long long,long long> ii; // first: start point, second: cur min value

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld",&a[i]);

    stack<ii> s;

    s.push(ii(0,a[0]));

    long long sol=0;
    long long cur_st=a[0];
    for(int i=1; i<n; cur_st+=a[i], i++){

        ii t=s.top();
        long long t_st=t.first;
        long long t_min=t.second;

        if(a[i]>t_min){
            s.push(ii(cur_st,a[i]));
        }

        else if(a[i]<t_min){

            long long in_st=cur_st;
            while(1){

                ii tt=s.top();
                long long tt_st=tt.first;
                long long tt_min=tt.second;

                if(tt_min<=a[i]){
                    if(tt_min<a[i]){
                        s.push(ii(in_st,a[i]));
                    }
                    break;
                }

                else{
                    if(sol<tt_min*(cur_st-tt_st)) sol=tt_min*(cur_st-tt_st);
                    in_st=tt_st;
                    s.pop();
                    if(s.empty()){
                        s.push(ii(in_st,a[i]));
                        break;
                    }
                }
            }
        }
    }

    while(!s.empty()){
        ii t=s.top();
        s.pop();
        long long t_st=t.first;
        long long t_min=t.second;

        if(sol<t_min*(cur_st-t_st)) sol=t_min*(cur_st-t_st);
    }

    printf("%lld\n",sol);
    return 0;
}