#include <stdio.h>
int main(void){
        long double a, b;
        scanf("%llf %llf", &a, &b);
        printf("%.32llf\n", a/b);
        return 0;
}