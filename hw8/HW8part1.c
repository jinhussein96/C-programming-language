#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define size 10
typedef enum type{P = 'P',B = 'B' , T = 'T' , M = 'M' , S = 'S' }block_type;
typedef struct block
{
    char text[10];
    int  data; 
    block_type type ;
    int pos_x,
        pos_y,
        jump_x,
        jump_y;
}block;

void init_board( block board[size][size]){
    int i ,j,count = 1 ;
    int temp;

    for(i = 0 ; i < size ; i++){
        if(i % 2 != 0){
            for(j = size-1 ; j>=0;j--){
                board[i][j].data=count;
                count++;
            }
        }
        else {
            for(j =0 ; j < size ; j++){
                board[i][j].data=count;
                count++;
            }
        }

    }
    for(i = 0 ; i<size/2;i++){
        for(j =0 ; j <size;j++){
            temp =  board[i][j].data;
            board[i][j].data = board[size-i-1][size-j-1].data;
            board[size-1-i][size-1-j].data = temp;


        }
    }
    for(i = 0 ; i<size;i++){
        for(j =0 ; j <size;j++){
            board[i][j].pos_x = i;
            board[i][j].pos_y = j; 
            board[i][j].jump_x = 10;
            board[i][j].jump_y = 10;
        }
    }
    for(i = 0 ; i<size;i++){
        for(j =0 ; j <size;j++){
            board[i][j].type= 'x';
            strcpy(board[i][j].text,"\0");
            if (board[i][j].data == 1 ) {
                strcpy(board[i][j].text,"1(start)");
            }
            else if(board[i][j].data == 6){
                strcpy(board[i][j].text,"s{1}");
                board[i][j].jump_x = 9;
                board[i][j].jump_y = 9;
                board[i][j].type = S ;

            }
            else if(board[i][j].data == 7){
                strcpy(board[i][j].text,"M{11}");
                board[i][j].jump_x = 8;
                board[i][j].jump_y = 0;
                board[i][j].type = M ;          
            }
            else if(board[i][j].data == 17){
                strcpy(board[i][j].text,"M{28}");
                board[i][j].jump_x = 7;
                board[i][j].jump_y = 2;
                board[i][j].type = M ;
            }
            else if(board[i][j].data == 25){
                strcpy(board[i][j].text,"s{12}");
                board[i][j].jump_x = 8;
                board[i][j].jump_y = 1;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 32){
                strcpy(board[i][j].text,"M{52}");
                board[i][j].jump_x = 4;
                board[i][j].jump_y = 1;
                board[i][j].type = M ;
            }
            else if(board[i][j].data == 45){
                strcpy(board[i][j].text,"s{22}");
                board[i][j].jump_x = 7;
                board[i][j].jump_y = 8;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 57){
                strcpy(board[i][j].text,"M{77}");
                board[i][j].jump_x = 2;
                board[i][j].jump_y = 6;
                board[i][j].type = M ; 
            }
            else if(board[i][j].data == 60){
                strcpy(board[i][j].text,"s{44}");
                board[i][j].jump_x = 5;
                board[i][j].jump_y = 6;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 63){
                strcpy(board[i][j].text,"s{52}");
                board[i][j].jump_x = 4;
                board[i][j].jump_y = 1;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 6){
                strcpy(board[i][j].text,"s{1}");
                board[i][j].jump_x = 9;
                board[i][j].jump_y = 9;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 69){
                strcpy(board[i][j].text,"M{77}");
                board[i][j].jump_x = 2;
                board[i][j].jump_y = 6;
                board[i][j].type = M ;
            }
            else if(board[i][j].data == 73){
                strcpy(board[i][j].text,"s{68}");
                board[i][j].jump_x = 3;
                board[i][j].jump_y = 2;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 76){
                strcpy(board[i][j].text,"M{83}");
                board[i][j].jump_x = 1;
                board[i][j].jump_y = 7;
                board[i][j].type = M ;
            }
            else if(board[i][j].data == 89){
                strcpy(board[i][j].text,"M{49}");
                board[i][j].jump_x = 5;
                board[i][j].jump_y = 1;
                board[i][j].type = M ;
            }
            else if(board[i][j].data == 98){
                strcpy(board[i][j].text,"s{72}");
                board[i][j].jump_x = 2;
                board[i][j].jump_y = 1;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 99){
                strcpy(board[i][j].text,"s{56}");
                board[i][j].jump_x = 4;
                board[i][j].jump_y = 5;
                board[i][j].type = S ;
            }
            else if(board[i][j].data == 100){
                strcpy(board[i][j].text,"100(finish)");
            }
            else if(board[i][j].data == 13 || board[i][j].data == 48 || board[i][j].data == 85){
                board[i][j].type = P;

            }
            else if(board[i][j].data == 29 || board[i][j].data == 36 || board[i][j].data == 50
                    || board[i][j].data == 66 || board[i][j].data == 82) {
                board[i][j].type = B;

            } 
            else if(board[i][j].data == 40 || board[i][j].data ==54 || board[i][j].data == 79 || board[i][j].data == 93){
                board[i][j].type = T ;
            }


        }
    }       


}
void print_board(block board[][size]){
    int i , j ;
    for(i =0 ; i < size ; i++){
        for( j=0 ; j < size ; j++){
            if( strcmp(board[i][j].text , "\0") != 0){
                printf("%s  ",board[i][j].text );
            }
            else if(board[i][j].type != 'x'){
                printf("%c   ", board[i][j].type);
            }
            else {
                printf("%d   ",board[i][j].data );
            }
        }
        printf("\n");
        printf("\n");
    }
}    
void search(block board[][size] , int dice , int cur_x , int cur_y , int * b , int *c ){
 int i , j ;
    dice += board[cur_x][cur_y].data;
    for(i =0 ; i < size ; i++){
        for( j =0 ; j < size ; j++){
            if(board[i][j].data == dice){
                *b = i ;
                *c = j ;
            }
        }
    }
} 

