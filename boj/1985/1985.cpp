#include <stdio.h>
#include <string.h>
#define MAX 100
char a[MAX+1];
char b[MAX+1];
int a_frq[10];
int b_frq[10];

int is_same_num(){
    int i;
    for(i=0; i<10; i++)
        if((a_frq[i]==0 && b_frq[i]!=0) || (a_frq[i]!=0 && b_frq[i]==0)) break;

    if(i==10) return 1;
    else return 0;
}

int main(void){

    int cases;
    int i,result;
    int a_len, b_len;
    cases=3;

    while(cases--){
        result=0;
        scanf("%s", a);
        scanf("%s", b);

        a_len=strlen(a);
        b_len=strlen(b);
        for(i=0; i<10; i++) a_frq[i]=b_frq[i]=0;
        for(i=0; i<a_len; i++) a_frq[a[i]-'0']++;
        for(i=0; i<b_len; i++) b_frq[b[i]-'0']++;
        if(is_same_num()) result=1;

        if(result==0){
            for(i=1; i<a_len; i++){
                if(a[i-1]>'0' && a[i]<'9' && !(i==1 && a[i-1]=='1')){
                    a_frq[a[i-1]-'0']--;
                    a_frq[a[i-1]-'0'-1]++;
                    a_frq[a[i]-'0']--;
                    a_frq[a[i]-'0'+1]++;
                    if(is_same_num()){
                        result=2;
                        break;
                    }
                    a_frq[a[i-1]-'0']++;
                    a_frq[a[i-1]-'0'-1]--;
                    a_frq[a[i]-'0']++;
                    a_frq[a[i]-'0'+1]--;
                }

                if(a[i]>'0' && a[i-1]<'9'){
                    a_frq[a[i-1]-'0']--;
                    a_frq[a[i-1]-'0'+1]++;
                    a_frq[a[i]-'0']--;
                    a_frq[a[i]-'0'-1]++;
                    if(is_same_num()){
                        result=2;
                        break;
                    }
                    a_frq[a[i-1]-'0']++;
                    a_frq[a[i-1]-'0'+1]--;
                    a_frq[a[i]-'0']++;
                    a_frq[a[i]-'0'-1]--;
                }
            }

            if(result==0){
                for(i=1; i<b_len; i++){
                    if(b[i-1]>'0' && b[i]<'9' && !(i==1 && b[i-1]=='1')){
                        b_frq[b[i-1]-'0']--;
                        b_frq[b[i-1]-'0'-1]++;
                        b_frq[b[i]-'0']--;
                        b_frq[b[i]-'0'+1]++;
                        if(is_same_num()){
                            result=2;
                            break;
                        }
                        b_frq[b[i-1]-'0']++;
                        b_frq[b[i-1]-'0'-1]--;
                        b_frq[b[i]-'0']++;
                        b_frq[b[i]-'0'+1]--;
                    }

                    if(b[i]>'0' && b[i-1]<'9'){
                        b_frq[b[i-1]-'0']--;
                        b_frq[b[i-1]-'0'+1]++;
                        b_frq[b[i]-'0']--;
                        b_frq[b[i]-'0'-1]++;
                        if(is_same_num()){
                            result=2;
                            break;
                        }
                        b_frq[b[i-1]-'0']++;
                        b_frq[b[i-1]-'0'+1]--;
                        b_frq[b[i]-'0']++;
                        b_frq[b[i]-'0'-1]--;
                    }
                }
            }
        }

        if(result==1) printf("friends\n");
        else if(result==2) printf("almost friends\n");
        else if(result==0) printf("nothing\n");
    }
    return 0;
}