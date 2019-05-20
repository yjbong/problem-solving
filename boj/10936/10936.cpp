#include <cstdio>
#include <cstring>

char in[101]; // Base64 encoded string

int main(void){

    scanf("%s",in);
    int len=strlen(in);
    for(int i=0; i<len; i+=4){
        int equals=0;
        for(int j=3; j>=0; j--) if(in[i+j]=='=') equals++;
        int chars=(24-equals*6)/8;

        int buf=0; // 24-bit buffer
        for(int j=0; j<4; j++){
            if(in[i+j]=='=') continue;
            int curVal;
            if(in[i+j]>='A' && in[i+j]<='Z') curVal = in[i+j]-'A';
            else if(in[i+j]>='a' && in[i+j]<='z') curVal = in[i+j]-'a'+26;
            else if(in[i+j]>='0' && in[i+j]<='9') curVal = in[i+j]-'0'+52;
            else if(in[i+j]=='+') curVal = 62;
            else curVal = 63;
            buf |= curVal<<((3-j)*6);
        }

        int curOut[3];
        for(int j=0; j<chars; j++)
            printf("%c",(buf&(0xff<<(8*(2-j))))>>(8*(2-j))); 
    }
    printf("\n");
    return 0;
}
