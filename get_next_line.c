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
	ssize_t		read_ret;
	char		*buff;
	static char *str_stash;
	char		*new_line_ptr;
	char		*final_line;

	if (fd < 0 || BUFF_SIZE < 1)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	new_line_ptr = 0;
	while (new_line_ptr == 0)
	{
		read_ret = read(fd, buff, BUFF_SIZE);
		if (read_ret < 0)
			return (0);
		if (read_ret > 0)
		{
			buff[read_ret] = '\0';
			new_line_ptr = cpy_srch_buff(buff, &str_stash);
		}
		if (read_ret == 0)
		{
			if (str_stash == 0)
				return (0);
			buff = 0;
		//	free(buff);
			new_line_ptr = cpy_srch_buff(buff, &str_stash);
			if (new_line_ptr != 0)
				break;
			final_line = str_stash;
			str_stash = 0;
			return (final_line);
		}
	}
//	final_line = complete_line(&str_stash, new_line_ptr);
//	str_stash = *(&new_line_ptr) + 1;
	return (complete_line(&str_stash, new_line_ptr));
}

char	*cpy_srch_buff(char *str_buff, char **str_stash)
{	
	if (*str_stash != 0 && str_buff != 0)
		*str_stash = my_strjoin(str_stash, str_buff);
	else if (*str_stash == 0)
		*str_stash = ft_strdup(str_buff);
	else
		;
	return (strchr_newline(*str_stash, '\n'));
}

char	*complete_line(char **str_stash, char *new_line)
{
	size_t	i;
	size_t	j;
	char	*line;

	line = (char *)malloc(ft_strlen(*str_stash) - ft_strlen(new_line) + 2);
	if(*str_stash == 0 || line == 0)
		return (0);
	if (new_line == 0)
		return (*str_stash);
	i = 0;
	j = 0;
	while (str_stash[i][j] != *new_line)
	{
		line[j] = str_stash[i][j];
		j++;
	}
	line[j] = str_stash[i][j];
	line[j + 1] = '\0';
	*str_stash = *(&new_line) + 1;
	return (line);	
}
