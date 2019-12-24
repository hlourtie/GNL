/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:15:31 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/23 09:34:37 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define CHECKMALL(x) if(!x) return (-1);

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strchrgnl(const char *s);
#endif
