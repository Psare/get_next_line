/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:01 by damarry           #+#    #+#             */
/*   Updated: 2021/10/22 20:43:29 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

static char	*ft_get_line(char **line, char **str)
{
	char	*new;
	int		i;

	i = 0;
	new = *str;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if (ft_strchr(*str, '\n'))
	{
		*line = ft_substr(*str, 0, i + 1);
		*str = ft_strdup(*str + i + 1);
	}
	else
	{
		*line = ft_strdup(new);
		*str = NULL;
	}
	free_ptr(new);
	return (*line);
}

static char	*ft_read(int fd, char **str, char **buff)
{
	int		bwr;
	char	*tmp;

	bwr = 1;
	while (!ft_strchr(*str, '\n') && bwr)
	{
		bwr = read(fd, *buff, BUFFER_SIZE);
		if (bwr == -1)
		{
			free_ptr(*buff);
			return (NULL);
		}
		(*buff)[bwr] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, *buff);
		free_ptr(tmp);
	}
	free_ptr(*buff);
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read(fd, buff, 0) < 0)
	{
		free_ptr(buff);
		return (NULL);
	}
	if (!str)
		str = ft_strdup("");
	str = ft_read(fd, &str, &buff);
	ft_get_line(&line, &str);
	if (*line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}
