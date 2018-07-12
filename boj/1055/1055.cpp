#include <cstdio>
#include <cstring>
typedef long long ll;

char f[55];
char s[55];
ll flen, slen;

ll runs,min,max;
ll ds; // num of dollars
ll nds; // num of non-dollars

ll len[31];
ll lens;

bool find;

void find_char(ll clev, ll cidx){

    ll cchar=0;
    for(ll i=0; find==false && i<slen; i++){
        if(s[i]=='$'){
            if(clev==1){
                if(cchar+len[clev]-1 >= cidx){
                    find=true;
                    printf("%c",f[cidx-cchar]);
                }
                else cchar += len[clev];
            }
            else if(clev>1){
                if(cchar+len[clev]-1 >= cidx) find_char(clev-1, cidx-cchar);
                else cchar += len[clev];
            }
        }

        else{
            if(cchar==cidx){
                find=true;
                printf("%c",s[i]);
                return;
            }
            else cchar++;
        }
    }
}

int main(void){

    scanf("%s",f);
    scanf("%s",s);
    scanf("%lld",&runs);
    scanf("%lld %lld",&min,&max);

    flen=strlen(f);
    slen=strlen(s);

    ds=nds=0;
    for(ll i=0; i<slen; i++){
        if(s[i]=='$') ds++;
        else nds++;
    }

    if(ds<2){
        for(ll i=min-1; i<max; i++){
            if(i>=flen+(slen-1)*runs) printf("-");
            else if(i<flen) printf("%c",f[i]);
            else printf("%c",s[(i-flen)%(slen-1) + 1]);
        }
        printf("\n");
    }

    else{

        len[1]=flen;
        for(ll i=2; i<=runs; i++){
            len[i]=len[i-1]*ds + nds;
            if(len[i] > max){
                runs=i;
                break;
            }
        }

        for(ll i=min-1; i<max; i++){
            ll crun=runs;
            if(len[crun]*ds + nds <= i){
                printf("-");
                continue;
            }

            while(crun>1 && len[crun] > i)
                crun--;

            find=false;
            find_char(crun,i);
        }
        printf("\n");
    }
    return 0;
}