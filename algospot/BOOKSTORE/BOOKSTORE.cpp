#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define INF 1000000000
using namespace std;
vector<pair<int,int> > book[111]; //book[i][j].first = j-th book's point at i-th store
                                  //book[i][j].second = j-th book's price at i-th store
int c,n,m;
int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&m);
                for(int i=0; i<m; i++) book[i].clear();
                for(int j=0; j<n; j++){
                        for(int i=0; i<m; i++){
                                int price,point;
                                scanf("%d %d",&price,&point);
                                book[i].push_back(make_pair(point,price));
                        }
                }
                for(int i=0; i<m; i++)
                        sort(book[i].begin(), book[i].end());

                int ans=INF;
                for(int i=0; i<m; i++){
                        int cur_spent=0;
                        int cur_point=0;
                        for(int j=n-1; j>=0; j--){
                                int price=book[i][j].second;
                                int point=book[i][j].first;

                                if(price>=cur_point){
                                        cur_spent+=(price-cur_point);
                                        cur_point=0;
                                }
                                else cur_point-=price;

                                cur_point+=point;
                        }

                        if(ans>cur_spent) ans=cur_spent;
                }
                printf("%d\n",ans);
        }
}