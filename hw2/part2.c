#include <stdio.h>
int num_digits(int num);
int count(int num ,int num1);



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
int count(int num ,int num1){
	num = num /num1;
	return num%10;
}
int main(){
	int num;
	int digits;
	int a1,a2,a3,a4,a5;
	printf("enter the number\n");
	scanf("%d",&num);
	digits=num_digits(num);
	if(num > 23 && num<98760){
		switch(digits){
			case 2:
				a1=count(num,10);
				a2=count(num,1);
				printf("the second digit is %d\n",a1 );
				printf("the first digit is %d\n",a2 );
				break;
			case 3:
				a1=count(num,100);
				a2=count(num,10);
				a3= count(num,1);
				printf("the third digit is %d\n",a1 );
				printf("the second digit is %d\n",a2 );
				printf("the first digit is %d\n",a3 );
				break;
			case 4:
				a1=count(num,1000);
				a2=count(num,100);
				a3=count(num,10);
				a4=count(num,1);
				printf("the fourth digit is %d\n",a1 );
				printf("the third digit is %d\n",a2 );
				printf("the second digit is %d\n",a3 );
				printf("the first digit is %d\n",a4 );
				break;
			case 5 :
				a1=count(num,10000);
				a2=count(num,1000);
				a3=count(num,100);
				a4=count(num,10);
				a5=count(num,1);
				printf("the fifth digit is %d\n",a1 );
				printf("the fourth digit is %d\n",a2 );
				printf("the third digit is %d\n",a3 );
				printf("the second digit is %d\n",a4 );
				printf("the first digit is %d\n",a5 );
				break;


		
		}

	}
	else 
		printf("the number must be between 23 and 98760\n");
	return 0;
}