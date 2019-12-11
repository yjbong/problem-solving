#include <cstdio>
#include <cstring>

int main() {
    while(1){
        char name[11];
        int age,weight;
        scanf("%s %d %d",name,&age,&weight);
        if(!strcmp(name,"#") && !age && !weight) break;
        printf("%s ",name);
        if(age>17 || weight>=80) printf("Senior\n");
        else printf("Junior\n");
    }
    return 0;
}