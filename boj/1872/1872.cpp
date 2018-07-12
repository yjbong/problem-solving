#include <cstdio>
#include <cstring>
int tc;
char str[10001];
int main(void){

	scanf("%d\n",&tc);
	while(tc--){
		gets(str);
		int len=strlen(str);
		//printf("%s %d\n",str,strlen(str));

		long long m,d,c,xc,l,x,ix,v,i;
		m=d=c=xc=l=x=ix=v=i=0;

		int start=0;
		// count "m" as many as possible
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='m'){
				m++; start=cur+1;
			}
		}
		
		// count "d" at most 1
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='d'){
				d++; start=cur+1;
				break;
			}
		}

		// count "c" at most 3
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='c'){
				c++; start=cur+1;
				if(c==3) break;
			}
		}
		
		// count "xc" at most 1 if c==3
		if(c==3){
			bool is_x=false, is_c=false;
			for(int cur=start; cur<len; cur++){
				if(str[cur]=='x') is_x=true;
				if(is_x==true && str[cur]=='c') is_c=true;
				if(is_x && is_c){
					xc++; start=cur+1;
					break;
				}	
			}
			if(xc==1) goto IX; // if xc exists, pass counting l and x
		}
		
		// count "l" at most 1
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='l'){
				l++; start=cur+1;
				break;
			}
		}

		// count "x" at most 3
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='x'){
				x++; start=cur+1;
				if(x==3) break;
			}
		}
IX:
		// count "ix" at most 1 if xc==1 || x==3
		if(xc==1 || x==3){
			bool is_i=false, is_x=false;
			for(int cur=start; cur<len; cur++){
				if(str[cur]=='i') is_i=true;
				if(is_i && str[cur]=='x') is_x=true;
				if(is_i && is_x){
					ix++; start=cur+1;
					break;
				}
			}
			if(ix==1) goto END; // if ix exists, pass counting v and i
		}

		// count "v" at most 1
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='v'){
				v++; start=cur+1;
				break;
			}
		}

		// count "i" at most 3
		for(int cur=start; cur<len; cur++){
			if(str[cur]=='i'){
				i++; start=cur+1;
				if(i==3) break;
			}
		}
END:
		long long ans = m*1000 + d*500 + c*100 + xc*90 + l*50 + x*10 + ix*9 + v*5 + i*1;
		printf("%lld\n",ans);
	}
	return 0;
}