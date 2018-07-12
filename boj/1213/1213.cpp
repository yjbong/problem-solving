#include <stdio.h>
#include <string.h>
#define MAXLEN 50

int main(void){

        int i,j;
        char name[MAXLEN+1];
        char pal_name[MAXLEN+1];
        int freq[26];
        int name_len;
        int odd_freqs;
        int odd_freq_idx;
        int tmp_idx;
        int is_ok;

        scanf("%s", name);
        name_len=strlen(name);
        for(i=0; i<26; i++) freq[i]=0;
        for(i=0; i<name_len; i++) freq[name[i]-'A']++;

        odd_freqs=0;
        tmp_idx=0;
        is_ok=1;
        for(i=0; i<26; i++){

                if(freq[i]%2==1){
                        odd_freqs++;
                        if(odd_freqs>=2){
                                is_ok=0;
                                break;
                        }
                        odd_freq_idx=i;
                }

                j=0;
                while(j<freq[i]/2){

                        pal_name[tmp_idx]=i+'A';
                        pal_name[name_len-1-tmp_idx]=i+'A';
                        j++, tmp_idx++;
                }
        }

        if(odd_freqs==1) pal_name[tmp_idx]=odd_freq_idx+'A';
        pal_name[name_len]='\0';

        if(is_ok==1) printf("%s\n", pal_name);
        else printf("I'm Sorry Hansoo\n");

        return 0;
}