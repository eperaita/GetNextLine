/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:55:15 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/01 14:53:53 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{	
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l] != '\0')
		l++;
	return (l);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	e;

	j = ft_strlen(src);
	i = ft_strlen(dest);
	if (size > i && size > 0)
	{
		e = i + j;
		size = size - i - 1;
		j = 0;
		while (src[j] && size != 0 )
		{
			dest[i++] = src[j++];
			size--;
		}
		dest[i] = '\0';
	}
	else
		e = size + j;
	return (e);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[j] != '\0')
		j++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	num_chars;

	i = 0;
	num_chars = 0;
	if (!s || len <= 0)
		return (NULL);
	if (start < ft_strlen(s))
		num_chars = ft_strlen(s) - (size_t)start;
	if (len < num_chars)
		num_chars = len;
	p = (char *)malloc((num_chars + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (num_chars && start < ft_strlen(s))
	{
		p[i] = ((char *)s)[start + i];
		i++;
		num_chars--;
	}
	p[i] = '\0';
	return (p);
}
