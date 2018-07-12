#include <cstdio>
#include <cstring>
char time0[10];
char time1[10];
int main(void){
	gets(time0);
	gets(time1);

	int time0_hh=(time0[0]-'0')*10+time0[1]-'0';
	int time0_mm=(time0[3]-'0')*10+time0[4]-'0';
	int time0_ss=(time0[6]-'0')*10+time0[7]-'0';
	int time0_val=time0_hh*60*60+time0_mm*60+time0_ss;

	int time1_hh=(time1[0]-'0')*10+time1[1]-'0';
	int time1_mm=(time1[3]-'0')*10+time1[4]-'0';
	int time1_ss=(time1[6]-'0')*10+time1[7]-'0';
	int time1_val=time1_hh*60*60+time1_mm*60+time1_ss;

	int ans_val=time1_val-time0_val;
	if(ans_val<=0) ans_val+=24*60*60;
	int ans_hh=ans_val/60/60;
	int ans_mm=(ans_val/60)%60;
	int ans_ss=ans_val%60;
	printf("%02d:%02d:%02d\n",ans_hh,ans_mm,ans_ss);

	return 0;
}