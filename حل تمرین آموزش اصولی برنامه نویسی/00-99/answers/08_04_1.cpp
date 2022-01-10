#include<stdio.h>

int strcmp(char str1[20], char str2[20]){
    int i;
    for(i=0;str1[i];i++){
        if(str1[i]!=str2[i]){
            return 0;
        }
    }
    if(!str2[i]){
        return 1;
    }
    return 0;
}

void str_lower_case(char* str){
    for(int i=0;str[i];i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]+=32;
        }
    }
}

int main(){
    char student1[100][20];
    char student2[100][20];
    int student1_word_num;
    int student2_word_num;
    int cheat_count=0;


    scanf("%d",&student1_word_num);
    for(int i=0;i<student1_word_num;i++){
        scanf("%s",student1[i]);
    }
    scanf("%d",&student2_word_num);
    for(int i=0;i<student2_word_num;i++){
        scanf("%s",student2[i]);
    }
    int range;
    if(student1_word_num>student2_word_num){
        range = student2_word_num;
    }
    else{
        range = student1_word_num;
    }
    for(int i=0;i<student1_word_num || i<student2_word_num;i++){
        str_lower_case(student1[i]);
        str_lower_case(student2[i]);
    }
    for (int i=0;i<student1_word_num;i++){
        for(int j=0; j<student2_word_num;j++){
            if(strcmp(student1[i],student2[j])){
                cheat_count++;
            }
        }
    }
    int cheat_percent;
    cheat_percent = (cheat_count*100)/range;
    if(cheat_percent>79){
        printf("Cheat");
    }else{
        printf("Clear");
    }
}