int play(block board[][size] , int cur_x , int cur_y , int *count_move , int temp ){
  int dice = rand()%7;
  int to_x;
  int to_y;
  
    if(board[cur_x][cur_y].data != 100 ){
        if (dice == 0){
              play(board , cur_x , cur_y,count_move,temp);
        }

        else if(dice+board[cur_x][cur_y].data <= 100){

            search(board , dice , cur_x , cur_y , &to_x , &to_y);
            if(board[to_x][to_y].type == P){
                play(board,cur_x,cur_y,count_move,temp+1);
                printf("location : %d    dice: %d\n",board[cur_x][cur_y].data , dice );
                

            }
            else if(board[to_x][to_y].type == B){
                search(board,5,to_x,to_y,&to_x,&to_y);
                play(board,to_x,to_y,count_move,temp+1);
                printf("location : %d    dice: %d\n",board[cur_x][cur_y].data , dice );
                
            }
            else if(board[to_x][to_y].type == T){
                search(board,-5,to_x,to_y,&to_x,&to_y);
                temp++;
                play(board,to_x,to_y,count_move,temp);
                printf("location : %d    dice : %d\n",board[cur_x][cur_y].data , dice );
                

            }
            else if(board[to_x][to_y].type == M){
                temp++;
                play(board,board[to_x][to_y].jump_x,board[to_x][to_y].jump_y,count_move,temp);
                printf("location : %d    dice : %d\n",board[cur_x][cur_y].data , dice );
                
            }
            else if(board[to_x][to_y].type == S){
                temp++;
                play(board,board[to_x][to_y].jump_x,board[to_x][to_y].jump_y,count_move,temp);
                printf("location : %d    dice : %d\n",board[cur_x][cur_y].data , dice );
                
            }
            else{ 
                temp++;
                play(board , to_x , to_y,count_move,temp);
                printf( "location : %d    dice : %d\n",board[cur_x][cur_y].data , dice );     
            }


        }
        else {
             play(board,cur_x,cur_y,count_move,temp+1);
             printf("location : %d    dice : %d\n",board[cur_x][cur_y].data , dice );     
        }
    }
    else {
        printf("location : %d  \n",board[cur_x][cur_y].data );
        *count_move = temp;
    }   
}
void two_sep_game(block board[][size],int  *count_move_1 , int *count_move_2){
    int a , b ;
    printf("\nfirst player's move ::::: \n");
    play(board,9,9,count_move_1,a);
     printf("\nsecond player's move ::::: \n");
     play(board,9,9,count_move_2,b);

}


void main(){
     block board[size][size];
     int a =0, b=0 ;
     int count_move;
     int  count_move_1 ; int count_move_2;

     srand(time(NULL));
     init_board(board);

    print_board(board);
    play(board,9,9,&count_move,b);
    
    printf("count_move === %d\n",count_move);
    printf("-------------------------\n");
    printf("---------------TWO SEPARATE GAME---------------\n");
    two_sep_game(board,&count_move_1,&count_move_2);
    if(count_move_1>count_move_2)
        printf("the first player wins\n");

    else 
        printf("the second player wins\n");

    

}



