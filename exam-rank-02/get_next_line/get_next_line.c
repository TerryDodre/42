#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int		i = 0;

	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *tmp, int c)
{
	while (tmp && *tmp != (unsigned char)c)
	{
		if (!*tmp)
			return (NULL);
		tmp++;
	}
	return ((char *)tmp);
}

char	*ft_strdup(char	*s)
{
	int		i = 0;
	char	*ret;
	
	if (s == NULL)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i = 0;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char *s, int start, int e)
{
	int		i = 0;
	char	*ret;

	if (s == NULL)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * (e - start) + 1)))
		return (NULL);
	while (start < e)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

int		ret_line(char **tmp, char **line, int len)
{
	int		stop = 0;
	char	*dash;

	if (len < 0)
		return (-1);
	else if (len == 0 && (*tmp) == NULL)
		*line = ft_strdup("");
	else
	{
		while ((*tmp)[stop] && (*tmp)[stop] != '\n')
			stop++;
		if ((*tmp)[stop] == '\n')
		{
			*line = ft_substr((*tmp), 0, stop);
			dash = ft_strdup(&(*tmp)[stop + 1]);
			free(*tmp);
			(*tmp) = dash;
			return (1);
		}
		(*line) = ft_strdup(*tmp);
		free(*tmp);
		(*tmp) = NULL;
	}
	return (0);
}

int		get_next_line(char **line)
{
	static char		*tmp;
	char			*dash;
	char			buffer[1000000];
	int				len;

	while (!ft_strchr(tmp, '\n'))
	{
		if ((len = read(0, buffer, 999999)) <= 0)
			break;
		buffer[len] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buffer);
		else
		{
			dash = ft_strjoin(tmp, buffer);
			free(tmp);
			tmp = dash;
		}
	}
	return (ret_line(&tmp, line, len));
}