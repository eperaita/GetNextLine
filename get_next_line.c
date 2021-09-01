/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:50:21 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/01 18:28:46 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h> 
#include "get_next_line.h"

char	*ft_remain_in_temp(char *temp, char *final)
{
	char	*new_temp;
	int		len;
	int		start;

	if (!temp || (!ft_strchr(temp, '\n')))
	{
		free (temp);
		return (NULL);
	}
	len = ft_strlen(temp) - ft_strlen(final);
	start = ft_strlen(final);
	new_temp = ft_substr(temp, start, len);
	free(temp);
	return (new_temp);
}

char	*ft_final_str(char *final, char *temp)
{
	size_t	len;

	len = 0;
	if (!temp)
		return (NULL);
	if (ft_strchr(temp, '\n'))
		final = ft_substr(temp, 0, ft_strlen(temp)
				- ft_strlen(ft_strchr(temp, '\n')) + 1);
	else
		final = ft_substr(temp, 0, ft_strlen(temp));
	return (final);
}

char	*ft_update_temp(char *temp, char *buff)
{
	char	*p;

	if (!temp)
	{
		temp = malloc (1);
		temp[0] = '\0';
	}
	p = (char *)malloc((ft_strlen(temp) + ft_strlen(buff) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, temp, ft_strlen(temp) + 1);
	ft_strlcat(&p[ft_strlen(temp)], buff, ft_strlen(buff) + 1);
	free(temp);
	return (p);
}

char	*ft_read_to_temp(int fd, char *temp)
{
	char	*buff;
	int		nbytes;

	nbytes = 1;
	while (!ft_strchr(temp, '\n') && nbytes > 0)
	{
		buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buff)
			return (0);
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		temp = ft_update_temp(temp, buff);
		free(buff);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*temp;

	final = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_read_to_temp(fd, temp);
	final = ft_final_str(final, temp);
	temp = ft_remain_in_temp(temp, final);
	return (final);
}
