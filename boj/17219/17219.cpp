#include <iostream>
#include <map>
using namespace std;
map<string,string> pwList;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string site, pw;
        cin >> site >> pw;
        //cout << site << " " << pw << "\n";
        pwList.insert(make_pair(site,pw));
    }
    for(int i=0; i<M; i++){
        string site;
        cin >> site;
        cout << pwList.find(site)->second << "\n";
    }
    return 0;
}