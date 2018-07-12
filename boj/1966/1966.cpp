#include <stdio.h>
int queue[10000][2];
int main(void){

        int i,j;
        int cases, pages, target;
        int queue_start;
        int is_go_back;
        int printed;
        scanf("%d", &cases);
        while(cases--){
                scanf("%d %d", &pages, &target);
                for(i=0; i<pages; i++){
                        queue[i][0]=i;
                        scanf("%d", &queue[i][1]);
                }

                queue_start=0;
                printed=0;
                while(pages>0){

                        is_go_back=0;
                        for(i=queue_start+1; i<queue_start+pages; i++){
                                if(queue[queue_start][1]<queue[i][1]){
                                        is_go_back=1;
                                        break;
                                }
                        }

                        if(is_go_back==1){
                                queue[queue_start+pages][0]=queue[queue_start][0];
                                queue[queue_start+pages][1]=queue[queue_start][1];
                                queue_start++;
                        }
                        else{
                                printed++;
                                if(queue[queue_start][0]==target){
                                        printf("%d\n", printed);
                                        break;
                                }

                                queue_start++;
                                pages--;
                        }
                }
        }

        return 0;
}