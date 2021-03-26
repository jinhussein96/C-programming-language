#include <stdio.h>
#include <string.h>
#define max_num_of_rows 100
#define max_num_of_columns 250



/*reads the input file into a 2D array */
void read(char *file , char arr[max_num_of_rows][max_num_of_columns],int *max_rows)
{
 
	FILE *MyFile=fopen(file,"r");
	int i=0;
	while(!feof(MyFile))
	{
		fgets(arr[i],max_num_of_columns,MyFile);
		i++;
	}
*max_rows=i-1;	
fclose(MyFile);
}

int search(char arr[max_num_of_rows][max_num_of_columns],char str[])
{

	int i=0,x,j=0,a=0,*firstOcc , found =0;
	int counter;
	read("input.txt",arr,&x);
	for(i=0;i<x;i++)
	{
		for(j=0;arr[i][j] != '\0';j++)
		{
			
			 
			if(arr[i][j]==str[0])
			{ 
				counter=1;
				while(counter<strlen(str))
				{

					if(arr[i][j+counter] == str[counter])
					{
						counter++;
						found=1;
					}
					else 
					{
						found=0;
						counter=strlen(str);
						
					}


				}
				if(found==1)
					{
						printf(" %s (%d,%d) Horizontal",str,i+1,j+1);
					}

			}

			
		}
		
	}
	for(i=0;i<x;i++)
	{
			
			for(j=0;arr[i][j] != '\0';j++)
		{
			
			if(arr[i][j]==str[0])
			{ 
				counter=1;
				while(counter<strlen(str))
				{

					if(arr[i+counter][j] == str[counter])
					{
						counter++;
						found=1;
					}
					else 
					{
						found=0;
						counter=strlen(str);
						
					}


				}
				if(found==1)
					{
						printf(" %s (%d,%d)  Vertical ",str,i+1,j+1);
					}

			}
		}
	}
}	



int main()
{

char arr1[max_num_of_rows][max_num_of_columns];
char string[]={"Patara"};
search(arr1,string);
	
 


	return 0;
}

