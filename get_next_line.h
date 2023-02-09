/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:56:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/02/09 23:26:24 by cestevez         ###   ########.fr       */
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
size_t	ft_strlen(char *s);
int	cpy_srch_buff(char *str_buff, char **str_stash);
char	*strdup_free(char *s);
char	*strjoin_free(char **stash, char *buff);
char	*strlcat_line(char *str, char *dst, char *src, size_t size);
int	    strchr_newline(char *s, int new_line_c);
char	*complete_line(char *str_stash);
//void	clean_stash(char *str_stash);

#endif