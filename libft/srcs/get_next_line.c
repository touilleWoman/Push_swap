/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:43:47 by jleblond          #+#    #+#             */
/*   Updated: 2018/12/18 14:43:49 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t			read_and_stock(const int fd, char **end)
{
	ssize_t			ret;
	char			buf[BUFF_SIZE + 1];
	char			*temp;

	temp = NULL;
	ret = read(fd, buf, BUFF_SIZE);
	if ((ret == -1) || (ret == 0))
		return (ret);
	buf[ret] = 0;
	if (*end == NULL)
	{
		if ((*end = ft_strdup(buf)) == NULL)
			return (-1);
	}
	else
	{
		if ((temp = ft_strjoin(*end, buf)) == NULL)
			return (-1);
		free(*end);
		*end = temp;
	}
	return (ret);
}

char			*copy_line(const char *str)
{
	size_t			x;
	char			*stock;

	x = 0;
	while ((str[x] != 0) && (str[x] != '\n'))
	{
		x++;
	}
	stock = (char*)malloc(sizeof(char) * (x + 2));
	if (stock == NULL)
		return (0);
	x = 0;
	while ((str[x] != 0) && (str[x] != '\n'))
	{
		stock[x] = str[x];
		x++;
	}
	stock[x] = '\0';
	return (stock);
}

int				renew_end(char **line, char **end)
{
	char			*temp;

	*line = copy_line(*end);
	if (*line == NULL)
		return (-1);
	temp = ft_strdup(ft_strchr(*end, '\n') + 1);
	if (temp == NULL)
		return (-1);
	free(*end);
	*end = temp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*end = NULL;

	if (BUFF_SIZE < 1 || line == 0 || fd < 0 )
		return (-1);
	while ((end == NULL) || (ft_strchr(end, '\n') == NULL))
	{
		ret = read_and_stock(fd, &end);
		if ((ret == -1) || ((ret == 0) && (end == NULL)))
			return (ret);
		if (ret == 0)
		{
			if (end[0] == '\0')
			{
				free(end);
				end = NULL;
				return (0);
			}
			*line = end;
			end = NULL;
			return (1);
		}
	}
	return (renew_end(line, &end));
}
