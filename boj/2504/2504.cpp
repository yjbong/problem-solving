#include <cstdio>
#include <cstring>

char a[33];
int d[33][33];
int main(void){

        scanf("%s",a);
        int l=strlen(a);

        for(int i=0; i<l-1; i++){
                if(a[i]=='(' && a[i+1]==')') d[i][i+1]=2;
                else if(a[i]=='[' && a[i+1]==']') d[i][i+1]=3;
        }

        for(int i=3; i<l; i+=2){
                for(int j=0; j+i<l; j++){
                        if(d[j+1][j+i-1]>0){
                                if(a[j]=='(' && a[j+i]==')') d[j][j+i]=d[j+1][j+i-1]*2;
                                else if(a[j]=='[' && a[j+i]==']') d[j][j+i]=d[j+1][j+i-1]*3;
                        }

                        for(int k=j+1; k<=j+i-2; k+=2)
                                if(d[j][k]>0 && d[k+1][j+i]>0) d[j][j+i]=d[j][k]+d[k+1][j+i];
                }
        }
        printf("%d\n",d[0][l-1]);
        return 0;
}