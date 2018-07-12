#include <cstdio> 
long long a[111][111]; 
long long d[111][111]; 
  
int main(void){ 
  
    int n,m; 
    scanf("%d %d",&n,&m); 
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) scanf("%1lld",&a[i][j]); 
  
    d[0][0]=a[0][0]; 
    for(int i=1; i<n; i++) d[i][0]=d[i-1][0]+a[i][0]; 
    for(int j=1; j<m; j++) d[0][j]=d[0][j-1]+a[0][j]; 
    for(int i=1; i<n; i++) 
        for(int j=1; j<m; j++) 
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+a[i][j]; 
  
    long long sol=0; 
    for(int i=0; i<n-1; i++){ 
        for(int j=0; j<m-1; j++){ 
            long long s1=d[i][j]; 
            long long s2=d[i][m-1]-d[i][j]; 
            long long s3=d[n-1][j]-d[i][j]; 
            long long s4=d[n-1][m-1]-(s1+s2+s3);  
            if(sol<(s1+s2)*s3*s4) sol=(s1+s2)*s3*s4; 
            if(sol<(s1+s3)*s2*s4) sol=(s1+s3)*s2*s4; 
            if(sol<(s2+s4)*s1*s3) sol=(s2+s4)*s1*s3; 
            if(sol<(s3+s4)*s1*s2) sol=(s3+s4)*s1*s2; 
        } 
    } 
  
    for(int i=0; i<m-2; i++){ 
        for(int j=i+1; j<m-1; j++){ 
            long long s1=d[n-1][i]; 
            long long s2=d[n-1][j]-d[n-1][i]; 
            long long s3=d[n-1][m-1]-(s1+s2); 
            if(sol<s1*s2*s3) sol=s1*s2*s3; 
        } 
    } 
  
    for(int i=0; i<n-2; i++){ 
        for(int j=i+1; j<n-1; j++){ 
            long long s1=d[i][m-1]; 
            long long s2=d[j][m-1]-d[i][m-1]; 
            long long s3=d[n-1][m-1]-(s1+s2); 
            if(sol<s1*s2*s3) sol=s1*s2*s3; 
        } 
    } 
    printf("%lld\n",sol); 
    return 0; 
}