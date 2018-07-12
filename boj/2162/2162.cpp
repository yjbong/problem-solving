#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int n;
int line_x1[3000]; int line_x2[3000];
int line_y1[3000]; int line_y2[3000];

int a[3000][3000]; // adj[i][j] = if line[i] and line[j] intersect 1, otherwise 0
int p[3000]; // parent[i] = line[i]'s parent. if line[i] does not have parent, (-p[i]) means the level of group whose top is line[i]
int size[3000]; // size[i] = the size of group whose top is line[i]

int ccw(int x1,int y1,int x2,int y2,int x3,int y3){

    int t;
    t = x2*y3 - y1*x2 - x1*y3 - y2*x3 + x1*y2 + y1*x3;
    if(t>0) return 1;
    else if(t<0) return -1;
    else return 0;
}

bool intersect_line(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int t;
    if(ii(x1,y1) > ii(x2,y2)){ swap(x1,x2); swap(y1,y2); }
    if(ii(x3,y3) > ii(x4,y4)){ swap(x3,x4); swap(y3,y4); }

    if((ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4)==0) && (ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)==0)){
        if(ii(x2,y2) < ii(x3,y3) || ii(x4,y4) < ii(x1,y1)) return false;
        else return true;
    }
    else if((ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4)<=0) && (ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)<=0)) return true;
    else return false;
}

int find2(int idx){
    while(p[idx]>=0) idx=p[idx];
    return idx;
}

void union2(int idx1,int idx2){
    int top_idx1=find2(idx1);
    int top_idx2=find2(idx2);

    if(top_idx1==top_idx2) return;

    if(p[top_idx1]<p[top_idx2]){
        p[top_idx2]=top_idx1;
        size[top_idx1]+=size[top_idx2];
    }
    else if(p[top_idx1]>p[top_idx2]){
        p[top_idx1]=top_idx2;
        size[top_idx2]+=size[top_idx1];
    }
    else{
        p[top_idx2]=top_idx1;
        p[top_idx1]--;
        size[top_idx1]+=size[top_idx2];
    }
}

int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d %d %d %d",&line_x1[i],&line_y1[i],&line_x2[i],&line_y2[i]);

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(intersect_line(line_x1[i],line_y1[i],line_x2[i],line_y2[i],line_x1[j],line_y1[j],line_x2[j],line_y2[j])) a[i][j]=1;

    for(int i=0; i<n; i++){
        p[i]=-1;
        size[i]=1;
    }

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i][j]) union2(i,j);

    int groups=0;
    int max_size=0;

    for(int i=0; i<n; i++){
        if(p[i]<0){
            groups++;
            if(max_size<size[i]) max_size=size[i];
        }
    }

    printf("%d\n",groups);
    printf("%d\n",max_size);
    return 0;
}