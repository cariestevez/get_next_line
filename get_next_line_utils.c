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

char	*strdup_free(char *s)
{
	size_t	length;
	char	*ptr;
	
	printf("and stash passed to strdup: %s\n", s);
	length = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (!ptr)
		return (0);
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

char	*strjoin_free(char **stash, char *buff)
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
	temp = strdup_free(*stash);
	printf("stash after strdup: %s\n", *stash);
	printf("copy of stash in temp %s\n", temp);
	while (buff[j] != '\0')
	{
		temp[i + 1] = buff[j];
		i++;
		j++;
	}
	temp[i + 1] = '\0';
	printf("temp %s\n", temp);
	free(*stash);
	free(buff);
	return (temp);
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
