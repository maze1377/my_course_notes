#include<stdio.h>

int strlen(char str[101]){
    int size;
    for(size=0;str[size];size++);
    return size;

    /* "abcd" {a,b,c,d,\0} */
}

int abs(int n){
    if(n<0){
        return (-1 * n);
    }
    return n;
}

int main(){
    char pass[101];
    scanf("%s",pass);

    int size = strlen(pass);

    int i;
    for(i=0;i<size-1;i++){
        int diff = abs(pass[i] - pass[i+1]);
        pass[i] = 'a' + diff;
    }
    pass[i] = '\0';
    printf("%s",pass);

}