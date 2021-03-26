#include <stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;

void init_board(piece board[][8]);	
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_1();
void sample_game_2();
int blocked(piece board[][8],int x,int y);
void read_location(int *from_x , int *from_y , int *to_x , int *to_y);
int check_move_avaibilty(piece board[][8], int from_x, int from_y, int to_x, int to_y);
void change_to_king(piece board[][8]);
int count(piece board[][8]);
void temp_move(piece board[][8], int from_x, int from_y, int to_x, int to_y);



int main(){
	piece board[8][8];
	player p = white ;
	int from_x,from_y,to_x,to_y,go=0,win,a=0;
	int choose ;
	printf("enter 1 to play the game \n");
	printf("enter 2 to display  sample game 1 \n");
	printf("enter 3 to display  sample game 2 \n");
	scanf("%d",&choose);
	if(choose == 1){
		init_board(board);
		display_board(board);
		do{
			
			read_location( &from_x , &from_y , &to_x , &to_y);
			if (a%2 == 1){
				go = move(board,from_x,from_y,to_x,to_y,white);
				if(go == -1)
					printf("you  tried to move a piece doesnt belong to you ....you lost your turn\n");
				else if(go == -2)
					printf("The move is not allowed. \n");
			}
			else{
				go = move(board,from_x,from_y,to_x,to_y,black);
				if(go == -1)
					printf("you  tried to move a piece doesnt belong to you ....you lost your turn\n");
				else if(go == -2)
					printf("The move is not allowed. \n");	
			}
			win = check_end_of_game(board); 
			a++;
			
			
		}while( win == -1);
		if(win == white)
			printf("the winner is the white player\n");
		else if(win == black)
			printf("the winner is the black player\n");
	}
	else if(choose == 2){
		sample_game_1();
	}
	else if (choose == 3){
		sample_game_2();
	}


	
	


	return 0;
}
void init_board(piece board[][8]){
	int i;

	for(i=0;i<8;i++){
		board[0][i]=empty;
		board[1][i]=white_man;
		board[2][i]=white_man;
		board[3][i]=empty;
		board[4][i]=empty;
		board[5][i]=black_man;
		board[6][i]=black_man;
		board[7][i]=empty;
	}
		

}


void display_board(piece board[][8]){

	int i , j;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==white_man)
				printf("w " );
			else if(board[i][j]==black_man)
				printf("b ");
			else if(board[i][j]==black_king)
				printf("B ");
			else if(board[i][j]==white_king)
				printf("W ");
			else if(board[i][j]==empty)
				printf("- ");
			
			
			 
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");

}

int blocked(piece board[][8],int x,int y){

		int black_1 = 0 , black_2 = 0 , black_3 = 0;
		int white_1 = 0, white_2 = 0 , white_3 = 0 ;
		int king_1 = 0 , king_2 = 0 , king_3 = 0;


	if( board[x][y] == black_man){// Checks if the  black man is trapped 
		if((board[x-1][y] != empty && x-1 >=0)){// Checks if the  black man is trapped from the top
			if((board[x-2][y] != empty && x-2 >=0) || x-2 < 0 ){
				black_1=1;
			}
		}
		
		if((board[x][y+1] != empty && y+1 < 8) || y+1 >= 8 ){// Checks if the  black man is trapped from the right side
			if((board[x][y+2] != empty && y+2 < 8 ) || y + 2 > 8 ){
				black_2=1;
			}
		}
		if((board[x][y-1] != empty && y-1 >= 0 ) || y-1 >= 0){// Checks if the  black man is trapped from the right side
			if((board[x][y-2] != empty && y-2 >= 0 ) || y - 2 < 0 ){
				black_3=1;
			}
		}	
	}

	if(black_1 ==1 && black_2 ==1 && black_3 ==1 )
		return 1;


	if( board[x][y] == white_man){// Checks if the  white man is trapped 
		if((board[x+1][y] != empty && x+1 < 8 )){// Checks if the  white man is trapped from the bottom
			if((board[x+2][y] != empty && x+2 < 8) || x+2 >=  8 ){
				white_1=1;
			}
		}
		
		if((board[x][y+1] != empty && y+1 < 8) || y+1 >= 8 ){// Checks if the  white man is trapped from the right side
			if((board[x][y+2] != empty && y+2 < 8 ) || y + 2 >= 8 ){
				white_2=1;
			}
		}
		if((board[x][y-1] != empty && y-1 >= 0 ) || y-1 >= 0){// Checks if the  white man is trapped from the right side
			if((board[x][y-2] != empty && y-2 >= 0 ) || y - 2 < 0 ){
				white_3=1;
			}
		}	
	
		if(white_1 && white_2 && white_3 )
			return 1;

	}
	if(board[x][y] == white_king || black_king){
		if((board[x+1][y] != empty && x+1 < 8 ) || x + 1 >= 8 ){// Checks if the  king is trapped from the bottom
			if((board[x+2][y] != empty && x+2 < 8) || x+2 >=  8 ){
				king_1=1;
			}
		}
		
		if((board[x][y+1] != empty && y+1 < 8) || y+1 >= 8 ){// Checks if the  white man is trapped from the right side
			if((board[x][y+2] != empty && y+2 < 8 ) || y + 2 >= 8 ){
				king_2=1;
			}
		}
		if((board[x][y-1] != empty && y-1 >= 0 ) || y-1 >= 0){// Checks if the  white man is trapped from the right side
			if((board[x][y-2] != empty && y-2 >= 0 ) || y - 2 < 0 ){
				king_3=1;
			}
		}
		if(king_1 && king_2 && king_3 ){

			return 1;	
		}
	}
	return 0;

}
int check_end_of_game(piece board[][8]){

	int count_b =0 ,
		count_w =0 ,
		count_block_b =0 ,
		count_block_w =0 ,
		i , j;


		for(i=0 ; i < 8 ; i++){
			for(j = 0 ; j < 8 ; j++ ){
				if(board[i][j] == black_man || board[i][j] == black_king){
					count_b++;
					count_block_b += blocked(board,i,j);

				}
				else if(board[i][j] == white_man || board[i][j] == white_king){
					count_w++;
					count_block_w += blocked(board,i,j);
				}

			}
		}

		if(count_b == 0){
			printf("the winner is the white player\n");
			return white;
		}
		else if(count_w == 0){
			printf("the winner is the black player\n");
			return black;
		}
		else if(count_b == count_block_b){
			printf("the winner is the white player\n");
			return white;
		}
		else if(count_w == count_block_w){
			printf("the winner is the black player\n");
			return black;
		}
		else 
			return -1 ;
}

