/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:56:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/03/03 12:31:22 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*save_buff_srch(char **buff, char **stash);
char	*complete_line(char **stash, char *new_line_ptr);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*my_strjoin(char **stash, char **buff);
char	*strchr_newline(char *s, int new_line_char);
char	*free_buff(char **stash, char **buff);
void	*free_stash(char *stash, char *buff);

#endif
