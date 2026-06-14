# Libft - Controle de Desenvolvimento

## Arquivos de Configuração e Documentação
- [ ] `Makefile` 
- [ ] `README.md`
- [ ] `libft.h`

## Parte 1: Funções da Libc

### Classificação e Conversão de Caracteres
- [x] ft_isalpha.c
- [x] ft_isdigit.c
- [x] ft_isalnum.c
- [x] ft_isascii.c
- [x] ft_isprint.c
- [x] ft_toupper.c
- [x] ft_tolower.c

### Manipulação e Busca em Memória
- [x] ft_memset.c
- [x] ft_bzero.c
- [x] ft_memcpy.c
- [x] ft_memmove.c
- [x] ft_memchr.c
- [x] ft_memcmp.c

### Manipulação e Busca em Strings
- [x] ft_strlen.c
- [x] ft_strchr.c
- [x] ft_strrchr.c
- [x] ft_strncmp.c
- [x] ft_strlcpy.c
- [x] ft_strlcat.c
- [x] ft_strnstr.c
- [x] ft_atoi.c

### Alocação Dinâmica Base
- [x] ft_calloc.c
- [x] ft_strdup.c

---

## Parte 2: Funções Adicionais

### Manipulação Avançada de Strings
- [x] ft_substr.c
- [x] ft_strjoin.c
- [x] ft_strtrim.c
- [ ] ft_split.c
- [x] ft_itoa.c
- [x] ft_strmapi.c
- [x] ft_striteri.c

### Escrita em File Descriptors
- [x] ft_putchar_fd.c
- [x] ft_putstr_fd.c
- [x] ft_putendl_fd.c
- [x] ft_putnbr_fd.c

---

## Parte 3: (Listas Encadeadas) - verificar includes das libs e norminette
- [x] ft_lstnew.c
- [x] ft_lstadd_front.c
- [x] ft_lstsize.c
- [x] ft_lstlast.c
- [x] ft_lstadd_back.c
- [x] ft_lstdelone.c
- [x] ft_lstclear.c
- [x] ft_lstiter.c
- [x] ft_lstmap.c


1. O Contador de Palavras
A primeira necessidade mecânica é dimensionar o array principal. A função percorre a string original s avaliando os dados de forma sequencial.

Ação Lógica: A máquina avança índice por índice, utilizando o caractere delimitador c como referência binária. O processador identifica o início de uma palavra sempre que detecta uma transição de estado: o caractere atual é diferente do delimitador c e o ciclo imediatamente anterior estava posicionado sobre um delimitador (ou no início absoluto da string). Cada transição desse tipo incrementa o contador.

Retorno: A quantidade exata de palavras detectadas na string inteira (size_t). A função ft_split utilizará este retorno para definir o tamanho da alocação bidimensional principal (lembrando de somar o espaço para o terminador NULL do array).

2. O Medidor de Palavra
Com o array principal criado, o processador inicia uma nova iteração pela string para extrair os textos. Para não desperdiçar ou invadir memória, a máquina precisa saber o tamanho cirúrgico de cada fragmento antes de alocá-lo.

Ação Lógica: A função recebe um ponteiro posicionado no exato caractere onde a palavra atual se inicia. A partir dali, ela avança a leitura estritamente até colidir com o próximo delimitador c ou atingir o fim da string original.

Retorno: O comprimento daquela palavra específica (size_t). A função principal usará essa métrica para executar o malloc do bloco individual, solicitando ao sistema o espaço físico apenas para aquele fragmento textual (somando o espaço do terminador estrito daquela string).

3. O Extrator de Caracteres
Com a métrica definida e o bloco de memória individual alocado, a extração física ocorre. Esta lógica pode habitar a própria repetição da split ou ser isolada em uma terceira auxiliar.

Ação Lógica: O processador copia os caracteres originais para o bloco recém-alocado, avançando o mesmo número de posições calculado pelo medidor. No final da cópia, a máquina grava manualmente o \0 na última posição do bloco.

Retorno: O ponteiro isolado (char *) daquela string pronta, que será imediatamente atribuído ao índice atual do array de ponteiros da split.

4. O Sistema de Destruição (Prevenção de Memory Leak)
Exatamente. A arquitetura de alocação bidimensional não possui "rollback" (reversão) automático. O sistema operacional não limpa o progresso parcial de uma operação que foi abortada.

O Cenário de Falha:
Imagine que a string original possui 10 palavras. O motor de alocação roda o laço e cria as primeiras 5 palavras com sucesso (executou 5 mallocs independentes e os guardou no array principal). Ao tentar alocar a 6ª palavra, a memória do computador esgota e o malloc retorna NULL.

A Realidade da Máquina:
Se a ft_split simplesmente abortar e retornar NULL neste momento, o endereço do array principal será perdido. As 5 palavras alocadas anteriormente continuarão existindo fisicamente na memória dinâmica (heap), mas o processador não terá mais como acessá-las. Isso é um memory leak (vazamento de memória) grave.

A Ação Lógica da Função Auxiliar:
Esta função atuará como um protocolo de emergência. Ela deve receber o array principal (char ) e o índice exato onde a falha ocorreu.

Um laço de repetição itera pelos índices já preenchidos (de 0 até o índice da falha).

A máquina executa a instrução free() em cada ponteiro individual, devolvendo os blocos de caracteres para o sistema operacional.

Após destruir todas as strings filhas, a máquina executa um free() final no array principal.

O Retorno:
Retorna NULL. A ft_split recebe este valor e encerra a sua própria execução retornando NULL para o programa original, sinalizando que a operação falhou inteiramente, mas garantindo que nenhum byte de memória foi corrompido ou retido indevidamente.