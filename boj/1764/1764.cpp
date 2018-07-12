#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSON 500000
#define MAXLEN 20
char no_hear[MAX_PERSON][MAXLEN+1];
char cur_no_see[MAXLEN+1];
char no_hear_no_see[MAX_PERSON][MAXLEN+1];

int string_cmp(const void *a, const void* b){

        if(strcmp((char*)a, (char*)b)>0) return 1;
        else if(strcmp((char*)a, (char*)b)<0) return -1;
        else return 0;
}

int main(void){

        int i, left, right, mid;
        int no_hears, no_sees;
        int no_hear_no_sees;
        scanf("%d %d", &no_hears, &no_sees);
        for(i=0; i<no_hears; i++){
                scanf("%s", no_hear[i]);
        }

        qsort(no_hear, no_hears, sizeof(char)*(MAXLEN+1), string_cmp);

        no_hear_no_sees=0;
        for(i=0; i<no_sees; i++){
                scanf("%s", cur_no_see);

                left=0, right=no_hears-1;
                while(left<=right){
                        mid=(left+right)/2;
                        if(strcmp(cur_no_see, no_hear[mid])>0) left=mid+1;
                        else if(strcmp(cur_no_see, no_hear[mid])<0) right=mid-1;
                        else{
                                strcpy(no_hear_no_see[no_hear_no_sees], cur_no_see);
                                no_hear_no_sees++;
                                break;
                        }
                }
        }

        qsort(no_hear_no_see, no_hear_no_sees, sizeof(char)*(MAXLEN+1), string_cmp);
        printf("%d\n", no_hear_no_sees);
        for(i=0; i<no_hear_no_sees; i++){
                printf("%s\n", no_hear_no_see[i]);
        }
        return 0;
}