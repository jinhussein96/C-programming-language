#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);
int charOperationToResult(char op, int this, int other);
int isArrayEmpty(char* arr);
void fillArrayWithSpaces(char* arr, size_t size);

int main(){
	int arr[] = {25, 12, 6, 10, 32, 8};
	int arrSize = 6;
	char* operations = (char*)malloc(sizeof(char)*(arrSize-1));
	int expected_result = 44;
	operations = find_operations(arr, expected_result, operations, 6, 0,arr[0]);
	
	printf("%s \n",operations ); 
	free(operations);
	return 0;
}



char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){
	char operands[3] = {'+', '-', '*'};
	if(cursor == arr_len - 1){
		if(current == expected_val)
			return operations;
		else
			fillArrayWithSpaces(operations, arr_len-1);
		/* The case that expected_val was not obtained */
		return operations;
	}

	int next;
	for (int i = 0; i < 3; ++i)
	{
		char* temp = (char*)malloc(sizeof(char) * arr_len);
		next = charOperationToResult(operands[i], current, arr[cursor+1]);
		char* result = find_operations(arr, expected_val, temp, arr_len, cursor+1, next);
		if(!isArrayEmpty(temp))
		{
			memcpy(operations, temp, arr_len-1);
			//printArrayContent(operations, arr_len-1);
			operations[cursor] = operands[i];
			free(temp);
			return operations;
		}
		else{
			fillArrayWithSpaces(operations, arr_len-1);
			free(temp);
		}
	}
	/* The case that all result arrays was empty */
	return operations;
}

int charOperationToResult(char op, int this, int other){
	if(op == '*')
		return this*other;
	else if(op == '+')
		return this + other;
	else if(op == '-')
		return this - other;
}

int isArrayEmpty(char* arr){
	/* If the first character is space, then whole array is empty
	so we don't need to check all the array */
	if(arr[0] == ' ')
		return 1;
	else
		return 0;
}

void fillArrayWithSpaces(char* arr, size_t size){
	for (int i = 0; i < size; ++i)
	{
		arr[i] = ' ';
	}
}