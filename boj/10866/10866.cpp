#include <cstdio>
#include <cstring>
#include <cstdlib>
 
#define MAX 10000
int N; // 명령의 개수
int q[MAX+1];
int front, rear; // 유효한 데이터는 q[front ~ rear-1] 에 있음
bool isFull(){ return (rear+1)%(MAX+1)==front; }
bool isEmpty(){ return rear==front; }
int getSize(){
    if(rear>=front) return rear-front;
    else return rear+MAX+1-front;
}
 
int main() {
    // init queue
    front=rear=0;
    scanf("%d\n",&N);
    char input[101];
    for(int i=0; i<N; i++){
        fgets(input, 100, stdin);
        if(input[strlen(input)-1]=='\n') input[strlen(input)-1]=0;
        char *cmd=strtok(input, " ");
        
        // operation별 처리
        if(!strcmp(cmd, "push_front")){
            int data=atoi(strtok(NULL, " "));
            if(!isFull()){
                front=(front+MAX)%(MAX+1);
                q[front]=data;
            }
        }
        else if(!strcmp(cmd, "push_back")){
            int data=atoi(strtok(NULL, " "));
            if(!isFull()){
                q[rear]=data;
                rear=(rear+1)%(MAX+1);
            }
        }
        else if(!strcmp(cmd, "pop_front")){
            if(!isEmpty()){
                printf("%d\n",q[front]);
                front=(front+1)%(MAX+1);
            }
            else printf("-1\n");
        }
        else if(!strcmp(cmd, "pop_back")){
            if(!isEmpty()){
                rear=(rear+MAX)%(MAX+1);
                printf("%d\n",q[rear]);
            }
            else printf("-1\n");
        }
        else if(!strcmp(cmd, "size")){
            printf("%d\n",getSize());
        }
        else if(!strcmp(cmd, "empty")){
            printf("%d\n",isEmpty()?1:0);
        }
        else if(!strcmp(cmd, "front")){
            if(!isEmpty()){
                printf("%d\n",q[front]);
            }
            else printf("-1\n");
        }
        else if(!strcmp(cmd, "back")){
            if(!isEmpty()){
                printf("%d\n",q[(rear+MAX)%(MAX+1)]);
            }
            else printf("-1\n");
        }
    }
 
    return 0;
}