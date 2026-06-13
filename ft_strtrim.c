#include "libft.h"

int	ft_filter(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *s2;
	size_t	i;
	size_t	j;

	if(!s1 || !set)
		return (NULL);
	i = 0;
	if(s1[i] == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (s1[i] != 0 && ft_filter(s1[i], set))
		i++;
	while (j > i && ft_filter(s1[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	s2 = ft_substr(s1, i, j - i + 1);
	return (s2);
}
