/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:14:40 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/23 09:36:42 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	duplicates the string that was given and put it in a new one
**	is used here to duplicate the rest of the file that was read
**	so we can free the part that has already been returned.
*/

char				*ft_strdup(char *src)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	while (src[len])
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
** classic strlen
*/

static size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str)
		i++;
	return (i);
}

/*
** strjoin for joining buffer and the file in mem
*/

char				*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len;
	size_t	i;
	size_t	len2;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * (len + len2 + 1))))
		return (NULL);
	ret[len + len2] = '\0';
	i = 0;
	while (i < len && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2 && s2[i])
	{
		ret[i + len] = s2[i];
		i++;
	}
	return (ret);
}

/*
** modified strchr so that it checks only for \n
*/

int					ft_strchrgnl(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

/*
**	gets the substring to return the line that we actually need to return.
*/

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || ft_strlen(s) < start)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
