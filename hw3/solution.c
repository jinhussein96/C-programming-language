#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void menu();
int num_digits(int num);
void countOccurrence();
void triangleOfSequences();
void horseRacingGame();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);


int getInt(int mini, int maxi){
	int choice;
	int flag=0;
	do{
		scanf("%d",&choice);
		if(choice>=mini && choice <= maxi){
			flag =1;
		}
		if(choice<mini || choice > maxi){
			printf("not in range \nenter your choice\n");
		}
	}
	while(flag!=1);
		
	
	return choice;
}
int numberGeneratorBetweenRange(int min, int max){
	int num;
	do{
			
		num=rand()%max+1;
	}while(num<min || num > max);
	
	return num;

}
void menu(){
	int choice=-1;
	int flag =0;
	do{
		printf("------------------------------\n");
		printf("1. Horse Racing Game\n");
		printf("2. Occurrence Counter\n");
		printf("3. Triangle of Sequences\n");
		printf("0. Exit\n");				
		printf("enter your choice :");
		choice=getInt(0,3);

		switch(choice){
				case 1 :
					horseRacingGame();
					break;
				case 2 :
					countOccurrence();
					break;
				case 3 :
					triangleOfSequences();
					break;
				case 0 :
					flag =1;
					break;

			}
		
	}while(flag != 1);
}

void horseRacingGame(){
	int NumberOfHorse,
		HorseNumber;
	int i ;
	int temp;
	int min=21,tie=0;
	int max=0;
	int Horse,pre=0;
	srand(time(NULL));
		NumberOfHorse=numberGeneratorBetweenRange(3,5);
		printf("Number Of Horse: %d \n",NumberOfHorse);
		printf("Horse Number :");
		scanf("%d",&HorseNumber);
		
		for(i=1;i<=NumberOfHorse;i++){
			Horse=numberGeneratorBetweenRange(10,20);
			 if(Horse<min){
				min=Horse;
				temp=i;
			}
			else if(Horse>max)
				max=Horse;

			else if(Horse==pre || Horse==min|| Horse==max){
				tie=1;
			}

			printf("hores %d :",i );
			for(int j=0;j<Horse;j++)
				printf("-");
			printf("\n");
			pre=Horse;

		}
		if(tie>=1)
			printf("no winner \n");
		else if(temp == HorseNumber)
			printf("you win\n");
		else 
			printf("you lose ...Horse %d win\n",temp );
		
}


void triangleOfSequences(){
	int rows;
	int i , j;
	srand(time(0));
	rows=numberGeneratorBetweenRange(2,10);

	for(i=1;i<=rows;i++){
		for(j=1;j<=i;j++){
			printf("%d ",i*j );
			
		}
		
		printf("\n");
	}
}
int num_digits(int num){//calculating the digits of the given number...
	int counter=0;
	int i;
	while(num>=1){
		i=num % 10;
		num /= 10;
		counter++;
	}
	return counter;
}
void countOccurrence(){
	int occurrence=0;
	int BigNumber ,SearchNumber;
	int digits,num;
	printf("Big Number: ");
	scanf("%d",&BigNumber);
	printf("Search Number:");
	scanf("%d",&SearchNumber);
	digits=num_digits(SearchNumber);
	num=pow(10,digits);
	while(BigNumber>0)
	{
		if(SearchNumber==(BigNumber%num)){
			occurrence++;
		}
		BigNumber /= 10;
	}
	printf("occurrence : %d\n",occurrence );


}
int main(){
	menu();
	return 0;
}