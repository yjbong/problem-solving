#include <cstdio>
int c,n;
int h[22222];

int max2(int a, int b){
        return a>=b?a:b;
}
int min2(int a, int b){
        return a<=b?a:b;
}
int maxrect(int left, int right){
        if(left>right) return 0;
        else if(left==right) return h[left];
        else{
                int mid=(left+right)/2;
                int ans=max2(maxrect(left,mid), maxrect(mid+1,right));

                int lidx=mid, ridx=mid+1;
                int minh=min2(h[lidx],h[ridx]);
                ans=max2(ans,minh*(ridx-lidx+1));

                while(lidx>left || ridx<right){
                        if(lidx>left && ridx<right){
                                if(h[lidx-1]>=h[ridx+1]){
                                        lidx--; minh=min2(minh,h[lidx]);
                                }
                                else{
                                        ridx++; minh=min2(minh,h[ridx]);
                                }
                        }
                        else if(lidx>left){
                                lidx--; minh=min2(minh,h[lidx]);
                        }
                        else if(ridx<right){
                                ridx++; minh=min2(minh,h[ridx]);
                        }

                        ans=max2(ans,minh*(ridx-lidx+1));
                }
                return ans;
        }
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%d",&h[i]);
                printf("%d\n", maxrect(0,n-1));
        }
        return 0;
}