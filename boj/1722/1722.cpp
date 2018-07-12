#include <stdio.h>
#define MAXPERMS 20
int main(void){
        long long option,i,j,k,l,tmp;
        long long perm[MAXPERMS+1];
        long long perms, cur_perms, cur_iter_num;
        long long is_used[MAXPERMS+1];
        long long perm_num, tot_perms, before_nums;
        scanf("%lld", &perms);
        scanf("%lld", &option);
        if(option==1){
                scanf("%lld", &perm_num);

                tot_perms=1;
                for(i=1; i<=perms; i++){
                        is_used[i]=0;
                        tot_perms*=i;
                }

                tmp=tot_perms;
                perm_num--;

                for(i=1, j=perms; i<=perms; i++, j--){

                        tmp/=j;
                        before_nums=perm_num/tmp;
                        for(k=1, l=0; l<before_nums; k++){
                                if(is_used[k]==0) l++;
                        }

                        while(is_used[k]==1) k++;

                        perm[i]=k;
                        is_used[perm[i]]=1;
                        perm_num -= before_nums*tmp;
                }

                for(i=1; i<=perms; i++){
                        printf("%lld", perm[i]);
                        if(i<perms) printf(" ");
                }
        }

        else if(option==2){

                tot_perms=1;
                for(i=1; i<=perms; i++){
                        scanf("%lld", &perm[i]);
                        is_used[i]=0;
                        tot_perms*=i;
                }

                tmp=tot_perms;
                perm_num=1;

                for(i=1, j=perms; i<=perms; i++, j--){

                        tmp/=j;
                        before_nums=0;
                        for(k=1; k<perm[i]; k++){
                                if(is_used[k]==0) before_nums++;
                        }
                        is_used[perm[i]]=1;
                        perm_num += before_nums*tmp;
                }
                printf("%lld\n", perm_num);

        }
        return 0;
}