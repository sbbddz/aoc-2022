#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int 
main(void)
{
	long max_calories = 0;
	int calories;
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
			if (calories > max_calories)
			{
				max_calories = calories;
			}
			calories = 0;
		} else {
			int parsed_int = atoi(buffer);
			calories += parsed_int;
		}
	}

	printf("MAX CALORIES - %ld", max_calories);

	fclose(file_pointer);
	return 0;
}
