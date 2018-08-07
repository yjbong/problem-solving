#include <cstdio>
#include <cstring>

int tc,n;
char word[1111][22];

int indeg[26];
int outedge[26][26];
int outedges[26];
bool check[26];
int result[26];
int results;
bool edge_check[26][26];

int min2(int a, int b){
        return a<b?a:b;
}
int main(void){
        scanf("%d",&tc);
        while(tc--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%s",word[i]);
                for(int i=0; i<26; i++){
                        indeg[i]=0;
                        outedges[i]=0;
                        check[i]=false;
                }
                for(int i=0; i<26; i++)
                        for(int j=0; j<26; j++) edge_check[i][j]=false;

                bool valid=true;
                for(int i=0; i<n; i++){
                        for(int j=i+1; j<n; j++){
                                bool diff_found=false;
                                for(int k=0; k<min2(strlen(word[i]),strlen(word[j])); k++){
                                        if(word[i][k]!=word[j][k]){
                                                diff_found=true;
                                                int from=word[i][k]-'a', to=word[j][k]-'a';
                                                if(edge_check[from][to]==false){
                                                        edge_check[from][to]=true;
                                                        outedge[from][outedges[from]++]=to;
                                                        indeg[to]++;
                                                }
                                                break;
                                        }
                                }
                                if(diff_found==false && strlen(word[i])>strlen(word[j])) valid=false;
                        }
                }

                if(valid){
                        results=0;
                        for(int i=0; i<26; i++){
                                for(int j=0; j<26; j++){
                                        if(check[j]==false && indeg[j]==0){
                                                check[j]=true;
                                                result[results++]=j;
                                                for(int k=0; k<outedges[j]; k++) indeg[outedge[j][k]]--;
                                                break;
                                        }
                                }
                        }
                        if(results<26) valid=false;
                }

                if(valid){
                        for(int i=0; i<results; i++) printf("%c",result[i]+'a');
                        printf("\n");
                }
                else printf("INVALID HYPOTHESIS\n");
        }
        return 0;
}