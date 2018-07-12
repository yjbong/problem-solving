#include <stdio.h>
#include <string.h>
char line[1001];
char b[102][102];
int main(void){

    int i,j,n,len,curx,cury;
    scanf("%d",&n);
    scanf("%s",line);
    len=strlen(line);

    for(i=0; i<=n+1; i++){
        for(j=0; j<=n+1; j++){
            if(i==0 || i==n+1 || j==0 || j==n+1) b[i][j]='X';
            else b[i][j]='.';
        }
    }

    curx=cury=1;
    for(i=0; i<len; i++){

        if(line[i]=='U'){
            if(b[cury-1][curx]!='X'){
                if(b[cury][curx]=='.') b[cury][curx]='|';
                else if(b[cury][curx]=='-') b[cury][curx]='+';

                if(b[cury-1][curx]=='.') b[cury-1][curx]='|';
                else if(b[cury-1][curx]=='-') b[cury-1][curx]='+';

                cury--;
            }
        }
        else if(line[i]=='D'){
            if(b[cury+1][curx]!='X'){
                if(b[cury][curx]=='.') b[cury][curx]='|';
                else if(b[cury][curx]=='-') b[cury][curx]='+';

                if(b[cury+1][curx]=='.') b[cury+1][curx]='|';
                else if(b[cury+1][curx]=='-') b[cury+1][curx]='+';

                cury++;
            }
        }

        else if(line[i]=='L'){
            if(b[cury][curx-1]!='X'){
                if(b[cury][curx]=='.') b[cury][curx]='-';
                else if(b[cury][curx]=='|') b[cury][curx]='+';

                if(b[cury][curx-1]=='.') b[cury][curx-1]='-';
                else if(b[cury][curx-1]=='|') b[cury][curx-1]='+';

                curx--;
            }
        }

        else if(line[i]=='R'){
            if(b[cury][curx+1]!='X'){
                if(b[cury][curx]=='.') b[cury][curx]='-';
                else if(b[cury][curx]=='|') b[cury][curx]='+';

                if(b[cury][curx+1]=='.') b[cury][curx+1]='-';
                else if(b[cury][curx+1]=='|') b[cury][curx+1]='+';

                curx++;
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            printf("%c",b[i][j]);
        printf("\n");
    }

    return 0;
}