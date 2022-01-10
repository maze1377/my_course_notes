#include <stdio.h>

int strlen(char* str){
    int i;
    for(i=0;str[i];i++);
    return i;
}
void emptystr(char* str, int n){
    for(int i=0;i<n;i++){
        str[i]=0;
    }
}
int strappend(char* str, int n, char c){
    int len = strlen(str);
    if(len>=n-1) return 0;
    str[len] = c;
    str[len+1] = '\0';
    return 1;
}
int strcpy(char* dest, char* src, int n){
    for(int i=0;i<n;i++){
        dest[i] = src[i];
    }
    return 1;
}
int main(){
    char input_str[1000];
    char min_str[30];
    char max_str[30];
    char word[30];
    
    gets(input_str);

    emptystr(min_str,10);
    emptystr(max_str,30);
    emptystr(word,30);
    
    int in_str_len = strlen(input_str);
    for(int i=0;i<in_str_len+1;i++){
        if(input_str[i]!=' ' && input_str[i]!='.' && input_str[i]!=',' && input_str[i]!='\n' && input_str[i]!='\0'){
            if(!strappend(word,30,input_str[i])){
                return 1;
            }
        }else{
            int word_len = strlen(word);
            if(word_len>strlen(max_str)){
                strcpy(max_str,word,word_len);
            }if((word_len<strlen(min_str) || !strlen(min_str))&& word_len){
                emptystr(min_str,30);
                strcpy(min_str,word,word_len);
            }
            emptystr(word,30);
        }
    }
    puts(min_str);
    puts(max_str);

    return 0;
}