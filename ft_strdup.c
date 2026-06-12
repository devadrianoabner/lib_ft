#include "libft.h"

char	*ft_strdup(const char *s)
{
    size_t	i;
	size_t	size;
    char	*ptr;

    i = 0;
	size = ft_strlen(s) + 1;
	ptr = ft_calloc(size, 1);
    while (s[i] != 0)
    {
		ptr[i] = s[i];
		i++;
    }
	ptr[i] = '\0';
	return (ptr);
}