#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customers
{
	char name[25];
	char surname[25];
	int age;
	char gender[10];
	struct customers *next;
}Customer;

typedef struct rooms
{
	int room_number;
	int capacity;
	int flr;
	Customer *customer;
	struct rooms *next;
	
}Room;



Room *read(char *file1,Room *room);
Room *read_customer(char *file2,Room **room);
void add_room_to_end( Room **room   );
void add_room_after_room_number (Room **room  , int room_number_to_insert_after );
void  add_customer_to_end(Room  *room , char name[], char surname[] , int age , char gender[] );
void link_customers_to_room(Room  *room ,int room_number, char name[], char surname[] , int age , char gender[] );
void remove_room(Room **room);
void show_vacancy(Room **room);
void get_by_floor(Room **room);
void print_list (Room *room);

int main(void){
	Room  *head = read("rooms.txt",head);
	head = read_customer("customers.txt",&head);
	
	//get_by_floor(&head);
	//show_vacancy(&head);
	//remove_room(&head);
	while(head->next != NULL){
		print_list(head);
		head = head->next;
	}
	return 0;
}

Room *read(char *file1,Room *room){
	char c ;
	FILE *f = fopen(file1,"r");
	room = malloc(sizeof(Room));
	Room *cur = room ; 
	while(fscanf(f,"%d %c %d %c %d",&cur->room_number,&c,&cur->capacity,&c,&cur->flr)==5){
		cur->next= malloc(sizeof(Room));
		cur = cur->next;
	}
	fclose(f);
	return room ;
}

Room *read_customer(char *file2,Room **room ){
//	room = read("rooms.txt",room);
	Room *head = *room;
	Room *cur = *room;


	FILE *fp = fopen(file2,"r");

	char c;
	int room_number;
	int i = 0;
	char name[20] , surname[20] , gender[10] ;
	int age ;

	while(fscanf(fp,"%d %c " ,&room_number,&c) == 2){
		cur = head ;
		i = 0;
		//strcpy(surname,NULL);
		while(cur->next != NULL){
			
			if(cur->room_number == room_number){
				fscanf(fp,"%s",name);
				fscanf(fp,"%c%c",&c,&c);
				while(c != ','){
					surname[i++] = c ;
					fscanf(fp,"%c",&c);
				}
				surname[i]='\0';
				//printf("%s\n",surname );
				
				fscanf(fp,"%d %c %s",&age,&c,gender);
				link_customers_to_room(cur,room_number,name,surname,age,gender);
					
			}
			cur= cur->next;
		
	}
}


	fclose(fp);
	return head;

}
void add_room_to_end( Room **room ){
	Room *head = malloc(sizeof(Room));
	head = *room;
	Room *last = malloc(sizeof(Room));
	printf("enter new room's number -> ");
	scanf("%d", &last->room_number);	
	printf("enter new room's capacity -> ");
	scanf("%d",&last->capacity );
	printf("enter new room's floor -> ");
	scanf("%d",&last->flr);
	last->next = NULL;

	while(head->next != NULL){
		head = head->next;
	}

	head->next = last;	
}
void add_room_after_room_number (Room **room , int room_number_to_insert_after){
	Room *temp = malloc(sizeof(Room));
	Room *curr = malloc(sizeof(Room));
	curr = *room;
	int found = 0;

	while(curr->next != NULL){
		if(curr->room_number == room_number_to_insert_after){
			temp = curr->next;

			printf("enter new room's number -> ");
			scanf("%d", &curr->next->room_number );	
			printf("enter new room's capacity -> ");
			scanf("%d",&curr->next->capacity );
			printf("enter new room's floor -> ");
			scanf("%d",&curr->next->flr);
			curr->next->customer = NULL;
			curr->next = temp;
			found = 1;
			break;
			
		}


		curr = curr->next;
	}
	if(!found){
		printf("didnt find room\n");
	}
	



}
void  add_customer_to_end(Room  *room , char name[], char surname[] , int age , char gender[] ){

	
	Room *temp = malloc(sizeof(Room));
	temp = room;
	
		if(temp->customer == NULL){
			temp->customer = malloc(sizeof(Customer));
			strcpy(temp->customer->name , name);
			strcpy(temp->customer->surname,surname);
			strcpy(temp->customer->gender,gender);
			temp->customer->age = age;
			temp->customer->next = NULL;
		}
		else {
			while(temp->customer->next != NULL){
					temp->customer = temp->customer->next;		
			}
			temp->customer->next = malloc(sizeof(Customer));
			strcpy(temp->customer->next->name , name);
			strcpy(temp->customer->next->surname,surname);
			strcpy(temp->customer->next->gender,gender);
			temp->customer->next->age = age;
			temp->customer->next->next = NULL;
		}
			


}

void remove_room(Room **room){
	Room *temp = malloc(sizeof(Room));
	Room *temp1 = malloc(sizeof(Room));
	temp = *room;

	int found = 0 ;
	int room_number_to_be_removed;

	printf("enter room number you want to remove ->");
	scanf("%d",&room_number_to_be_removed);

	if(temp != NULL && temp->room_number == room_number_to_be_removed){
		*room = temp->next;
		free(temp);
		return;
	}
	else {

		while(temp->next != NULL){
			if(temp->next->room_number == room_number_to_be_removed){
				temp1 = temp->next->next;
				free(temp->next);
				temp->next = temp1;
				found = 1;
				return;

			}
			temp = temp->next;

		}
		if(!found){
			printf("cann't find room\n");
		}
	}
}

void show_vacancy(Room **room){
	Room *temp = *room;
	while(temp->next != NULL){
		if(temp->customer == NULL){
			print_list(temp);
		}
		temp = temp->next;
	}
}
void get_by_floor(Room **room){
	Room *temp = *room;

	int flr;

	printf("enter floor number" );
	scanf("%d",&flr);
	while(temp->next != NULL){
		if(temp->flr == flr){
			print_list(temp);
		}
		temp = temp->next;
	}


}
void print_list(Room *room){
	if(room != NULL){
		printf("Room %d (Floor %d - capacity %dx )\n",room->room_number,room->flr ,room->capacity);
		if(room->customer != NULL && room->next->customer ==NULL){
			printf("-> %s %s (%d - %s) \n",room->customer->name,room->customer->surname,room->customer->age,room->customer->gender);
		}
		else if(room->customer == NULL){
			printf("-> Empty\n");
		}
		else {
			while(room->customer->next != NULL){
				printf("-> %s %s (%d - %s) \n",room->customer->name,room->customer->surname,room->customer->age,room->customer->gender);
				room->customer = room->customer->next; 
			}
		}
	}

}
void link_customers_to_room(Room  *room, int room_number, char name[], char surname[] , int age , char gender[] ){
	Room *temp = room;


	while(temp->next != NULL){

		if(temp->room_number == room_number ){
			
			add_customer_to_end(temp,name,surname,age,gender);
			
		}
		temp = temp->next;
	}




}
