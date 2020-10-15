#include <stdio.h>
// in tabe state ia haman vaziat safhe bazi ra migird va safe bazi ra chap mikonad
void print_border(int state[][3]){
	for(int row=0;row<5;row++){
		for(int column=0;column<5;column++){
			if(row%2==1){
				printf("-");
			}else{ // row%2==0
				if(column%2==1){
					printf("|");
				}else{
					if(state[row/2][column/2]==0){
						printf(" ");
					}else if(state[row/2][column/2]==1){
						printf("X");
					}else{// state[row/2][column/2]==2
						printf("O");
					}
				}
			}
		}
		printf("\n");
	}
}
//in tabe state bazi ra migirad va agar kasi barde shode bashad id bar migardanad dar gheir in sorat 0
int check_winner(int state[][3]){
	// row check
	for(int row=0;row<3;row++){	
		if(state[row][0]==state[row][1] && state[row][0]==state[row][2] && state[row][0]!=0){
			return state[row][0];
		}
	}
	// column check
	for(int column=0;column<3;column++){	
		if(state[0][column]==state[1][column] && state[0][column]==state[2][column] && state[0][column]!=0){
			return state[0][column];
		}
	}
	// barasi kardan movarab az bala be paiin
	if(state[0][0]==state[1][1] && state[1][1]==state[2][2] && state[1][1]!=0){
		return state[1][1];
	}
	// barasi kardan movarab az pain be bala
	if(state[2][0]==state[1][1] && state[1][1]==state[0][2] && state[1][1]!=0){
		return state[1][1];
	}
	
	return 0;
}
// vorodi ra az karbar mikhanad va state bazi ra update mikonad
void move(int state[][3],int turn){
	int pos_x,pos_y;
	do{// validate input
		printf("select available postion:");
		scanf("%d %d",&pos_x,&pos_y);
	}while(pos_x<0 || pos_x>3||pos_y<0 || pos_y>3 ||state[pos_x-1][pos_y-1]!=0);
	state[pos_x-1][pos_y-1]=turn;
}
// taghir nobat
void change_turn(int &turn){
	if(turn == 1){
		turn = 2;
	}else{
		turn = 1;
	}
}
// check is game over or not
bool is_game_over(int state[][3]){
	// shomaresh tam mohre haie mojod dar safe
	int coins=0;
	for(int row=0;row<3;row++)
		for(int column=0;column<3;column++)
			if(state[row][column]!=0)
				coins++;
	return coins==9 || check_winner(state)!=0;
}
//start point
int main() {
	int state[3][3]={{0}};
	int turn=1;
	print_border(state);
	while(!is_game_over(state)){
		move(state,turn);
		change_turn(turn);
		print_border(state);
	}
	int status_win =check_winner(state);
	if(status_win==0){
		printf("\nmosavi");
	}else if(status_win==1){
		printf("nafar aval bord");
	}else{//status_win == 2
		printf("nafar dovom bord");
	}
	return 0;
}
