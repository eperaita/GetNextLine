/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:51:20 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/01 16:42:34 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_update_temp(char *temp, char *buff);
char	*ft_final_str(char *final, char *temp);
char	*ft_remain_in_temp(char *temp, char *final);
char	*ft_read_to_temp(int fd, char *temp);
char	*ft_strchr(char *temp, int c);
size_t	*ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
