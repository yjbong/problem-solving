#include <stdio.h>
int freq[26];
int main(void){
        int i, max_idx, maxs;
        char tmp;
        for(i=0; i<26; i++) freq[i]=0;
        while(scanf("%c", &tmp)==1){
                if(tmp>='a' && tmp<='z') freq[tmp-'a']++;
                else if(tmp>='A' && tmp<='Z') freq[tmp-'A']++;
        }

        for(i=1,max_idx=0,maxs=1; i<26; i++){
                if(freq[max_idx]<freq[i]){
                        max_idx=i;
                        maxs=1;
                }
                else if(freq[max_idx]==freq[i]) maxs++;
        }
        if(maxs>1) printf("?\n");
        else printf("%c\n", max_idx+'A');
        return 0;
}