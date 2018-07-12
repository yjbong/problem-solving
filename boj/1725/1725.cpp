#include <stdio.h>
#define MAX_HISTO 100000

typedef struct _histo_stack{

        int start_idx;
        int height;

}HISTO_STACK;
int main(void){


        int i, tmp;
        HISTO_STACK histo_stack[MAX_HISTO];
        int histo_stack_top;
        int histo_list[MAX_HISTO];
        int histo_lists;

        int max_rec, cur_rec;
        scanf("%d", &histo_lists);


        for(i=0; i<histo_lists; i++) scanf("%d", &histo_list[i]);

        max_rec=0;
        histo_stack_top=-1;
        for(i=0; i<histo_lists; i++){
                if(histo_stack_top<0 || histo_stack[histo_stack_top].height<histo_list[i]){
                        histo_stack_top++;
                        histo_stack[histo_stack_top].height=histo_list[i];
                        histo_stack[histo_stack_top].start_idx=i;
                }

                else if(histo_stack[histo_stack_top].height>histo_list[i]){

                        while(histo_stack_top>=0 && histo_stack[histo_stack_top].height>histo_list[i]){

                                cur_rec=histo_stack[histo_stack_top].height*(i-histo_stack[histo_stack_top].start_idx);
                                if(max_rec<cur_rec) max_rec=cur_rec;

                                histo_stack_top--;
                        }

                        tmp=histo_stack[histo_stack_top+1].start_idx;

                        histo_stack_top++;
                        histo_stack[histo_stack_top].height=histo_list[i];
                        histo_stack[histo_stack_top].start_idx=tmp;
                }
        }

        while(histo_stack_top>=0){
                cur_rec=histo_stack[histo_stack_top].height*(histo_lists-histo_stack[histo_stack_top].start_idx);
                if(max_rec<cur_rec) max_rec=cur_rec;

                histo_stack_top--;
        }

        printf("%d\n", max_rec);

        return 0;
}