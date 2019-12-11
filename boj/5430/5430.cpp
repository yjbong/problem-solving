#include <cstdio>
#include <cstring>
#include <cctype>
#include <deque>
#define MAX_P 700000
using namespace std;
int T; // # of TC
char P[MAX_P+1];
int n;
deque <int> dq;
char arr[500001];
int main() {
    scanf("%d\n",&T);
    while(T--){
 
        bool reverse=false;
        bool error=false;
        scanf("%s %d\n",P,&n);
        scanf("%s\n",arr);
        // 배열을 파싱하여 deque에 push
        int arrLen=strlen(arr);
        int num=0;
        for(int i=0; i<arrLen; i++){
            if(isdigit(arr[i])){
                num*=10;
                num+=arr[i]-'0';
            }
            else{
                if(num>0) dq.push_back(num);
                num=0;
            }
        }
        // 주어진 연산 수행
        int PLen=strlen(P);
        for(int i=0; i<PLen; i++){
            if(P[i]=='R'){
                if(reverse) reverse=false;
                else reverse=true;
            }
            else if(P[i]=='D'){
                if(dq.empty()) error=true;
                else if(reverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        // 남아 있는 값들을 출력
        if(error){
            while(!dq.empty()) dq.pop_back();
            printf("error\n");
        }
        else{
            printf("[");
            while(!dq.empty()){
                if(reverse){
                    printf("%d",dq.back());
                    dq.pop_back();
                }
                else{
                    printf("%d",dq.front());
                    dq.pop_front();
                }
                if(!dq.empty()) printf(",");
            }
            printf("]\n");
        }
    }
    return 0;
}