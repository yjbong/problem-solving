#include <stdio.h>
#include <string.h>
const char color[10][8]={"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int main(void){
 
        int i,j,result;
        int color_idx;
        char line[8];
        result=0;
        for(i=0; i<3; i++){
                scanf("%s", line);
                for(j=0; j<10; j++){
                        if(strcmp(color[j], line)==0){
                                color_idx=j;
                                break;
                        }
                }
                if(i<2){
                        result*=10;
                        result+=color_idx;
                }
                else{
                        printf("%d", result);
						if(result>0)
							for(j=0; j<color_idx; j++) printf("0");
                }
        }
        printf("\n");
        return 0;
}