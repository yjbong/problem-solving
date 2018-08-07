#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int c;
bool d[111][111];

string w; int wlen;
vector <string> f; int flen;

int main(void){

        cin>>c;
        while(c--){
                cin>>w;
                wlen=w.length();

                f.clear();
                int fs;
                cin>>fs;
                for(int i=0; i<fs; i++){
                        string tmp;
                        cin>>tmp;
                        f.push_back(tmp);
                }

                std::sort(f.begin(), f.end());

                for(int i=0; i<fs; i++){
                        flen=f[i].length();

                        for(int j=0; j<=wlen; j++)
                                for(int k=0; k<=flen; k++) d[j][k]=false;
                        d[0][0]=true;

                        for(int j=1; j<=wlen; j++){
                                for(int k=0; k<=flen; k++){
                                        char cur_w=w[j-1];
                                        char cur_f=f[i][k-1];

                                        if(cur_w=='*' && d[j-1][k])
                                                for(int l=k; l<=flen; l++) d[j][l]=true;
                                        else if(k>0 && cur_w=='?' && d[j-1][k-1]) d[j][k]=true;
                                        else if(k>0 && cur_w==cur_f && d[j-1][k-1]) d[j][k]=true;
                                }
                        }

                        if(d[wlen][flen])
                                cout<<f[i]<<endl;
                }
        }
        return 0;
}