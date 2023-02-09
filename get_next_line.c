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
	int			is_new_line;

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
		printf("Read return is: %ld\n", read_ret);
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
			if (str_stash != 0)
				return(complete_line(str_stash));
			return (0);
		}
		if (read_ret > 0)
		{
			str_buff[read_ret] = '\0';
			printf("Null terminated buffer: %s\n", str_buff);
			is_new_line = cpy_srch_buff(str_buff, &str_stash);
			printf("yes, stash is: %s\n", str_stash);
			printf("yes, buffer is: %s\n", str_buff);
			printf("and new line or not?: %d\n", is_new_line);
		}
	}
	return(complete_line(str_stash));
}

int	cpy_srch_buff(char *str_buff, char **str_stash)
{
	int	n_l;
	
	n_l = 0;
	if(*str_stash == 0)
	{
		*str_stash = strdup_free(str_buff);
		printf("Stash(before empty) after copying buff : %s\n", *str_stash);
		printf("Buffer after freeing: %s\n", str_buff);
	}
	else 
		*str_stash = strjoin_free(str_stash, str_buff);
	n_l = strchr_newline(*str_stash, '\n');
	if (n_l == 0)
		return (0);
	return(1);
}

char	*complete_line(char *str_stash)
{
	char	*final_line;
	size_t	i;

	if(str_stash == 0)
		return (0);
	final_line = (char *)malloc(sizeof(char) * ft_strlen(str_stash) + 1);
	if (final_line == 0)
		return (0);
	i = 0;
	while (str_stash[i] != '\n' && str_stash != 0)
	{
		final_line[i] = str_stash[i];
		i++;
	}
	if (str_stash[i] == '\n')
	{
		final_line[i] = str_stash[i];
		final_line[i + 1] = '\0';
	}
	else
		final_line[i] = '\0';
	free(str_stash);
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
