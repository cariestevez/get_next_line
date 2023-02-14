/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:06 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/09 23:48:32 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str_buff;
	static char *str_stash;
	ssize_t		read_ret;
	char		*is_new_line;
	char		*line;

	if (fd < 0 || BUFF_SIZE < 1)
	{
		if (str_stash != 0)
			free(str_stash);
		return (0);
	}
	str_buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	is_new_line = 0;
	printf("before reading\n");
	while (is_new_line == 0)
	{
		read_ret = read(fd, str_buff, BUFF_SIZE);
		printf("--------> Read return is: %ld\n", read_ret);
		printf("Buffer after reading is: %s\n", str_buff);
		if (read_ret == -1)
		{
			if (str_stash != 0)
				free(str_stash);
			if (str_buff != 0)
				free(str_buff);
			return (0);
		}
		if (read_ret == 0)//EOF
		{
			printf("Stash at EOF: %s\n", str_stash);
			line = complete_line(&str_stash, is_new_line);
			if (is_new_line != 0)
				free(is_new_line);
			free(str_buff);
			free(str_stash);
			return (line);
		}
		if (read_ret > 0)
		{
			str_buff[read_ret] = '\0';
			printf("Null terminated buffer: %s\n", str_buff);
			is_new_line = cpy_srch_buff(str_buff, &str_stash);
			printf("is new line: %s\n", is_new_line);
		}
	}
	line = complete_line(&str_stash, is_new_line);
	str_stash = *(&is_new_line) + 1;
	printf("Stash before return: %s\n", str_stash);
	free(str_buff);
	return(line);
}

char	*cpy_srch_buff(char *str_buff, char **str_stash)
{
	char	*n_l_ptr;
	
	if(*str_stash == 0)
	{
		*str_stash = ft_strdup(str_buff);
		printf("Stash(empty before) after copying buff : %s\n", *str_stash);
	}
	else
	{ 
		*str_stash = my_strjoin(str_stash, str_buff);
		printf("Stash(not empty bef) after strjoin : %s\n", *str_stash);
	}
	n_l_ptr = strchr_newline(*str_stash, '\n');
	printf("n_l_ptr: %s\n", n_l_ptr);
	if (n_l_ptr == 0)
		return (0);
	return(n_l_ptr);
}

char	*complete_line(char **str_stash, char *new_line)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	if(*str_stash == 0)
		return (0);
	final_line = (char *)malloc(sizeof(char) * (100));
	if (final_line == 0)
		return (0);
	if (new_line == 0)
	{
		final_line = *str_stash;
		return (final_line);
	}
	i = 0;
	j = 0;
	printf("final line ptr %p\n", final_line);
	printf("final line empty %s\n", final_line);
	printf("stash passed to complete line: %s\n", *str_stash);
	printf("new line char: %c\n", *new_line);
	while (*str_stash[i] != *new_line)
	{
		final_line[j] = *str_stash[i];
		str_stash[i] += 1;
		j++;
	}
	printf("final line withou newline %s\n", final_line);
	final_line[j] = *str_stash[i];
	printf("final line %s\n", final_line);
	final_line[j + 1] = '\0';
//	str_stash = (&new_line) + 1;
	return(final_line);	
}
		
/*void	clean_stash(char **str_stash)
{
	char	*temp;
	size_t	length_stash;
	size_t	i;
	
	length_stash = ft_strlen(*str_stash);
	i = 0;
	while (*str_stash[i] != '\n' && *str_stash[i] != 0)
		i++;
	temp = (char *)malloc(sizeof(char) * length_stash - i);
	while (str_stash[i] != 0)
	{
		temp [i - length_stash] = str_stash[i + 1];
		i++;
	}
	//free(str_stash);
	str_stash = temp;
//	free(temp);

}*/
				
/*void	free_if_needed(char *str_stash, char *str_buff)
{
	if (str_stash != 0)
		free(str_stash);
	if (str_buff != 0)
		free(str_buff);
	return;
}*/
