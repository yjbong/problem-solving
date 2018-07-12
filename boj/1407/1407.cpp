#include <stdio.h>  
long long pw[61];  
int main(void){  
    
     int i;  
     long long a,b,sol;  
     pw[0]=1;  
     for(i=1; i<=60; i++) pw[i]=pw[i-1]*2;  
     scanf("%lld %lld", &a, &b);  
     sol=0;  
     for(i=0; i<60; i++)  
         sol+=pw[i]*(b/pw[i]-b/pw[i+1]);  
    
     for(i=0; i<60; i++)  
         sol-=pw[i]*((a-1)/pw[i]-(a-1)/pw[i+1]);  
    
     printf("%lld\n", sol);
     return 0;  
}