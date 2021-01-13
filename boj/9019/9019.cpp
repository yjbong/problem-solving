#include <iostream>
#include <queue>
using namespace std;
 
int step[10000];
int D(int x){ return (x*2)%10000; }
int S(int x){ return (x+9999)%10000; }
int L(int x){ return (x*10+x/1000)%10000; }
int R(int x){ return x/10+(x%10)*1000; }
typedef struct{
    int val;
    int op;
} PREINFO;
PREINFO preInfo[10000];
queue <int> q;
int order[10000], orders;
 
int main() {
    int T,A,B;
    cin >> T;
    while(T--){
        cin >> A >> B;
        orders=0;
        for(int i=0; i<10000; i++){
            step[i]=1000000000;
            preInfo[i].op=-1;
        }
        step[A]=0; q.push(A);
        while(!q.empty()){
            int f=q.front(); q.pop();
            int c;
            // D
            c=D(f);
            if(step[c]>step[f]+1){
                step[c]=step[f]+1; q.push(c);
                preInfo[c].val=f; preInfo[c].op=0;
            }
            // S
            c=S(f);
            if(step[c]>step[f]+1){
                step[c]=step[f]+1; q.push(c);
                preInfo[c].val=f; preInfo[c].op=1;
            }
            // L
            c=L(f);
            if(step[c]>step[f]+1){
                step[c]=step[f]+1; q.push(c);
                preInfo[c].val=f; preInfo[c].op=2;
            }
            // R
            c=R(f);
            if(step[c]>step[f]+1){
                step[c]=step[f]+1; q.push(c);
                preInfo[c].val=f; preInfo[c].op=3;
            }
        }
        int val=B;
        while(1){
            if(preInfo[val].op>=0){
                order[orders++]=preInfo[val].op;
                val=preInfo[val].val;
            }
            else break;
        }
        for(int i=orders-1; i>=0; i--){
            switch(order[i]){
            case 0: cout << 'D'; break;
            case 1: cout << 'S'; break;
            case 2: cout << 'L'; break;
            case 3: cout << 'R'; break;
            }
        }
        cout << endl;
    }
    return 0;
}