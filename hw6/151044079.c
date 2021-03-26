#include <stdio.h>
#define size 1024
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
void main(){
	 menu();
}
void menu(){
	int choice ;	
	do{
		printf("1. Encrypt\n2. Decrypt\n0. Exit\nChoice: ");
		scanf("%d",&choice);
		switch (choice) {
			case 1 : 	encrypt_open_msg();
				break;
			case 2 :	decrypt_secret_msg();
				break;
		}
	}while(choice != 0);
}
void encrypt_open_msg(){
	FILE *p1 = fopen("open_msg.txt","r");
	FILE *p2 = fopen("secret_msg.txt","w");
	char line[size];
	char c ;
	int i =0 , j , key;
	int line_size;
	printf("key == "); 
	scanf("%d" , &key);
	while(!feof(p1)){
		i =0;
		do{	fscanf(p1,"%c",&c);
			line[i] = c;
			i++;
		}while(c != '\n' && !feof(p1) );
		line[i-1] = '\0';
		line_size = find_size_of_line(line);
		reverse_line(line,line_size);
		for(int s = 0 ; s < line_size ; s++){
				if(line[s] == ' ')
   					line[s] = '_';
   				if(line[s] == '.')
   					line[s] = '*';
		}
		for(i=1;i<line_size;i++){
			if(line[i] != '_'){
				for(j = 1 ; j <= key ; j++){
					if(line[i] == 'a'){
						line[i] = 'z';	}
					else 	line[i] = line[i] - 1;}
				}
		}
		printf("%s\n",line );
		fprintf(p2,"%s\n",line );	
	}
	fclose(p1);
	fclose(p2);
}
void decrypt_secret_msg(){
		FILE *p1 = fopen("secret_msg.txt","r");
		FILE *p2 = fopen("open_msg.txt","w");
	char line[size] , c ; int i =0 , j , key , line_size;
	printf("key == "); 
	scanf("%d" , &key);
	while(!feof(p1)){
		i =0;
		do{	fscanf(p1,"%c",&c);
			line[i] = c;
			i++;
		}while(c != '\n' && !feof(p1) );
		line[i-1] = '\0';
		line_size = find_size_of_line(line);
		reverse_line(line,line_size);
		for(int s = 0 ; s < line_size ; s++){
				if(line[s] == '_'){
   					line[s] = ' ';
   				}
   				else if(line[s] == '*'){
   					line[s] = '.';}
		}
		for(i=0;i<line_size-1;i++){
			if(line[i] != ' '){
				for(j = 1 ; j <= key ; j++){
					if(line[i] == 'z'){
						line[i] = 'a';
					}
					else 
						line[i] = line[i] + 1;
				}
			}
		}
		printf("%s\n",line );
		fprintf(p2,"%s\n",line );	
	}
	fclose(p1);
	fclose(p2);
}
int find_size_of_line(char line[]){
	int i ;
	for(i = 0 ; line[i]; i++);
		return i;
}
void reverse_line(char line[], int line_lenght){
	char temp[line_lenght];	int j =line_lenght-1, i=0 ;
  for(i=0;i < line_lenght;i++){
  	temp[i] = line[j];
  	j--;
  }
   temp[i] = '\0';
   for(i=0;i<line_lenght;i++){
   	line[i] = temp[i];
   }
}
