#include "libft.c"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	buff;

	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		buff = ft_strlen(s) - start + 1;
	else
		buff = len + 1;
	dest = ft_calloc(buff, 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, buff);
	return (dest);
}