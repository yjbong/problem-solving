#include <cstdio>
#include <cstring>
char n[55];
char s[55];
int l;
int main(void){

    scanf("%s",n);
    l=strlen(n);

    for(int i=0; i<=(l-1)/2; i++) s[i]=n[i];
    for(int i=(l-1)/2+1; i<l; i++) s[i]=s[l-1-i];

    bool is_big=false;
    for(int i=0; i<l; i++){
        if(s[i]>n[i]){
            is_big=true;
            break;
        }
        else if(s[i]<n[i]) break;
    }

    if(is_big){
        for(int i=0; i<l; i++) printf("%c",s[i]);
        printf("\n");
    }
    else{
        int i=(l-1)/2;
        s[i]++;
        while(i>=1 && s[i]>'9'){
            s[i]-=10;
            i--;
            s[i]++;
        }
        if(i==0 && s[i]>'9'){
            printf("1");
            for(int i=0; i<l-1; i++) printf("0");
            printf("1\n");
        }
        else{
            for(int i=(l-1)/2+1; i<l; i++) s[i]=s[l-1-i];
            for(int i=0; i<l; i++) printf("%c",s[i]);
            printf("\n");
        }
    }
    return 0;
}