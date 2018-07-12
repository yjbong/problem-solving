#include <cstdio>
#include <cstring>
#define INF 1000000

char str[55]; int strLength;
char word[55][55]; int wordLength[55];
int words;

int strFreq[55][26]; // strFreq[i][j] = from str[1~i], frequency of each alphabet j(0~25, a~z)
int wordFreq[55][26]; // strFreq[i][j] = from word[i], frequency of each alphabet j(0~25, a~z)
int d[55]; // minimum cost for str[1~i]

int min2(int a, int b){
        return a<b?a:b;
}
int main(void){

        // get input
        scanf("%s",str+1);
        strLength = strlen(str+1);
        scanf("%d",&words);
        for(int i=0; i<words; i++){
                scanf("%s",word[i]+1);
                wordLength[i] = strlen(word[i]+1);
        }

        // init
        for(int i=0; i<=strLength; i++)
                for(int j=0; j<26; j++)
                        strFreq[i][j] = 0;
        for(int i=0; i<words; i++)
                for(int j=0; j<26; j++)
                        wordFreq[i][j] = 0;
        d[0]=0;
        for(int i=1; i<=strLength; i++) d[i]=INF;

        // calc alphabet freq
        for(int i=1; i<=strLength; i++)
                for(int j=0; j<26; j++)
                        strFreq[i][j] = str[i]==j+'a' ? strFreq[i-1][j]+1 : strFreq[i-1][j];
        for(int i=0; i<words; i++)
                for(int j=1; j<=wordLength[i]; j++)
                        wordFreq[i][word[i][j]-'a']++;

        // calc d (DP)
        for(int i=1; i<=strLength; i++){
                for(int j=0; j<i; j++){
                        for(int k=0; k<words; k++){
                                bool isPossible=true;
                                for(int l=0; l<26; l++){
                                        if(strFreq[i][l]-strFreq[j][l] != wordFreq[k][l]){
                                                isPossible=false;
                                                break;
                                        }
                                }
                                if(isPossible){
                                        int curCost=0;
                                        for(int l=j+1, m=1; l<=i; l++, m++)
                                                if(str[l]!=word[k][m]) curCost++;

                                        //d[i]=min2(d[i], d[j]+(minimum cost for str[j+1~i]))
                                        d[i]=min2(d[i],d[j]+curCost);
                                }
                        }
                }
        }
        if(d[strLength]<INF) printf("%d\n", d[strLength]);
        else printf("-1\n");
        return 0;
}