#include <stdio.h>
int day_in_month[12+1]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(void){
        int i,x,y;
        int days;
        scanf("%d %d", &x, &y);
        days=0;
        for(i=1; i<x; i++) days+=day_in_month[i];
        days+=y;

        switch(days%7){
                case 0:
                        printf("SUN");
                        break;
                case 1:
                        printf("MON");
                        break;
                case 2:
                        printf("TUE");
                        break;
                case 3:
                        printf("WED");
                        break;
                case 4:
                        printf("THU");
                        break;
                case 5:
                        printf("FRI");
                        break;
                case 6:
                        printf("SAT");
        }
        printf("\n");
        return 0;
}