void read_location(int *from_x , int *from_y , int *to_x , int *to_y){

		printf("from x >>");
		scanf("%d",from_x);
		printf("from y >>");
		scanf("%d",from_y);
		printf("to x >>");
		scanf("%d",to_x);
		printf("to y >>");
		scanf("%d",to_y);

}

int check_location(piece board[][8], int from_x, int from_y, player p){



	if (p == white){
		if (board[from_x][from_y] == white_man || board[from_x][from_y] == white_king){
			return 1;
		}
	}
	if (p == black){
		if (board[from_x][from_y] == black_man || board[from_x][from_y] == black_king){
			return 1;
		}
	}
	return 0 ;

}

int check_move_avaibilty(piece board[][8], int from_x, int from_y, int to_x, int to_y){

	int i , cont =0 ;

	if ((from_x >= 0 && from_x < 8) && (from_y >= 0 && from_y < 8) && 
		(to_x >= 0 && to_x < 8) && (to_y >= 0 && to_y < 8)) {
		if ( board[from_x][from_y] == white_man ){
			if (board[from_x+1][from_y] == empty && from_x+1 == to_x && from_y == to_y){
				return 1 ;}
			else if(board[from_x][from_y+1] == empty && from_y+1 == to_y && from_x == to_x ){return 1;}
			else if(board[from_x][from_y-1] == empty && from_y-1 == to_y && from_x == to_x){return 1;}
			else if((board[from_x+1][from_y] == black_man || board[from_x+1][from_y] == black_king) && 
					board[from_x+2][from_y] == empty && from_x+2 == to_x && from_y == to_y){return 1 ;}
			else if((board[from_x][from_y+1] == black_man || board[from_x][from_y+1] == black_king) && 
					board[from_x][from_y+2] == empty && from_y+2 == to_y && from_x == to_x){return 1 ;}
			else if((board[from_x][from_y-1] == black_man || board[from_x][from_y-1] == black_king) && 
					board[from_x][from_y-2] == empty && from_y-2 == to_y && from_x == to_x){return 1 ;}
			else {
				return 0 ;
			}
		}
		else if (board[from_x][from_y] == black_man){
			if (board[from_x-1][from_y] == empty && from_x-1 == to_x && from_y == to_y){return 1 ;}
			else if(board[from_x][from_y+1] == empty && from_y+1 == to_y && from_x == to_x ){return 1;}
			else if(board[from_x][from_y-1] == empty && from_y-1 == to_y && from_x == to_x){return 1;}
			else if((board[from_x-1][from_y] == white_man || board[from_x-1][from_y] == white_king) && 
					board[from_x-2][from_y] == empty && from_x-2 == to_x && from_y == to_y){return 1 ;}
			else if((board[from_x][from_y+1] == white_man || board[from_x][from_y+1] == white_king) && 
					board[from_x][from_y+2] == empty && from_y+2 == to_y && from_x == to_x){return 1 ;}
			else if((board[from_x][from_y-1] == white_man || board[from_x][from_y-1] == white_king) && 
					board[from_x][from_y-2] == empty && from_y-2 == to_y && from_x == to_x){return 1 ;}
			else {
				return 0 ;
			}
		}
		else if (board[from_x][from_y] == white_king ){
			if (from_y == to_y && to_x > from_x){
				cont =0 ;
				for(i = from_x+1 ; i <= to_x ; i++){
					if (board[i][from_y] != empty){cont++;}
					if (board[i][from_y] == white_king || board[i][from_y] == white_man ) {return 0 ;}
				}
				if (cont <= 1){return 1 ;}
			}
			else if (from_y == to_y && to_x < from_x){
				cont =0 ;
				for(i = from_x-1 ; i >= to_x ; i--){
					if (board[i][from_y] != empty){cont++;}
					if (board[i][from_y] == white_king || board[i][from_y] == white_man ) {return 0 ;}
				}
				if (cont <= 1  ){return 1 ;}
			}
			else if (from_x == to_x && to_y > from_y){
				cont =0 ;
				for(i = from_y+1 ; i <= to_y ; i++){
					if (board[from_x][i] != empty){cont++;}
					if (board[from_x][i] == white_king || board[from_x][i] == white_man ) {return 0 ;}
				}
				if (cont <= 1  ){return 1 ;}
			}
			else if (from_x == to_x && to_y < from_y){
				cont =0 ;
				for(i = from_y-1 ; i >= to_y ; i--){
					if (board[from_x][i] != empty){cont++;}
					if (board[from_x][i] == white_king || board[from_x][i] == white_man ) {return 0 ;}
				}
				if (cont <= 1  ){return 1 ;}
			}
			else {
				return 0 ;
			}
		}
			else if (board[from_x][from_y] == black_king ){
				if (from_y == to_y && to_x > from_x){
					cont =0 ;
					for(i = from_x+1 ; i <= to_x ; i++){
						if (board[i][from_y] != empty){cont++;}
						if (board[i][from_y] == black_man || board[i][from_y] == black_king ) {return 0 ;}
					}
					if (cont <= 1){return 1 ;}
				}
				else if (from_y == to_y && to_x < from_x){
					cont =0 ;
					for(i = from_x-1 ; i >= to_x ; i--){
						if (board[i][from_y] != empty){cont++;}
						if (board[i][from_y] == black_man || board[i][from_y] == black_king ) {return 0 ;}
					}
					if (cont <= 1  ){return 1 ;}
				}
				else if (from_x == to_x && to_y > from_y){
					cont =0 ;
					for(i = from_y+1 ; i <= to_y ; i++){
						if (board[from_x][i] != empty){cont++;}
						if (board[from_x][i] == black_king || board[from_x][i] == black_man ) {return 0 ;}
					}
					if (cont <= 1  ){return 1 ;}
				}
				else if (from_x == to_x && to_y < from_y){
					cont =0 ;
					for(i = from_y-1 ; i >= to_y ; i--){
						if (board[from_x][i] != empty){cont++;}
						if (board[from_x][i] == black_king || board[from_x][i] == black_man ) {return 0 ;}
					}
					if (cont <= 1  ){return 1 ;}
				}
				else {
					return 0 ;
				}
		}
	}

	else {
		return 0 ;
	}
}

