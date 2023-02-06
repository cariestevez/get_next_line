# include "get_next_line.h"
#include <fcntl.h> 

int	main()
{
	int	my_file;
	int	errno;
/*	char    line_buff[200];*/

	errno = 0;
	my_file = open("test.txt", O_RDONLY);
	if (my_file == 0)
	{
		printf("Unable to open the file");
		return (-1);
	}
	while (get_next_line(my_file) != 0)
		printf("%s", get_next_line(my_file));
//  free()??
	errno = close(my_file);
/*	while (fgets(line_buff, sizeof(line_buff), my_file))
		printf("%s", line_buff);*/
	return (errno);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
//BUFFER_SIZE=9999
//BUFFER_SIZE=1
////BUFFER_SIZE=10000000
/*We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You can choose the
default value of your choice.*/
/*We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to????*/


/*#define MAX_LINE_LENGTH 80

int main(int argc, char **argv)
{
	char *path;
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_count = 0;
	
	if (argc < 1)
		return EXIT_FAILURE;
	path = argv[1];
	
	FILE *file = fopen(path, "r");
	
	if (!file)
	{
		perror(path);
		return EXIT_FAILURE;
	}
	
	while (fgets(line, MAX_LINE_LENGTH, file))
	{

		printf("line[%06d]: %s", ++line_count, line);
		
		if (line[strlen(line) - 1] != '\n')
			printf("\n");
	}
	

	if (fclose(file))
	{
		return EXIT_FAILURE;
		perror(path);
	}
}*/