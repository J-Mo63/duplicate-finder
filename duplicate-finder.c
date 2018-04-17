#include <stdio.h>
#include <string.h>

#define STR_LEN 16

void read_input(char *str);

int main(void)
{
	char str[STR_LEN];
	
	printf("Enter a word: ");
	
	scanf("%s", str);
	
	read_input(str);
	
	return 0;
}

void read_input(char *str)
{
	int i;
	char prev[STR_LEN];
	int hadDuplicates = 0;

	for(i = 0; i < STR_LEN; i++)
	{
		int j;
		int count = 0;
		char currentlyChecked = str[i];

		for(j = 0; j < STR_LEN; j++)
		{	
			if(str[j] == currentlyChecked)
			{	
			count++;
			}	
		}

		int previouslyChecked = 0;

		int k;
		for(k = 0; k < STR_LEN; k++)
		{	
			if(prev[k] == str[i])
			{	
			previouslyChecked = 1;
			}	
		}

		prev[i] = str[i];

		if(count > 1 && previouslyChecked == 0)		
		{		
			printf("Duplicate letter: %c, Occurences: %d\n", currentlyChecked, count);	
			hadDuplicates = 1;			
		}	
	}

	if (hadDuplicates == 0)
	{
		printf("No duplicates found\n");
	}
}