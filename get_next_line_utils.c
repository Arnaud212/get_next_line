/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:11:59 by agiraud           #+#    #+#             */
/*   Updated: 2020/05/25 16:11:59 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen((char *)str) + 1)))
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned int	i;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!n || dst2 == src2)
		return (dst2);
	while (n--)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}

char		*ft_newstr(size_t i)
{
	char	*str;
	size_t	j;

	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (str && j < i + 1)
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
					ft_strlen((char *)s2)) + 1)))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	s1 = NULL;
	return (dst);
}
