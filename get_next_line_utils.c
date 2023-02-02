/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/02 20:17:27 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
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
		return (ptr);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	joint_str = (char *)malloc(i + 1);
	if (!joint_str)
		return (0);
	ft_strlcpy(joint_str, s1, i + 1);
	ft_strlcat(joint_str, s2, i + 1);
	return (joint_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}