#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCARS 1000
#define MAXLEN 10
typedef struct _car{

        int origin_pos;
        char name[MAXLEN];
}CAR;

CAR car[MAXCARS];
int cars;

int exit_order[MAXCARS];
int exit_orders;

int cmp(const void *a, const void *b){

        if(strcmp(((CAR *)a)->name, ((CAR *)b)->name)>0) return 1;
        else return 0;
}

int binsearch(char key[MAXLEN]){

        int left, right, mid;

        left=0, right=cars-1;
        while(left<=right){
                mid=(left+right)/2;
                if(strcmp(key, car[mid].name)>0) left=mid+1;
                else if(strcmp(key, car[mid].name)<0) right=mid-1;
                else return mid;
        }
        return -1;
}

int main(void){

        int i, j, sol;
        char cur_car_name[MAXLEN];
        int cur_idx;
        scanf("%d\n", &cars);
        for(i=0; i<cars; i++){
                scanf("%s\n", car[i].name);
                car[i].origin_pos=i+1;
        }

        qsort(car, cars, sizeof(CAR), cmp);

        exit_orders=0;
        for(i=0; i<cars; i++){
                scanf("%s\n", cur_car_name);
                cur_idx=binsearch(cur_car_name);
                if(cur_idx>=0){
                        exit_order[exit_orders]=car[cur_idx].origin_pos;
                        exit_orders++;
                }
        }

        sol=0;
        for(i=0; i<exit_orders; i++){
                for(j=i+1; j<exit_orders; j++){
                        if(exit_order[i]>exit_order[j]){
                                sol++;
                                break;
                        }
                }
        }
        printf("%d\n", sol);
        return 0;
}