#include <stdio.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}
char list[15];
char cur_list[15];

int l,c;
void go(int cur_l, int cur_char_idx){

    int i;
    int moum,jaum;
    cur_list[cur_l-1]=list[cur_char_idx];

    if(cur_l==l){
        moum=jaum=0;
        for(i=0; i<l; i++){
            if(cur_list[i]=='a' || cur_list[i]=='e' || cur_list[i]=='i' || cur_list[i]=='o' || cur_list[i]=='u') moum++;
            else jaum++;
        }

        if(moum>=1 && jaum>=2){
            for(i=0; i<l; i++) printf("%c", cur_list[i]);
            printf("\n");
        }
    }

    else{
        for(i=cur_char_idx+1; i<c; i++) go(cur_l+1, i);
    }
}

int main(void){

    int i,j;
    char tmp;
    scanf("%d %d\n", &l, &c);
    for(i=0; i<c; i++){
        scanf("%c", &list[i]);
        if(i<c-1) scanf(" ");
    }

    for(i=0; i<c-1; i++)
        for(j=i+1; j<c; j++)
            if(list[i]>list[j]) SWAP(list[i],list[j],tmp);

    for(i=0; i<c; i++) go(1, i);

    return 0;
}