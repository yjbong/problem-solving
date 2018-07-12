#include <cstdio>
#include <algorithm>
using namespace std;
int shom[1111];
int shoms;
void go(int cnum, int cdigit, int clen, int lim_len){
    if(clen==lim_len){
        if(shom[shoms-1]!=cnum) shom[shoms++] = cnum;
        return;
    }
    go(cnum*10+cdigit, 4, clen+1,lim_len);
    go(cnum*10+cdigit, 7, clen+1,lim_len);
}

int main(void){

    shoms=0;
    for(int i=1; i<10; i++){
        go(0,4,0,i);
        go(0,7,0,i);
    }
    sort(shom,shom+shoms);

    int a,b;
    scanf("%d %d",&a,&b);

    int sol=0;
    for(int i=0; i<shoms; i++)
        if(a<=shom[i] && shom[i]<=b) sol++;

    printf("%d\n",sol);
    return 0;
}