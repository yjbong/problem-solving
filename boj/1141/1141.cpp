#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_N 50 // 단어의 최대 개수
#define MAXLEN 50 // 단어의 최대 길이
using namespace std;
typedef struct{
    char ch; // 현재 노드가 나타내는 문자
    int next[26]; // 문자 a~z 가 들어왔을 때 이동할 노드의 번호(음수면 invalid)
    bool isTerminal; // 현재 노드에서 끝나는 word가 있으면 true
}TRIE;
TRIE trie[MAX_N*MAXLEN+1];
 
int N; // 단어의 개수
char word[MAXLEN+1];
 
void initNode(int idx, char ch, bool isTerminal){
    if(ch>='a' && ch<='z') trie[idx].ch=ch;
    else trie[idx].ch=0;
    for(int i=0; i<26; i++) trie[idx].next[i]=-1;
    trie[idx].isTerminal=isTerminal;
}
int nodes;
int main(void){
 
    // add dummy root node (node number 0)
    initNode(0,0,false);
    nodes=1;
 
    cin >> N;
    cin.get();
    for(int i=0; i<N; i++){
        //// 각 단어를 입력받아 trie에 추가
        cin.getline(word, MAXLEN+1);
        int trieIdx=0, wordIdx=0, wordLen=strlen(word);
        // 문자값에 따라 기존에 존재하는 노드들을 탐색
        while(wordIdx<wordLen && trie[trieIdx].next[word[wordIdx]-'a']>=0){
            trieIdx=trie[trieIdx].next[word[wordIdx]-'a'];
            if(wordIdx==wordLen-1) trie[trieIdx].isTerminal=true;
            wordIdx++;
        }
        // 기존 노드 탐색 후에 남은 문자가 있는 경우 새 노드를 추가
        for(; wordIdx<wordLen; wordIdx++){
            trie[trieIdx].next[word[wordIdx]-'a']=nodes;
            initNode(nodes, word[wordIdx], wordIdx==wordLen-1?true:false);
            trieIdx=nodes++;
        }
    }
 
    // 답 출력
    int ans=0;
    for(int i=0; i<nodes; i++){
        if(!trie[i].isTerminal) continue; // 단어를 나타내는 노드가 아니면 pass
        bool isLeaf=true;
        for(int j=0; j<26; j++){
            if(trie[i].next[j]>=0){
                isLeaf=false; break;
            }
        }
        if(isLeaf) ans++; // leaf라면, 현재 노드가 나타내는 단어를 접두사로 하는 다른 단어가 없는 것임
    }
    printf("%d\n",ans);
    return 0;
}