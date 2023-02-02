/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:06 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/02 20:17:31 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		read_ret;
	char		*str_buff[BUFF_SIZE + 1];
	static char *str_stash;
	char		*line;

	if (fd < 0 || BUFF_SIZE < 1 || str_buff == 0)
	{
		if (str_stash != 0)
			free(str_stash);
		return(1);
	}
	read_ret = read(fd, str_buff, BUFF_SIZE);
	if (read_ret < 0)
	{
		free(str_buff);
		if (str_stash != 0)
			free(str_stash);
		return (-1);//or (0)??
	}
	str_buff[read_ret] == '\0';
	if (read_ret == 0)
	{
		free(str_buff);
		if (str_stash != 0)
			free(str_stash);
		return (0);
	}
	if (read_ret > 0)
	{
		line = copy_buff(&str_buff, read_ret, &str_stash);
		free(str_buff);
	}
	return(line);
}

char *copy_buff(char *str_buff, size_t read_ret, char *str_stash)
{
	int		new_line;
	char	*n_l_ptr;
	char	*line;

	new_line = 10;
	if(str_stash == 0)
	{
		str_stash = ft_strdup(str_buff);
		if (str_stash == 0)
			return (0);
	}
	else 
		str_stash = ft_strjoin(str_stash, str_buff);
	n_l_ptr = ft_strchr(str_stash, new_line);
	if (n_l_ptr == 0)
		return (str_stash);
	save_line(line, str_stash, n_l_ptr);
}

void	save_line(line, str_stash, n_l_ptr)
{
	size_t	i;
	size_t	length;

	i = 0;
	while (str_stash[i] != *n_l_ptr)
	{
		line[i] = str_stash[i];
		i++;
	}
	line[i] = str_stash[i];
	line[i + 1] = '\0';
	
}