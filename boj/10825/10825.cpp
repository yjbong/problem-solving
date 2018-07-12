#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N; // 학생의 수
typedef struct{
	char name[11];
	int korean;
	int english;
	int math;
}STUDENT;
STUDENT s[100000];

bool cmp(STUDENT a, STUDENT b){
	if(a.korean>b.korean) return true;
	else if(a.korean<b.korean) return false;
	else{
		if(a.english<b.english) return true;
		else if(a.english>b.english) return false;
		else{
			if(a.math>b.math) return true;
			else if(a.math<b.math) return false;
			else{
				if(strcmp(a.name, b.name)<0) return true;
				else return false;
			}
		}
	}
}
int main(void){
	scanf("%d\n",&N);
	for(int i=0; i<N; i++) scanf("%s %d %d %d\n",s[i].name,&s[i].korean,&s[i].english,&s[i].math);
	sort(s,s+N,cmp);
	for(int i=0; i<N; i++) printf("%s\n",s[i].name);	
	return 0;
}