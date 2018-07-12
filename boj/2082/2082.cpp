#include <cstdio>
#include <cstdlib>
const char s[10][5][4]=
{
"###",
"#.#",
"#.#",
"#.#",
"###",

"..#",
"..#",
"..#",
"..#",
"..#",

"###",
"..#",
"###",
"#..",
"###",

"###",
"..#",
"###",
"..#",
"###",

"#.#",
"#.#",
"###",
"..#",
"..#",

"###",
"#..",
"###",
"..#",
"###",

"###",
"#..",
"###",
"#.#",
"###",

"###",
"..#",
"..#",
"..#",
"..#",

"###",
"#.#",
"###",
"#.#",
"###",

"###",
"#.#",
"###",
"..#",
"###"
};
char a[4][5][4];
char l[20];
int main(void){

    for(int i=0; i<5; i++){
        gets(l);
        for(int j=0; j<15; j++){
            a[j/4][i][j%4]=l[j];
        }
    }

    int sol[4];
    sol[0]=sol[1]=sol[2]=sol[3]=9;
    for(int i=0; i<4; i++){
        for(int j=8; j>=0; j--){
            bool ok=true;
            for(int k=0; k<5; k++){
                for(int l=0; l<3; l++){
                    if(a[i][k][l]=='#' && s[j][k][l]!='#'){
                        ok=false;
                        goto out;
                    }
                }
            }
            out:
            if(ok) sol[i]=j;
        }
    }
    printf("%1d%1d:%1d%1d\n",sol[0],sol[1],sol[2],sol[3]);
    return 0;
}