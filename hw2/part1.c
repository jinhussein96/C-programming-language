
#include <stdio.h>
#include <stdlib.h>
char letter_grade(int student_grade);
void letter_grade_statistics(int A,int B,int C,int D,int F);


char letter_grade(int student_grade){//calculate later grade...
	
			if(student_grade >= 90 && student_grade <=100){
				return 'A';
			}
			else if(student_grade >= 80 && student_grade <=89){
				return 'B';
			}
			else if(student_grade >= 70 && student_grade <=79){	
				return 'C';
			}
			else if(student_grade >= 60 && student_grade <=69){
				return 'D';
			}
			else if(student_grade >= 0 && student_grade <=59){
				return 'F';
			}

}
//printing letter grade statistics...
void letter_grade_statistics(int A,int B,int C,int D,int F){
	printf("%d students got letter grade 'A'\n",A);
	printf("%d students got letter grade 'B'\n",B );
	printf("%d students got letter grade 'C'\n",C );
	printf("%d students got letter grade 'D'\n",D );
	printf("%d students got letter grade 'F'\n",F );
				

}


int main()
{
	int student_count,student_grade,i=0;
	int min_grade=101;
	int max_grade=0;
	int min_grade_index=0;
	int max_grade_index=0;
	double sum =0 ; double avg;
	int selection;
	char letter1;
	char letter2;
	srand(40);
	int A_grade_count=0,B_grade_count=0,C_grade_count=0,D_grade_count=0,F_grade_count=0;
	int flag=0;
	printf("Enter student count:");
	scanf("%d",&student_count);

		//cheking students number...
		while(student_count<3 || student_count > 50){
			printf("not in range\n");
			printf("Enter student count:");
			scanf("%d",&student_count);
		}
	
		while(i<student_count){
			student_grade=rand()%101;
			printf("%d ",student_grade );
			if (i%10 == 0 && i != 0)
			{
				printf("\n");
			}
			if(student_grade < min_grade){
				//finding the least grade.. 
				min_grade = student_grade;
				min_grade_index=i+1;
			}
			if(student_grade > max_grade){
				//finding the greatest grade... 
				max_grade = student_grade;
				max_grade_index = i+1;
			}
			if(student_grade >= 90 && student_grade <=100){
				A_grade_count++;
			}
			else if(student_grade >= 80 && student_grade <=89){
				B_grade_count++;
			}
			else if(student_grade >= 70 && student_grade <=79){	
				C_grade_count++;
			}
			else if(student_grade >= 60 && student_grade <=69){
				D_grade_count++;
			}
			else if(student_grade >= 0 && student_grade <=59){
				F_grade_count++;
			}
			i++;
			sum += student_grade;
		}
		


	while(flag!=-1){
		printf("\n------------------------------------------------------\n");
	printf("\nstudent score calculator menu for %d student \n",student_count );
	printf("1) most successful student \n");
	printf("2) most unsuccessful student \n");
	printf("3) latter grade statistics \n"); 
	printf("4) calculate average \n"); 
	printf("5) show all data \n");
	printf("                    make selection : ");
	scanf("%d",&selection);
	
	if((selection >0 && selection < 6) || selection==-1 ){	
		switch(selection){
			case 1 :
				letter1=letter_grade(max_grade);
				printf("most successfully student: \nindex %d :\nscore %d : \nletter grade %c \n",
					max_grade_index,max_grade,letter1);
				
				break;
			case 2 :
				letter2=letter_grade(min_grade);
				printf("most unsuccessfully student : \nindex %d : \nscore %d : \nlatter grade %c \n",
					min_grade_index,min_grade,letter2);
				break;
			case 3 : 
				letter_grade_statistics(A_grade_count,B_grade_count,C_grade_count,D_grade_count,
					F_grade_count);				
				break;
			case 4:
				avg=sum/student_count;
				printf("the average score of %d students is %.2lf \n",student_count,avg );
				break;
			case 5:
				letter1=letter_grade(max_grade);
				printf("most successfully student: \nindex %d :\nscore %d : \nletter grade %c \n",
					max_grade_index,max_grade,letter1);
				letter2=letter_grade(min_grade);
				printf("most unsuccessfully student : \nindex %d : \nscore %d : \nlatter grade %c \n",
					min_grade_index,min_grade,letter2);
				letter_grade_statistics(A_grade_count,B_grade_count,C_grade_count,D_grade_count,
					F_grade_count);	
				avg=sum/student_count;
				printf("the average score of %d students is %.2lf \n",student_count,avg );
				break;
			case -1:
				flag = -1;
				break;

		}
	}
	else 
		printf("false selection !!!\n");

		
	}

	return 0;
}