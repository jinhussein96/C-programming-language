#include <stdio.h>
#include <string.h>
#define size 728
void open_file(char * file,char array[size][2],double count_array[size]);
void all_bi_gram(char arr[size][2]);
double calculate(char *file1,char *file2);

double calculate(char *file1,char *file2)
{
	int i , j ;
	double a=0,dissimilarity=0;
	char array1[size][2];
	char array2[size][2];
	double counter_array1[size];
	double counter_array2[size];
	for( i=0;i<size;i++)
	{
		counter_array1[i]=0;
		counter_array2[i]=0;
	}
	open_file(file1,array1,counter_array1);
	open_file(file2,array2,counter_array2);
	for(j=0;j<size;j++)
	{
		a = counter_array1[j]-counter_array2[j];

		if(a<0)
		{
			a *= -1;
		}
		dissimilarity += a;

	}
	printf("%lf\n",dissimilarity);
	return dissimilarity;

}
void all_bi_gram(char arr[size][2])
{
	char ch='a',ch1='a';
	int i =0;
	int j=0,k=0;
	
		for( j=0;j<26;j++)
		{
			arr[j][0]=' ';
			arr[j][1]=ch;
			arr[j][2]='\0';
			ch++;

		}
		ch = 'a';
		for( j;j<52;j++)
		{
			arr[j][0]=ch;
			arr[j][1]=' ';
			arr[j][2]='\0';
			ch++;
				
		}
		ch = 'a';
		for(j;j<size;j++)
		{
			for(k=0;k<26;k++)
			{
				arr[j][0]=ch1;
				arr[j][1]=ch+k;
				arr[j][2]='\0';
				j++;
			}
			ch1++;
			ch = 'a';
			j--;

		}

}
void open_file(char * file,char array[size][2],double count_array[size])
{
	char a='a', temparr[2];
	int counter =0,i=0,j=0;
	
	for (int i = 0; i < size; ++i)
	{
		count_array[i]=0;
	}
	temparr[2]='\0';
	all_bi_gram(array);
	FILE * myfile =fopen(file,"r");
	a = fgetc(myfile);
	temparr[0]=a;
	while((a = fgetc(myfile)) != EOF )
	{
		
		temparr[1]=a;
		if(temparr[1] == '\n')
		{
			temparr[1]=' ';
			
		}
		
		if(temparr[0] != ' ' || temparr[1] != ' ')
			{
				counter++;
				for(j=0;j<size;j++){
					if (strncmp(temparr,array[j],2) == 0){
						count_array[j]++;
						
					}
				}
			}
	
		temparr[0]=temparr[1];
		
		
	}
	fclose(myfile);
	for(i=0;i<size;i++)
		{
			if (count_array[i]!=0)
				{
					count_array[i] = count_array[i]/counter;
					
				}
		}


	
}

int main()
{
	
 calculate("language_1.txt","language_x.txt");
 calculate("language_2.txt","language_x.txt");
 calculate("language_3.txt","language_x.txt");
 calculate("language_4.txt","language_x.txt");
 calculate("language_5.txt","language_x.txt");

	return 0;
}