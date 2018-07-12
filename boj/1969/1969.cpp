#include <stdio.h>
#define MAX_N 100000
#define MAX_M 1000

char dna[MAX_N][MAX_M+1];
int freq[MAX_M][26];
char sol[MAX_M+1];
int main(void){

        int n, m, i, j;
        int ham_sum, max_freq;
        char max_char;
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) scanf("%s", dna[i]);

        for(i=0; i<m; i++)
                for(j=0; j<26; j++)
                        freq[i][j]=0;

        for(i=0; i<m; i++)
                for(j=0; j<n; j++)
                        freq[i][dna[j][i]-'A']++;

        ham_sum=0;
        for(i=0; i<m; i++){
                max_freq=-1;
                for(j=0; j<26; j++){
                        if(max_freq<freq[i][j]){
                                max_freq=freq[i][j];
                                max_char=j+'A';
                        }
                }
                sol[i]=max_char;
                ham_sum+=(n-max_freq);
        }
        sol[m]='\0';
        printf("%s\n%d\n", sol, ham_sum);

        return 0;
}