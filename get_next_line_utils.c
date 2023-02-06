/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/06 22:02:09 by cestevez         ###   ########.fr       */
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

char	*strdup_free(char *s)
{
	size_t	length;
	char	*ptr;

	length = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr != 0)
	{
		length = 0;
		while (s[length] != '\0')
		{
			ptr[length] = s[length];
			length++;
		}
		ptr[length] = '\0';
		free(s);
		return (ptr);
	}
	return (0);
}

char	*strjoin_free(char *stash, char *buff)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*temp;

	len = ft_strlen(stash) + ft_strlen(buff);
	i = ft_strlen(stash);
	j = 0;
	temp = strdup_free(stash);
	stash = (char *)malloc(len + 1);
	if (!stash)
		return (0);
	stash = strdup_free(temp);
	while (len > i && buff[j] != '\0')
	{
		stash[i] = buff[j];
		i++;
		j++;
	}
	stash[i] = '\0';
	free(buff);
	free(temp);
	return (stash);
}

int	strchr_newline(char *s, int new_line_c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)new_line_c)
			return (1);
		i++;
	}
	if (s[i] == (char)new_line_c)
		return (1);
	return (0);
}
