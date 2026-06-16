/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:35:11 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/15 17:35:12 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <stdio.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>

// // =========================================================================
// // FUNÇÕES AUXILIARES PARA TESTES DE LISTA E STRING
// // =========================================================================

// void	del_func(void *content)
// {
// 	free(content);
// }

// void	*map_func(void *content)
// {
// 	return (ft_strdup((char *)content));
// }

// void	iter_func(void *content)
// {
// 	char *str = (char *)content;
// 	int i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// }

// char	mapi_func(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper(c));
// }

// void	striteri_func(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }

// // =========================================================================
// // BLOCOS DE TESTE
// // =========================================================================

// void	test_char_classification(void)
// {
// 	printf("\n--- CLASSIFICACAO E CONVERSAO ---\n");
// 	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
// 	printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
// 	printf("ft_isalnum('a'): %d\n", ft_isalnum('a'));
// 	printf("ft_isprint(' '): %d\n", ft_isprint(' '));
// 	printf("ft_isascii(127): %d\n", ft_isascii(127));
// 	printf("ft_tolower('Z'): %c\n", ft_tolower('Z'));
// 	printf("ft_toupper('z'): %c\n", ft_toupper('z'));
// }

// void	test_memory_functions(void)
// {
// 	printf("\n--- MEMORIA ---\n");
// 	char buffer[20] = "abcdefghijklmnop";
	
// 	ft_memset(buffer, 'X', 5);
// 	printf("ft_memset: %s\n", buffer);
	
// 	ft_bzero(buffer, 2);
// 	printf("ft_bzero: (primeiros 2 nulos, 3o char): %c\n", buffer[2]);

// 	char dest[20] = "123456789";
// 	ft_memcpy(dest, "abc", 3);
// 	printf("ft_memcpy: %s\n", dest);

// 	char dest2[20] = "123456789";
// 	ft_memmove(dest2 + 3, dest2, 5); // Overlap test
// 	printf("ft_memmove: %s\n", dest2);

// 	char *mem = ft_memchr("escola 42", '4', 9);
// 	printf("ft_memchr ('4' in 'escola 42'): %s\n", mem);
	
// 	printf("ft_memcmp ('abc', 'abd'): %d\n", ft_memcmp("abc", "abd", 3));
// }

// void	test_string_functions(void)
// {
// 	printf("\n--- STRINGS BASE ---\n");
// 	printf("ft_strlen('42SP'): %zu\n", ft_strlen("42SP"));
// 	printf("ft_strchr('escola', 'c'): %s\n", ft_strchr("escola", 'c'));
// 	printf("ft_strrchr('escola', 'e'): %s\n", ft_strrchr("escola", 'e'));
// 	printf("ft_strncmp('abc', 'abcd', 3): %d\n", ft_strncmp("abc", "abcd", 3));
	
// 	char dst_cpy[10];
// 	ft_strlcpy(dst_cpy, "42", sizeof(dst_cpy));
// 	printf("ft_strlcpy: %s\n", dst_cpy);

// 	char dst_cat[20] = "Escola ";
// 	ft_strlcat(dst_cat, "42", sizeof(dst_cat));
// 	printf("ft_strlcat: %s\n", dst_cat);

// 	printf("ft_strnstr: %s\n", ft_strnstr("escola 42 sao paulo", "42", 15));
// 	printf("ft_atoi('-42'): %d\n", ft_atoi("-42"));
// }

// void	test_advanced_strings(void)
// {
// 	printf("\n--- STRINGS AVANCADAS E ALOCACAO ---\n");
	
// 	char *calloc_str = ft_calloc(5, sizeof(char));
// 	printf("ft_calloc (deve ser vazio): '%s'\n", calloc_str);
// 	free(calloc_str);

// 	char *dup = ft_strdup("42");
// 	printf("ft_strdup: %s\n", dup);
// 	free(dup);

// 	char *sub = ft_substr("Escola 42", 7, 2);
// 	printf("ft_substr: %s\n", sub);
// 	free(sub);

// 	char *join = ft_strjoin("Escola ", "42");
// 	printf("ft_strjoin: %s\n", join);
// 	free(join);

// 	char *trim = ft_strtrim("xx42xx", "x");
// 	printf("ft_strtrim: %s\n", trim);
// 	free(trim);

// 	char *itoa_res = ft_itoa(-42);
// 	printf("ft_itoa: %s\n", itoa_res);
// 	free(itoa_res);

// 	printf("ft_split('escola 42 sp', ' '):\n");
// 	char **split = ft_split("escola 42 sp", ' ');
// 	if (split)
// 	{
// 		for (int i = 0; split[i] != NULL; i++)
// 		{
// 			printf("  [%d]: %s\n", i, split[i]);
// 			free(split[i]);
// 		}
// 		free(split);
// 	}

// 	char *mapi_str = ft_strmapi("abc", mapi_func);
// 	printf("ft_strmapi ('abc'): %s\n", mapi_str);
// 	free(mapi_str);

// 	char iteri_str[] = "xyz";
// 	ft_striteri(iteri_str, striteri_func);
// 	printf("ft_striteri ('xyz'): %s\n", iteri_str);
// }

// void	test_file_descriptors(void)
// {
// 	printf("\n--- FILE DESCRIPTORS ---\n");
// 	printf("Imprimindo no stdout (FD 1):\n");
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Hello 42\n", 1);
// 	ft_putendl_fd("Hello com newline", 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	ft_putchar_fd('\n', 1);
// }

// void	test_linked_lists(void)
// {
// 	printf("\n--- LISTAS ENCADEADAS ---\n");
	
// 	t_list *node1 = ft_lstnew(ft_strdup("Node 1"));
// 	t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
// 	t_list *node3 = ft_lstnew(ft_strdup("Node 3"));

// 	ft_lstadd_front(&node2, node1);
// 	ft_lstadd_back(&node1, node3);

// 	printf("ft_lstsize: %d\n", ft_lstsize(node1));
// 	printf("ft_lstlast: %s\n", (char *)ft_lstlast(node1)->content);

// 	ft_lstiter(node1, iter_func);
// 	printf("ft_lstiter (upper): %s\n", (char *)node1->content);

// 	t_list *mapped_list = ft_lstmap(node1, map_func, del_func);
// 	printf("ft_lstmap (copia do conteudo): %s\n", (char *)mapped_list->content);

// 	ft_lstclear(&mapped_list, del_func);
// 	ft_lstclear(&node1, del_func);
// 	printf("Listas limpas com ft_lstclear.\n");
// }

// // =========================================================================
// // MAIN EXECUTORA
// // =========================================================================

// int	main(void)
// {
// 	printf("========================================\n");
// 	printf("       INICIANDO TESTES DA LIBFT        \n");
// 	printf("========================================\n");

// 	test_char_classification();
// 	test_memory_functions();
// 	test_string_functions();
// 	test_advanced_strings();
// 	test_file_descriptors();
// 	test_linked_lists();

// 	printf("\n========================================\n");
// 	printf("        TESTES CONCLUIDOS               \n");
// 	printf("========================================\n");
// 	return (0);
// }
