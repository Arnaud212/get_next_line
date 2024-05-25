/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:12:07 by agiraud           #+#    #+#             */
/*   Updated: 2020/05/25 16:12:07 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_free(char ***str)
{
	free(**str);
	**str = NULL;
}

int			ft_is_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_line(char **line, char **tmp)
{
	char	*str;
	int		i;

	if (!ft_strlen(*tmp))
	{
		*line = ft_newstr(0);
		ft_free(&tmp);
		return (0);
	}
	i = ft_is_in_str(*tmp, '\n');
	if (i != -1)
	{
		*line = ft_newstr(i + 1);
		ft_memcpy(*line, *tmp, i);
		(*line)[i] = '\0';
		str = ft_strdup(*tmp + i + 1);
		ft_free(&tmp);
		*tmp = str;
		return (1);
	}
	*line = ft_strdup(*tmp);
	ft_free(&tmp);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	static char		*tmp = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!tmp)
		tmp = ft_newstr(0);
	while (ft_is_in_str(tmp, '\n') == -1 &&
		(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin_free(tmp, buf)))
			return (-1);
	}
	return (ft_line(line, &tmp));
}
