#include "pipex.h"

char	**decision_maker(t_pipe info, char *s, int i)
{
	int	sing;
	int	doub;
	char	first; // if it is 0 - no quotes, 1 - single is first, 2 - double, -1 - there are unclosed quotes

	first = '\0';
	sing = 0;
	doub = 0;
	while (s[++i])
	{
		if (s[i] == '\'')
		{	
			if (!first)
				first = '\'';
			sing++;
		}
		if (s[i] == '\"')
		{
			if (!first)
				first = '\"';
			doub++;
		}
	}
	if ((doub % 2) != 0 || (sing % 2) != 0)
		print_error("non terminated string", 2, info);
	else if (first == 0)
		return (ft_split_cmd(info, s, -1));
	else
		return (ft_split_quotes(info, s, first, -1));
}

	**ft_split_cmd(t_pipe info, char *s, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
	if (decision_maker != 0)
	{
		return (ft_split_quotes(info, s, i))
	}
	arr = (char **) malloc((count_cmd(s) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 1), 1);
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
		}
	arr[++n] = NULL;
	return (arr);
}

int	count_cmd(char *s)
{   int		i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}



int	main(void)
{
//	int			i;
	char 		**res;
	res = ft_split("tripouille", 0);
//	printf("res[0]: %s\n", res[0]);
//	printf("res[1]: %p", res[1]);
	
//	printf("%lu\n", count("tripouille", 0));	
//	for (i = 0; i < 2; i++)
//	{
	  	printf("%s\n", ft_split("tripouille", 0)[i]);
	}
	printf("%d\n", strcmp(ft_split("tripouille", 0)[0], "tripouille"));
	printf("%d\n", ft_split("tripouille", 0)[1] == NULL);
	printf("%p\n", ft_split("tripouille", 0)[1]);
	return (0);
}