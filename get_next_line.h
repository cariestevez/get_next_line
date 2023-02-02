/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:56:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/02 20:17:31 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#ifndef BUFF_SIZE 
# define BUFF_SIZE  10

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char    *copy_buff(char *str_buff, size_t read_ret, char *str_stash);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif