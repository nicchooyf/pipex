/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:20:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/27 18:11:02 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	p = (char *)malloc((len + 1) * (sizeof(char)));
	if (!p)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s, const char *s2)
{
	int		n;
	char	*tmp;
	char	*p;

	if (!s || !s2)
		return (NULL);
	n = ft_strlen(s);
	p = malloc(sizeof(char) * (n + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	tmp = p;
	while (*s)
		*tmp++ = *s++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	c %= 128;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		p = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len && s[i + start])
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
