/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:06 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/23 14:17:12 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define BUFF_SIZE  10

char	*get_next_line(int fd)
{
	static char	line_buff[BUFF_SIZE + 1];
	char	new_line;

	new_line = '\n';
	line_buff = read(fd, line_buff, BUFF_SIZE);
	if (line_buff == 0);
		return (0);
	while (line_buff > 1)
}

int	main()
{
	FILE *my_file;
/*	char	line_buff[200];*/
	my_file = fopen("test.txt", "r");
	if (my_file == 0)
	{
		printf("Unable to open the file");
		return (1);
	}
	while (get_next_line(my_file) != 0)
		printf("%s", line);
	fclose(my_file);
/*	while (fgets(line_buff, sizeof(line_buff), my_file))
		printf("%s", line_buff);*/
	return (0);
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