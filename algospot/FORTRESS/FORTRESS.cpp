#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int c,n;
vector<pair<int, pair<int, int> > > wall;

typedef struct node{
        int parent;
        vector <int> children;
}NODE;

NODE node[111];

int max2(int a, int b){

        return a>b?a:b;
}

int height(int cur_root){
        int ret=1;
        for(int i=0; i<node[cur_root].children.size(); i++){
                int ichild=node[cur_root].children[i];
                ret=max2(ret,height(ichild)+1);
        }
        return ret;
}

int diameter(int cur_root){

        int ret=1;
        for(int i=0; i<node[cur_root].children.size(); i++){
                int ichild=node[cur_root].children[i];
                ret=max2(ret,height(ichild)+1);
                for(int j=i+1; j<node[cur_root].children.size(); j++){
                        int jchild=node[cur_root].children[j];
                        ret=max2(ret,height(ichild)+height(jchild)+1);
                }
        }
        for(int i=0; i<node[cur_root].children.size(); i++){
                int ichild=node[cur_root].children[i];
                ret=max2(ret,diameter(ichild));
        }
        return ret;
}

int main(void){
        scanf("%d",&c);
        while(c--){
                wall.clear();

                scanf("%d",&n);
                for(int i=0; i<n; i++){
                        int x,y,r;
                        scanf("%d %d %d",&x,&y,&r);
                        wall.push_back(make_pair(r,make_pair(x,y)));
                }
                sort(wall.begin(),wall.end());

                /*
                for(int i=0; i<n; i++)
                        printf("(%d,%d) radius=%d\n",wall[i].second.first, wall[i].second.second, wall[i].first);
                printf("\n");
                */

                for(int i=0; i<n; i++){
                        node[i].parent=-1;
                        node[i].children.clear();
                }


                for(int i=0; i<n; i++){
                        int ix=wall[i].second.first, iy=wall[i].second.second, ir=wall[i].first;
                        for(int j=i+1; j<n; j++){
                                int jx=wall[j].second.first, jy=wall[j].second.second, jr=wall[j].first;
                                if((ix-jx)*(ix-jx)+(iy-jy)*(iy-jy) < (jr-ir)*(jr-ir)){ // wall[i] is in wall[j]
                                        node[i].parent=j;
                                        node[j].children.push_back(i);
                                        break;
                                }
                        }
                }

                /*
                for(int i=0; i<n; i++){
                        printf("node %d's parent=%d, children=",i, node[i].parent);
                        for(int j=0; j<node[i].children.size(); j++) printf("%d ",node[i].children[j]);
                        printf("\n");
                }
                */

                printf("%d\n",diameter(n-1)-1);
        }
        return 0;
}