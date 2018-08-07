#include <cstdio>
#include <cstring>
char input[1111];

int quad_length(int idx){
    if(input[idx]!='x') return 1;

    int curidx=idx+1;
    int sublen[4];

    // upper-left length
    sublen[0]=quad_length(curidx);
    curidx+=sublen[0];

    // upper-right length
    sublen[1]=quad_length(curidx);
    curidx+=sublen[1];

    // lower-left length
    sublen[2]=quad_length(curidx);
    curidx+=sublen[2];

    // lower-right length
    sublen[3]=quad_length(curidx);
    curidx+=sublen[3];

    return curidx-idx;
}

void quad_reverse(int idx){
    if(input[idx]!='x'){
        printf("%c",input[idx]);
        return;
    }
    else{
        int substart[4];

        substart[0]=idx+1;
        substart[1]=substart[0]+quad_length(substart[0]);
        substart[2]=substart[1]+quad_length(substart[1]);
        substart[3]=substart[2]+quad_length(substart[2]);

        printf("x");
        quad_reverse(substart[2]);
        quad_reverse(substart[3]);
        quad_reverse(substart[0]);
        quad_reverse(substart[1]);
    }
}

int main(void){

    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%s",input);
        quad_reverse(0);
        printf("\n");
    }

    return 0;
}