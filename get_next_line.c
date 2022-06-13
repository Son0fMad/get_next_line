/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:36:00 by dcloud            #+#    #+#             */
/*   Updated: 2021/12/06 17:01:05 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	flag(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

static char	*save_buffer(char *str, char *buf)
{
	char	*tempo;

	if (str)
	{
		tempo = str;
		str = ft_strjoin(str, buf);
		free(tempo);
	}
	else
		str = ft_strdup(buf);
	return (str);
}

static char	*check_ostatok(char **stroka)
{
	char	*point;
	char	*line;
	size_t	count;

	count = 0;
	if (!(*stroka))
		return (NULL);
	while ((*stroka)[count] != '\n' && (*stroka)[count])
		count++;
	if (count < ft_strlen(*stroka))
	{
		point = *stroka;
		line = ft_substr(*stroka, 0, ++count);
		*stroka = ft_substr(*stroka, count, ft_strlen(*stroka));
		free(point);
	}
	else
	{
		line = *stroka;
		*stroka = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*ostatok;
	char		*buf;
	int			read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = read(fd, buf, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buf[read_byte] = '\0';
		ostatok = save_buffer(ostatok, buf);
		if (flag(ostatok))
			break ;
		read_byte = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (check_ostatok(&ostatok));
}

int	main()
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open("1.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
		printf("%s", str);
	return (0);
}
