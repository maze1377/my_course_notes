#include<stdio.h>

int main(){
    char input[1000];

    fgets(input, 1000, stdin);

    char most_freq = '\0';
    int max_freq = 0;

    for(int i=0;input[i];i++){
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
            int counter =0;
            for(int j=0;input[j];j++){
                if(input[i]==input[j]){
                    counter++;
                }
            }
            if(counter > max_freq){
                max_freq = counter;
                most_freq = input[i];
            }
        }
    }

    printf("%c \n%d",most_freq,max_freq);
}