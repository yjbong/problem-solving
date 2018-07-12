#include <stdio.h>
#define MAXSCORE 1000
int main(void){

        int i, hiscore;
        int score[MAXSCORE], scores;
        double new_sum, new_avg;

        scanf("%d", &scores);

        if(scores<1) printf("0.00\n");

        else{
                for(i=0; i<scores; i++) scanf("%d", &score[i]);
                hiscore=0;
                for(i=0; i<scores; i++) if(score[i]>hiscore) hiscore=score[i];

                new_sum=0.0;
                for(i=0; i<scores; i++)
                        new_sum += (double)score[i]/hiscore*100.0;

                new_avg=new_sum/scores;
                printf("%.2lf\n", new_avg);
        }
        return 0;
}