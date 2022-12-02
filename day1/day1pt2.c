#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int 
main(void)
{
	long top_one = 0;
	long top_two = 0;
	long top_three = 0;
	int calories = 0;
	char buffer[1024];
	FILE *file_pointer = fopen("input.txt", "r");

	assert(file_pointer);

	while (1)
	{
		char *gets_pointer = fgets(buffer, sizeof(buffer), file_pointer);

		if (gets_pointer == NULL)
		{
			break;
		}
		
		if (strcmp(buffer, "\n") == 0)
		{
			if (calories > top_one)
			{
				top_two = top_one;
				top_three = top_two;
				top_one = calories;
			} 
			else if (calories > top_two)
			{
				top_three = top_two;
				top_two = calories;
			}
			else if (calories > top_three)
			{
				top_three = calories;
			}

			calories = 0;
		} else {
			int parsed_int = atoi(buffer);
			calories += parsed_int;
		}
	}

	long max_calories = 0;

	max_calories += top_one;
	max_calories += top_two;
	max_calories += top_three;

	printf("MAX CALORIES - %ld", max_calories);

	fclose(file_pointer);
	return 0;
}
