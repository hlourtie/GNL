/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:14:56 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/23 09:37:29 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

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
**	delete the str when we don't need it anymore
*/

void		del_str(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

/*
** modified calloc function for the purpose of this gnl
*/

char		*ft_callocgnl(int nbr)
{
	char	*ptr;

	if (!(ptr = malloc(nbr)))
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

/*
**	get the new line and puts it in the right pointer
*/

int			new_line(int ret, int fd, char **line, char **str)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		CHECKMALL((*line = ft_substr(str[fd], 0, len)));
		CHECKMALL((tmp = ft_strdup(&str[fd][len + 1])));
		free(str[fd]);
		str[fd] = tmp;	
	}
	else if(str[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		CHECKMALL((*line = ft_strdup(str[fd])));
		del_str(&str[fd]);
		return (0);
	}
	return (1);
}

/*
**	the main function that reads and return accordingly.
*/

int			get_next_line(int fd, char **line)
{
	static	char	*str[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
		{
			CHECKMALL((str[fd] = ft_callocgnl(1)));
		}
		CHECKMALL((tmp = ft_strjoin(str[fd], buff)));
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchrgnl(str[fd]))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd]== NULL && (*line = ft_callocgnl(1)))
		return (0);
	return (new_line(ret, fd, line, str));
}
