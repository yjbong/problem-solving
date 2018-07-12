#include <stdio.h>
#include <math.h>
int main(void){

        int input;
        int set_num, elem_num;
        scanf("%d", &input);
        input--;
        set_num=(int)floor(0.5*(sqrt(8*input+1)-1));
        elem_num=input-set_num*(set_num+1)/2;
        if(set_num%2==1) printf("%d/%d\n", elem_num+1, set_num+2-(elem_num+1));
        else printf("%d/%d\n", set_num+2-(elem_num+1), elem_num+1);
        return 0;
}