#include <cstdio>
#include <cstring>
int n; // 채널 수
char ch[100][11]; // 채널 이름
int kbs1_pos, kbs2_pos;

int main(void){

	scanf("%d\n",&n);
	for(int i=0; i<n; i++) gets(ch[i]);

	for(int i=0; i<n; i++){
		if(strcmp(ch[i],"KBS1")==0) kbs1_pos=i;
		if(strcmp(ch[i],"KBS2")==0) kbs2_pos=i;
	}

	for(int i=0; i<kbs1_pos; i++) printf("1");
	for(int i=0; i<kbs1_pos; i++) printf("4");

	if(kbs2_pos<kbs1_pos) kbs2_pos++;
	for(int i=0; i<kbs2_pos; i++) printf("1");
	for(int i=0; i<kbs2_pos-1; i++) printf("4");
	printf("\n");

	return 0;
}