void change_to_king(piece board[][8]){
	int i , j ;
	for(i=0;i<8;i+=7){
		for(j=0;j<8;j++){
			if (i == 0 && board[i][j] == black_man){
				board[i][j] = black_king ;
			}
			if (i == 7 && board[i][j] == white_man){
				board[i][j] = white_king ;
			}
		}
	}

}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){

	int i ;
	int a ;
	int j ;
	int counter1 , counter2;
	int cap_num  = 0 ;
	int continuee = 0;

	
	
	counter1 = count(board);


	if (check_location(board,from_x,from_y,p)){
		if (check_move_avaibilty(board,from_x,from_y,to_x,to_y)){
			temp_move(board,from_x,from_y,to_x,to_y);
			do{
					
				display_board(board);
				continuee = 0;
				change_to_king(board);
				counter2=count(board);
				if(counter1 - counter2 ==1){
					cap_num++;
					from_x = to_x ;
					from_y = to_y ;
					counter1--;
					
					for(a = to_y + 2 ;  check_move_avaibilty(board,from_x,from_y,to_x,a)==1 ; a++ ){
						
						if(board[to_x][a - 1] != empty && a  < 8 && board[to_x][a] == empty ){
	
							to_y = a  ;
							temp_move(board,from_x,from_y,to_x,to_y);
							continuee = 1 ;
							break;
							
						}
						change_to_king(board);

					}
					for(a = to_x + 2 ;  check_move_avaibilty(board,from_x,from_y,a,to_y)==1 ; a++ ){
						
						if(board[a - 1][to_y] != empty && a < 8 && board[a][to_y] == empty){
							to_x = a ;
							temp_move(board,from_x,from_y,to_x,to_y);
							continuee = 1 ;
							break;
							
						}
					}
					for(a = to_x - 2 ;  check_move_avaibilty(board,from_x,from_y,a,to_y)==1 ; a-- ){
						
						if(board[a + 1][to_y] != empty && a >= 0 && board[a][to_y] == empty){
							
							to_x = a  ;
							temp_move(board,from_x,from_y,to_x,to_y);
							continuee = 1 ;
							break;
							
						}
					}
					
					for(a = to_y - 2 ;  check_move_avaibilty(board,from_x,from_y,to_x,a) ; a-- ){
						
						if(board[to_x][a + 1] != empty && a >= 0 && board[to_x][a] == empty){
							
							to_y = a ;
							temp_move(board,from_x,from_y,to_x,to_y);
							continuee = 1 ;
							break;
							
						}

					}
					change_to_king(board);
				}
				j = check_end_of_game(board);
			}while(continuee == 1);


		}
		else{
			return -2 ;
		}

	}
	else{
		return -1 ;
	}
	return cap_num;

}

