#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
vector <ii> v;
int a[9][9];

bool find_sol;

bool valid(int y, int x, int val){

    for(int i=0; i<9; i++)
        if(i!=x && a[y][i]==val) return false;

    for(int i=0; i<9; i++)
        if(i!=y && a[i][x]==val) return false;

    for(int i=y/3*3; i<=y/3*3+2; i++)
        for(int j=x/3*3; j<=x/3*3+2; j++)
            if(i!=y && j!=x && a[i][j]==val) return false;

    return true;
}

void go(int idx){

    if(find_sol) return;

    if(idx==v.size()){
        find_sol=true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                printf("%d",a[i][j]);
            printf("\n");
        }
        return;
    }

    int cy=v[idx].first; int cx=v[idx].second;

    for(int i=1; i<=9; i++){
        if(valid(cy,cx,i)){
            a[cy][cx]=i;
            go(idx+1);
            a[cy][cx]=0;
        }
    }
}

int main(void){

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            scanf("%1d",&a[i][j]);

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(!a[i][j]) v.push_back(make_pair(i,j));

    find_sol=false;
    go(0);
    return 0;
}