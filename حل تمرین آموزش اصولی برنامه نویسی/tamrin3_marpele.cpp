#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int myRandomFunction(){
    return rand()%6+1;
}
void show(int x){
    if(x==0) printf("not found ");
    else if(x%5==0) printf("(%d,5) ",x/5);
    else printf("(%d,%d) ",(x/5)+1,x%5);
}
void moveForward(int turn,int rnd,int &pos1,int &pos2){
    if(turn==1){
        if(pos1==0){
            if(rnd==6){
                pos1=1;
            }
        }
        else if(pos1+rnd<=25){
            pos1+=rnd;
            if(pos1==18){
                pos1-=5;
            }
            else if(pos1==12){
                pos1+=10;
            }
        }
    }
    else{//if(turn==2)
        if(pos2==0){
            if(rnd==6){
                pos2=1;
            }
        }
        else if(pos2+rnd<=25){
            pos2+=rnd;
            if(pos2==18){
                pos2-=5;
            }
            else if(pos2==12){
                pos2+=10;
            }
        }
    }
}
int main(){
    srand(time(NULL));
    int turn=1;
    int pos1=0;
    int pos2=0;
    while(1){
        int rnd=myRandomFunction();
        moveForward(turn,rnd,pos1,pos2);
        printf("%d ",rnd);
        show(pos1);
        show(pos2);
        printf("\n");
        if(pos1==25){
            printf("Player 1 won");
            return 0;
        }
        else if(pos2==25){
            printf("Player 2 won");
            return 0;
        }
        if(turn==1 && rnd!=6){
            turn=2;
        }
        else if(turn==2 && rnd!=6){
                turn=1;
        }
    }
}
