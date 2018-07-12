#include <stdio.h>
#define MAX_PERSON 5000
int main(void){

        int i;
        int N, M;
        int alive[MAX_PERSON+1];
        int cur_steps, remains, cur_person;
        int is_first=1;
        scanf("%d %d", &N, &M);

        for(i=1; i<=N; i++) alive[i]=1;
        cur_steps=0;
        cur_person=0;
        remains=N;
        while(remains>0){
                cur_person++;
                if(cur_person>N) cur_person=1;
                if(alive[cur_person]==1) cur_steps++;

                if(cur_steps==M){
                        cur_steps=0;
                        alive[cur_person]=0;
                        if(is_first==1){
                                printf("<");
                                is_first=0;
                        }
                        printf("%d", cur_person);
                        if(remains==1) printf(">");
                        else printf(", ");
                        remains--;
                }
        }
        printf("\n");
        return 0;
}