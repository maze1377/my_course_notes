#include<stdio.h>
#include<string.h>

void reverse(char str[]){
    int len = strlen(str);
    char tmp[len+1];
    int j=0;
    for(int i=len-1;i>=0;i--){
        tmp[j] = str[i];
        j++;
    }
    tmp[j]=0;
    strcpy(str,tmp);
}

void shift_right(char str[]){
    str[strlen(str)-1] = '\0';
}

void shift_left(char str[]){
    int i;
    for (i=1;str[i];i++){
        str[i-1] = str[i];
    }
    str[i-1] = 0;
}

void rotate(char str[]){
    char tmp = str[0];
    shift_left(str);
    int len = strlen(str);
    str[len] = tmp;
    str[len+1] = 0;
}

int is_lower_case(char c){
	return (c >= 'a' && c <= 'z');
}

int is_upper_case(char c){
    return (c >= 'A' && c <= 'Z');
}
void upper_case(char str[]){
    for(int i=0;str[i];i++){
        if(is_lower_case(str[i])){
            str[i] -= 32;       
        }
    }
}

void lower_case(char str[]){
    for(int i=0;str[i];i++){
        if(is_upper_case(str[i])){
            str[i] += 32;       
        }
    }
}

int main(){

    FILE* inputfp;
    FILE* outputfp;
    inputfp = fopen("input.txt","r");
    outputfp = fopen("output.txt","w");

    char in_str[100];
    fgets(in_str, 100, inputfp);
    in_str[strlen(in_str)-1] = '\0';

    do{
        char instruction[7];
        fgets(instruction, 10, inputfp);
        instruction[strlen(instruction)-1] = '\0';
        if(strcmp(instruction, "Rev")==0){
            reverse(in_str);
        }else if(strcmp(instruction, "Rot")==0){
            rotate(in_str);
        }else if(strcmp(instruction, "SR")==0){
            shift_right(in_str);
        }else if(strcmp(instruction, "SL")==0){
            shift_left(in_str);
        }else if(strcmp(instruction, "UC")==0){
            upper_case(in_str);
        }else if(strcmp(instruction, "LC")==0){
            lower_case(in_str);
        }else if(strcmp(instruction, "Print")==0){
            fprintf(outputfp, "%s\n", in_str);
        }
    }while(!feof(inputfp));

    return 0;
}