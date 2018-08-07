#include <cstdio>
#include <cstring>
#define INF 100000000
int c,n;
char word[22][44];
int wordlen[22];
bool valid[22];
int valids;
int cache[1<<15][15];
int choice[1<<15][15];

int duplen(int a, int b){ // if word[a] is followed by word[b], return duplicated string length

        int i,j;
        int len=wordlen[a];
        if(len>wordlen[b]) len=wordlen[b];
        for(i=len; i>=1; i--){
                for(j=0; j<i; j++)
                        if(word[a][wordlen[a]-i+j]!=word[b][j]) break;

                if(j==i) return i;
        }
        return 0;
}

bool is_substr(int a, int b){ // if word[b] is a substring of word[a] then return true

        int i,j;
        if(wordlen[a]<wordlen[b]) return false;

        for(i=0; i<wordlen[a]; i++){
                for(j=0; j<wordlen[b] && i+j<wordlen[a]; j++) if(word[a][i+j]!=word[b][j]) break;
                if(j==wordlen[b]) return true;
        }
        return false;
}

int go(int state, int lastword){

        if(cache[state][lastword]>=0) return cache[state][lastword];

        int used_words=0;
        for(int i=0; i<n; i++) if(state&(1<<i)) used_words++;
        if(used_words==valids) return 0;


        int ret=INF;
        for(int i=0; i<n; i++){
                int curlen=INF;
                if(used_words==0){ // state==0
                        if(valid[i] && !(state&(1<<i))) curlen=go(state|(1<<i),i)+wordlen[i];
                }
                else if(lastword!=i){
                        if(valid[i] && !(state&(1<<i))) curlen=go(state|(1<<i),i)+wordlen[i]-duplen(lastword, i);
                }

                if(ret>curlen){
                        ret=curlen;
                        choice[state][lastword]=i;
                }
        }
        return (cache[state][lastword]=ret);
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++){
                        scanf("%s",word[i]);
                        wordlen[i]=strlen(word[i]);
                        valid[i]=true;
                }

                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                if(i!=j && valid[i] && valid[j] && is_substr(i,j)) valid[j]=false;

                valids=0;
                for(int i=0; i<n; i++)
                        if(valid[i]) valids++;

                for(int i=0; i<(1<<n); i++)
                        for(int j=0; j<n; j++) cache[i][j]=-1;

                go(0,0);

                int cur_state=0;
                int cur_lastword=0;
                for(int i=0; i<valids; i++){
                        int cur_choice=choice[cur_state][cur_lastword];
                        if(cur_state==0) printf("%s",word[cur_choice]);
                        else{
                                int cur_duplen=duplen(cur_lastword, cur_choice);
                                for(int i=cur_duplen; i<wordlen[cur_choice]; i++) printf("%c",word[cur_choice][i]);
                        }

                        cur_state|=(1<<cur_choice);
                        cur_lastword=cur_choice;
                }
                printf("\n");
        }
        return 0;
}