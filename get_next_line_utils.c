/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/09 23:48:20 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	length;
	char	*ptr;

	length = 0;
	while (s[length] != '\0')
		length++;
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr)
	{
		length = 0;
		while (s[length] != '\0')
		{
			ptr[length] = s[length];
			length++;
		}
		ptr[length] = '\0';
		return (ptr);
	}
	return (0);
}

char	*my_strjoin(char **stash, char *buff)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*temp;

	len = ft_strlen(*stash) + ft_strlen(buff);
	i = ft_strlen(*stash);
	j = 0;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	printf("stash passed to strjoin: %s\n", *stash);
	temp = ft_strdup(*stash);
	printf("copy of the stash in temp %s\n", temp);
	printf("buffer passed to strjoin: %s\n", buff);
	while (buff[j] != '\0')
	{
		temp[i] = buff[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	printf("joined, null terminated temp %s\n", temp);
	//free(&stash);
	//free(buff);
	return (temp);
}

char	*strchr_newline(char *stash, int new_line_c)
{
	size_t	i;
	size_t	len;
	char	*n_l;

	i = 0;
	len = ft_strlen(stash);
	while (stash[i] != '\0')
	{
		if (stash[i] == (char)new_line_c)
		{
			n_l = (char *)malloc(sizeof(char) * (len - i + 1));
			if (n_l == 0)
				return (0);
			n_l = &stash[i];
			return(n_l);
		}
		i++;
	}
	return (0);
}