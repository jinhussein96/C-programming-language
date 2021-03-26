#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct a{
  int coodinate_x;
  int coodinate_y;
  int Water_Bottle_Size ;
}Botanist;

typedef struct f
{
  Botanist botanist ;
  int width;
  int Height;
  char **Map;
  int Flower_X;
  int Flower_Y;
}Forest;


void init_game (Forest *forest);
void print(Forest forest );
void search(Forest forest,int water,int *finish);
int is_legal(Forest forest , int x , int y);
int is_target(Forest forest);
int is_open(Forest forest , int x , int y);
void print_finished(Forest forest);

void main(void){
  Forest forest ;

  int finish =1 ;
  init_game(&forest);
  print(forest);
  search(forest ,forest.botanist.Water_Bottle_Size,&finish);


}


void init_game (Forest *forest){
    FILE *fp = fopen("init.txt", "r");
    char c ,a;
    int i ,j;
    if(fp == NULL){
      printf("ERROR ....cant open file !!!");
    }
    fscanf(fp,"%d",&forest->botanist.Water_Bottle_Size);
    fscanf(fp,"%d %c %d",&forest->width,&c,&forest->Height);
    fscanf(fp,"%c",&c);
    forest->Map = malloc((forest->width) * sizeof(char *));
    for( i = 0 ; i < forest->width ; i++){
      forest->Map[i] = malloc((forest->Height )* sizeof(char));
    }
    for(i = 0 ; i < forest->width ; i++){
      for(j = 0 ; j < forest->Height ; j++){
          fscanf(fp,"%c",&c);
          if( c != ',' && c != '\n'){
            forest->Map[i][j] = c ;
          }
          else 
            j--;
          if(c == 'B'){
            forest->botanist.coodinate_x = i;
            forest->botanist.coodinate_y=j;
          }
          if(c == 'F'){
            forest->Flower_X = i;
            forest->Flower_Y = j ;
          }
      }
    }
  fclose(fp);
}

void print(Forest forest ){
  int i , j ;
  for (i=0 ; i < forest.width ; i++){

    for(j=0 ; j < forest.Height ; j++){
      if (i == forest.botanist.coodinate_x && j == forest.botanist.coodinate_y){
        printf("B ");
      }
      else if(forest.Map[i][j] == '+')
        printf("  ");
      else {
        printf("%c ",forest.Map[i][j] );
      }
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
}

void search(Forest forest, int water,int *finish){
 
  if (water > 0){
    if (!is_target(forest)){
      if(is_open(forest,forest.botanist.coodinate_x+1,forest.botanist.coodinate_y )&& *finish){
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = '+';
        forest.botanist.coodinate_x++;
        water--;
       
        search(forest,water,finish);
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = 'U';
        forest.botanist.coodinate_x--;
      }

      if(is_open(forest,forest.botanist.coodinate_x-1,forest.botanist.coodinate_y)&& *finish){
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = '+';
        forest.botanist.coodinate_x--;
        water--;
      
       
        search(forest,water,finish);
        
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = 'U';
        forest.botanist.coodinate_x++;
     
      }
  
      if(is_open(forest,forest.botanist.coodinate_x,forest.botanist.coodinate_y+1)&& *finish){
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = '+';
        forest.botanist.coodinate_y++;
        water--;
     
       
        search(forest,water,finish);
        
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = 'U';
        forest.botanist.coodinate_y--;
      
      }
 
      if(is_open(forest,forest.botanist.coodinate_x,forest.botanist.coodinate_y-1)&& *finish){
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = '+';
        forest.botanist.coodinate_y--;
        water--;
      
        
        search(forest,water,finish);
        
        forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = 'U';
        forest.botanist.coodinate_y++;
     
      }
    }
    else{
      printf("searchig......\n");
      print_finished(forest);
       printf("i have found it on (%d,%d)\n\n",forest.botanist.coodinate_x,forest.botanist.coodinate_y );

    }
  }
  else {
    *finish=0;
    forest.Map[forest.botanist.coodinate_x][forest.botanist.coodinate_y] = 'B';
    printf("searching.....\n");
     print(forest);
    printf("help!! im on (%d,%d)\n",forest.botanist.coodinate_x,forest.botanist.coodinate_y );
   

    return ;
  }

}

int is_legal(Forest forest , int x , int y){

    if ((x < forest.width && x >= 0) && (y < forest.Height && y >= 0)){
      return 1;
    }
    return 0;
}

int is_target(Forest forest){
  if((forest.Flower_X == forest.botanist.coodinate_x) &&
     (forest.Flower_Y == forest.botanist.coodinate_y)){
    
   
    return 1 ;
  }
  return 0 ;
}

int is_open(Forest forest , int x , int y){
 // if(!is_target(forest)){
    if (is_legal(forest , x , y )){
      if (forest.Map[x][y] == ' ' || forest.Map[x][y] == 'F'){
        return 1;
      }
    }
 // }
  return 0;
}

void print_finished(Forest forest){
   int i ,j ;
   for (i =0 ; i < forest.width ; i++){
      for(j = 0 ; j < forest.Height; j++){
         if (forest.Map[i][j] == 'U'){
            printf("  ");
         }
         else if (forest.Map[i][j] == 'B'){
            printf("F ");
         }
         else if(forest.Map[i][j] == '+')
          printf("  ");
         else{
            printf("%c ",forest.Map[i][j] );
         }
      }
      printf("\n");
   }
}

