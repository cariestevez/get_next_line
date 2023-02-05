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
	static char 	*str_stash;
	char		*the_line;
	char		*n_l_ptr;

	n_l_ptr = (char *)malloc(sizeof(char) * 1);
	if (n_l_ptr == 0)
		return (0);
	n_l_ptr[0] = '\0';
	if (fd < 0 || BUFF_SIZE < 1) // || str_buff == 0)??
		return (free_if_needed(str_stash, str_buff);
	while (n_l_ptr[0] == '\0')
	{
		read_ret = read(fd, str_buff, BUFF_SIZE);
		if (read_ret == -1)
			//free(str_buff);??
			return (free_if_needed(str_stash, str_buff);
		str_buff[read_ret] == '\0';
		if (read_ret > 0)
		{
			the_line = copy_buff(&str_buff, &str_stash, &n_l_ptr);
			//if (the_line == 0)
			//	the_line = save_line(the_line, str_stash, n_l_ptr);
		}
		if (read_ret == 0)//EOF
			return (save_line(the_line, str_stash, n_l_ptr));
	}
	return(the_line);
}

char *copy_buff(char *str_buff, char *str_stash, char *n_l_ptr)
{
	int	new_line;
	char	*line;

	new_line = '\n';
	if(str_stash == 0)
	{
		str_stash = strdup_free(str_buff);
		//if (str_stash == 0)
			//return (0);
	}
	else 
		strjoin_free(str_stash, str_buff);
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
				 
void	free_if_needed(char *str_stash, char *str_buff)
{
	if (str_stash != 0)
		free(str_stash);
	if (str_buff != 0)
		free(str_buff);
	return (0);
}
	
