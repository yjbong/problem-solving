#include <cstdio>
int n;
int a[55]; // input sequence
int s; // maximum swap count

int rank[55]; // rank[i] = rank of i-th num
int rankNum[55]; // rankNum[i] = the number whose rank is i
int curPos[55]; // curPos[i] = current position of the number whose rank is i
bool check[55]; // check[i] = true if i should be considered to move left

int main(void){

        while(scanf("%d",&n)==1){
                for(int i=0; i<n; i++) scanf("%d",&a[i]);
                scanf("%d",&s);

                // build rank array
                for(int i=0; i<n; i++) rank[i]=0;
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                if(a[j]>a[i]) rank[i]++;

                // build rankNum array
                for(int i=0; i<n; i++)
                        rankNum[rank[i]]=a[i];

                // transform input sequence array
                for(int i=0; i<n; i++)
                        a[i] = rank[i];

                // init curPos array
                for(int i=0; i<n; i++)
                        curPos[a[i]]=i;

                // init check array
                for(int i=0; i<n; i++) check[i] = false;

                // sorting
                for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++){
                                if(s>=curPos[j]-i && check[j]==false){ // possible to move
                                        if(curPos[j]-i>0){
                                                s-=curPos[j]-i;
                                                int tmp = a[curPos[j]];
                                                for(int k=curPos[j]-1; k>=i; k--){
                                                        a[k+1] = a[k];
                                                        curPos[a[k+1]] = k+1;
                                                }
                                                a[i] = tmp;
                                                curPos[j] = i;
                                        }
                                        check[j] = true;
                                        break;
                                }
                        }
                }

                // print answer
                for(int i=0; i<n; i++)
                        printf("%d ",rankNum[a[i]]);
                printf("\n");
        }
        return 0;
}