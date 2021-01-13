#include <iostream>
#define MAXN 100000
using namespace std;

class MyHeap{
private:
    int heap[MAXN+1];
    int numData;
public:
    MyHeap(){ numData=0; }
    void push(int data){
        heap[++numData]=data;
        int idx=numData;
        while(idx/2>0 && heap[idx/2]<heap[idx]){
            int tmp=heap[idx/2];
            heap[idx/2]=heap[idx];
            heap[idx]=tmp;
            idx/=2;
        }
    }
    int pop(){
        if(numData==0) return 0;
        int top=heap[1];
        heap[1]=heap[numData--];
        int idx=1;
        while(1){
            if(numData<idx*2) break;
            int bigChild=idx*2;
            if(numData>=idx*2+1 && heap[bigChild]<heap[idx*2+1])
                    bigChild=idx*2+1;
            if(heap[idx]<heap[bigChild]){
                int tmp=heap[idx];
                heap[idx]=heap[bigChild];
                heap[bigChild]=tmp;
                idx=bigChild;
            }
            else break;
        }
        return top;
    }
};
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    MyHeap heap;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(num==0) cout << heap.pop() << "\n";
        else heap.push(num);
    }
    return 0;
}