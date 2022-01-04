/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:58:58 by damarry           #+#    #+#             */
/*   Updated: 2021/10/22 18:51:40 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = (char *)malloc(sizeof(char) * (sum + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while ((i + j) < sum)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return ((char *)str);
}

size_t	ft_strlen(const char *s)
{
	size_t	b;

	b = 0;
	while (s[b] != '\0')
		b++;
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{	
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (i < len)
		len = i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (start < ft_strlen(s) && len > 0 && s[start + n] != '\0')
	{
		str[n] = s[start + n];
		n++;
		len--;
	}
	str[n] = '\0';
	return (str);
}
