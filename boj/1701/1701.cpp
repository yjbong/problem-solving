#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sfx_arr[5555];
char s[5555];

bool cmp(int a, int b){
        int i,j;
        i=a; j=b;
        while((i<strlen(s)) && (j<strlen(s))){
                if(s[i]>s[j]) return false;
                else if(s[i]<s[j]) return true;
                i++; j++;
        }
        if(a<b) return false;
        else return true;
}

int main(void){

        scanf("%s",s);
        for(int i=0; i<strlen(s); i++) sfx_arr[i]=i;
        sort(sfx_arr, sfx_arr+strlen(s), cmp);

        int sol=0;
        for(int i=0; i<strlen(s)-1; i++){
                int j,k;
                int csol=0;
                for(j=sfx_arr[i], k=sfx_arr[i+1]; j<strlen(s) && k<strlen(s); j++,k++){
                        if(s[j]==s[k]) csol++;
                        else break;
                }
                if(sol<csol) sol=csol;
        }
        printf("%d\n",sol);
        return 0;
}