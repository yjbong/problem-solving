#include <cstdio>
#include <cstring>
#include <cstdlib>
char str[100001];
int N;

typedef struct node{
    char data;
    struct node *prev;
    struct node *next;
}NODE;

NODE *head;
NODE *cursor;

NODE* init(char *str){

    NODE *cursor = head;
    int len=strlen(str);
    for(int i=0; i<len; i++){
        if(cursor->next==NULL){
            cursor->next = (NODE *)malloc(sizeof(NODE));
            cursor->next->data = str[i];
            cursor->next->prev = cursor;
            cursor->next->next = NULL;
            cursor = cursor->next;
        }
    }
    return cursor;
}

void print(void){
    NODE *cursor = head->next;
    while(cursor!=NULL){
        printf("%c", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

int main(void){

    head = (NODE *)malloc(sizeof(NODE));
    head->prev = NULL;
    head->next = NULL;
    head->data = '$';

    scanf("%s\n", str);

    // cursor->data : left char of the cursor
    // cursor->next->data : right char of the cursor
    cursor = init(str);

    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        char cmd[5];
        gets(cmd);
        switch(cmd[0]){

            case 'L':
                if(cursor->prev!=NULL) cursor = cursor->prev;
                break;

            case 'D':
                if(cursor->next!=NULL) cursor = cursor->next;
                break;

            case 'B':
                if(cursor->prev!=NULL){
                    // Remove nodes pointed by cursor
                    cursor->prev->next = cursor->next;
                    if(cursor->next!=NULL) cursor->next->prev = cursor->prev;

                    NODE *tmp = cursor;
                    cursor = cursor->prev;
                    free(tmp);
                }
            break;

            case 'P':
                // add a new node after cursor
                NODE *newNode = (NODE*)malloc(sizeof(NODE));
                NODE *tmp = cursor->next;

                cursor->next = newNode;
                if(tmp!=NULL) tmp->prev = newNode;

                newNode->prev = cursor;
                newNode->next = tmp;
                newNode->data = cmd[2];
                
                cursor = newNode;
            break;
        }
    }
    print();

    return 0;
}
