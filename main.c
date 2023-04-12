# include "get_next_line.h"
#include <fcntl.h> 



int	main() //(int ac, char **av)
{
	int	my_file;
	int	errno;
	char	*the_line;
	int	i;

	i = 1;
	errno = 0;
	//ac = 2;
	//(void)av;
	my_file = open("test.txt", O_RDONLY); //42;
	if (my_file == 0)
	{
		printf("Unable to open the file");
		return (-1);
	}
	the_line = get_next_line(my_file);
	while (the_line != 0)
	{
		printf(" ...line %d: %s.................................\n", i, the_line);
		free(the_line);
		i++;
		the_line = get_next_line(my_file);
	}
	//free(the_line);
	errno = close(my_file);
	return (errno);
}


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

/*int		main(int argc, char *argv[])
{
	char	fd[];
	char	*file_name;
	char	*line;
	int	ret;

	i = 0;
	while (i < argc)
	{
		fd[i] = open(argv[i], O_RDONLY);
		if (argc > i)
		{
			file_name = NULL;
			file_name = argv[i];
			while ((ret = get_next_line(fd[i], &line)))
			{
				printf("%s\n", line);
			}
			close(fd[i]);
		}
		i++
	}
	return (0);
}*/
