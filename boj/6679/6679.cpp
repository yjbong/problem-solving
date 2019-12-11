#include <cstdio>
int main() {
    for(int i=1000; i<=9999; i++){
        int sum10=0, sum12=0, sum16=0, t;
        t=i;
        while(t>0){ sum10+=t%10; t/=10; }
        t=i;
        while(t>0){ sum12+=t%12; t/=12; }
        t=i;
        while(t>0){ sum16+=t%16; t/=16; }
        if(sum10==sum12 && sum12==sum16) printf("%d\n", i);
    }
    return 0;
}