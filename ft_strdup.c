#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
    char	*ptr;

	size = ft_strlen(s) + 1;
	ptr = ft_calloc(size, 1);
	ft_strlcpy(ptr, s, size);
	return (ptr);
}