int count(piece board[][8]){
	int i , j ;
	int counter =0 ;
	for(i=0 ; i< 8 ; i++){
		for(j=0;j<8;j++){
			if(board[i][j] == white_king || board[i][j] == white_man || board[i][j] == black_king || board[i][j] == black_man ){
				counter++;
			}
			

		}
	}
	return counter;

}

void temp_move(piece board[][8], int from_x, int from_y, int to_x, int to_y){

	int i ;

	board[to_x][to_y] = board[from_x][from_y];
	board[from_x][from_y] = empty;
		if (from_y == to_y){
			if(from_x < to_x){
				for(i=from_x;i<to_x;i++){
					board[i][to_y] = empty ;
				}
			}
			if(from_x > to_x){
				for(i=from_x;i>to_x;i--){
					board[i][to_y] = empty ;
				}
			}
		}
		if (from_x == to_x){
			if(from_y < to_y){
				for(i=from_y;i<to_y;i++){
					board[to_x][i] = empty ;
				}
			}
			if(from_y > to_y){
				for(i=from_y;i>to_y;i--){
					board[to_x][i] = empty ;
				}
			}
		}
}

void sample_game_1(){
	int i ;
	piece board[8][8] = {
		{4,4,4,4,4,4,4,4},
		{4,4,0,0,0,4,4,4},
		{4,0,0,4,4,0,0,1},
		{4,4,4,4,1,0,1,1},
		{4,1,4,1,1,4,4,4},
		{1,4,1,1,4,4,4,1},
		{4,1,1,4,4,4,4,4},
		{4,4,4,4,4,4,4,4}				

	};
	display_board(board);
	i = move(board,2,1,3,1,white);
	i = move(board,4,1,2,1,black);
	i = move(board,2,5,4,5,white);
	i = move(board,4,4,4,6,black);
	i = move(board,1,4,2,4,white);
	i = move(board,3,4,1,4,black);
	i = move(board,1,2,1,3,white);
	i = move(board,0,3,2,3,black);
	i = move(board,2,5,2,4,white);
	i = move(board,2,3,2,5,black);
	i = move(board,2,6,2,5,white);
	i = move(board,4,5,1,5,black);





}
void sample_game_2(){
	piece board[8][8] = {
		{4,4,4,4,4,4,4,4},
		{4,4,0,0,0,0,4,4},
		{4,0,0,0,0,4,0,0},
		{0,0,0,4,4,0,4,0},
		{4,4,1,1,1,0,1,1},
		{1,1,1,1,1,4,1,1},
		{4,4,1,1,1,1,4,4},
		{4,4,4,4,4,4,4,4}
	};
	display_board(board);
	int i = move(board,5,1,4,1,black);
	    i = move(board,3,1,5,1,white);
	    i = move(board,4,3,3,3,black);
	    i = move(board,4,5,4,3,white);
	    i = move(board,3,3,3,1,black);
	    i = move(board,1,2,1,0,white);
	    i = move(board,5,3,4,3,black);
	    i = move(board,5,1,5,3,white);
	    i = move(board,4,3,3,3,black);
	    i = move(board,2,3,4,3,white);
	    i = move(board,5,6,5,5,black);
	    i = move(board,7,5,4,5,white);
	    i = move(board,4,6,4,4,black);

}

