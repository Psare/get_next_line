/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:27:32 by damarry           #+#    #+#             */
/*   Updated: 2021/10/22 21:29:13 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static void	ft_read(int fd, char **str, char **buff, char **line)
{
	int		bwr;
	char	*tmp;

	bwr = 1;
	while (!ft_strchr(*str, '\n') && bwr)
	{
		bwr = read(fd, *buff, BUFFER_SIZE);
		(*buff)[bwr] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, *buff);
		free_ptr(tmp);
	}
	free_ptr(*buff);
	ft_get_line(line, str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
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
	if (!str[fd])
		str[fd] = ft_strdup("");
	ft_read(fd, &str[fd], &buff, &line);
	if (*line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}
