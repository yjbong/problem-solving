#include <cstdio>
#include <cstring>
char s[111];
int main(void){
	scanf("%s",s);
	int n=strlen(s);
	int idx=0;
	int ans=0;
	while(idx<n){
		char t[10];
		if(idx+2<n){
			for(int i=0; i<3; i++) t[i]=s[idx+i];
			t[3]='\0';
			if(!strcmp(t,"dz=")){ ans++; idx+=3; continue; }
		}
		if(idx+1<n){
			for(int i=0; i<2; i++) t[i]=s[idx+i];
			t[2]='\0';
			if(!strcmp(t,"c=")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"c-")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"d-")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"lj")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"nj")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"s=")){ ans++; idx+=2; continue; }
			else if(!strcmp(t,"z=")){ ans++; idx+=2; continue; }
			else{ ans++; idx++; continue; }
		}
		else{ ans++; idx++; continue; }
	}
	printf("%d\n",ans);
	return 0;
}