#include <cstdio>
#include <vector>
#define MAX_N 10000000
using namespace std;
bool isNotPrime[3163]; // sqrt(10000000)=3162.xxx
vector <int> prime;
int N;

int main() {
    isNotPrime[0]=isNotPrime[1]=true;
    for(int i=2; i<=3162; i++)
        if(!isNotPrime[i])
            for(int j=i*2; j<=3162; j+=i) isNotPrime[j]=true;
    for(int i=0; i<=3162; i++) if(!isNotPrime[i]) prime.push_back(i);

    scanf("%d",&N);

    for(int i=0; i<prime.size(); i++){
        while(N%prime[i]==0){
            printf("%d\n",prime[i]);
            N/=prime[i];
        }
    }
    if(N>1) printf("%d\n",N);
    
    return 0;
}