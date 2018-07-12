#include <cstdio>
#include <cstring>
char m1[26];
char m2[26];
char w[111][55];
bool same(int a, int b){

    int alen=strlen(w[a]);
    int blen=strlen(w[b]);
    if(alen!=blen) return false;
    for(int i=0; i<26; i++) m1[i]=m2[i]=0;
    for(int i=0; i<alen; i++){
        if(m1[w[b][i]-'a']==0 && m2[w[a][i]-'a']==0){
            m1[w[b][i]-'a']=w[a][i];
            m2[w[a][i]-'a']=w[b][i];
        }
        else if(m1[w[b][i]-'a']!=w[a][i] || m2[w[a][i]-'a']!=w[b][i]) return false;
    }
    return true;
}

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%s",w[i]);
    int sol=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(same(i,j)) sol++;

    printf("%d\n",sol);
    return 0;
}