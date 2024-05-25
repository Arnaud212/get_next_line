/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:12:13 by agiraud           #+#    #+#             */
/*   Updated: 2020/05/25 16:12:13 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_is_in_str(char *str, char c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_newstr(size_t i);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	ft_free(char ***str);
int		ft_line(char **line, char **tmp);

#endif
