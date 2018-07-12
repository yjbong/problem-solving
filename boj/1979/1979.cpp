#include <cstdio>

char a[1001];
char b[1001];
int n,k;
bool ch[10][10];
void init_a(){
    for(int i=1000; i>=0; i--) a[i]=0;
}
void print_a(){

    bool nonz=false;
    for(int i=1000; i>=0; i--){
        if(a[i]!=0) nonz=true;
        if(nonz) printf("%1d",a[i]);
    }
    if(!nonz) printf("0");
    printf("\n");
}
void init_b(){
    for(int i=1000; i>=0; i--) b[i]=0;
}

int main(void){

    init_a();
    init_b();
    scanf("%d %d",&n,&k);
    if(n==1){
        printf("%d\n",k);
        return 0;
    }

    a[0]=k;
    int i=0;
    int c=0;
    bool ok=false;
    while(1){
        if(ch[a[i]][c]) break;
        ch[a[i]][c]=true;

        b[i]=(a[i]*n + c)%10;
        c=(a[i]*n + c)/10;

        if(a[i]!=0 && b[i]==a[0] && c==0){
            ok=true;
            break;
        }

        i++;
        a[i]=b[i-1];
    }

    if(ok) print_a();
    else printf("0\n");

    return 0;
}