/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:35:56 by dcloud            #+#    #+#             */
/*   Updated: 2021/12/06 16:17:44 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	length;
	unsigned int	i;
	char			*str;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	length = ft_strlen(s);
	if (length <= start)
		len = 0;
	if (length - start < len)
		len = length - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*res;
	int		i;

	if ((s1) && (s2))
	{
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		res = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
		if (res == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			res[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			res[ls1] = s2[i];
			ls1++;
		}
		res[ls1] = '\0';
		return (res);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	t;

	t = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	else
	{
		while (src[t] && (t < dstsize - 1))
		{
			dst[t] = src[t];
			t++;
		}
		dst[t] = '\0';
		while (src[t])
			t++;
		return (t);
	}
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = ft_strlen(src);
	str = NULL;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, i + 1);
	return (str);
}
