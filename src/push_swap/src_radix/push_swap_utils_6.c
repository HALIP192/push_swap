/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:03 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/27 00:26:01 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_parse2(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int32_t	*a1;

	i = argc - 1;
	data = (t_data *)malloc(sizeof(t_data));
	a1 = (int32_t *)malloc(sizeof(int32_t) * (argc));
	data->a = (int32_t *)malloc(sizeof(int32_t) * (argc));
	data->b = (int32_t *)malloc(sizeof(int32_t) * (argc));
	data->size_a = argc;
	if (!data || !a1 || !data->a || !data->b)
		return (error(data, a1));
	while (i >= 0)
	{
		a1[argc - i - 1] = ft_atoi(argv[i]);
		data->a[argc - i - 1] = a1[argc - i - 1];
		i--;
	}
	data->a_head = data->a + argc - 1;
	data->a_root = data->a;
	return (go_more(data, a1));
}

int	ft_linecounter(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_letters(char *str, int *i, char c)
{
	int	letters;

	letters = 0;
	while (str[*i] == c && str[*i])
		(*i)++;
	while (str[*i] != c && str[*i] != '\0')
	{
		letters++;
		(*i)++;
	}
	return (letters);
}

char	**memory_giver(char *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (ft_linecounter(str, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = get_letters(str, &i, c);
		if (letters > 0)
		{
			res[j] = (char *)malloc(sizeof(char) * letters + 1);
			if (res[j++] == NULL)
				return (NULL);
		}
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		str_number;
	int		size;

	if (str == NULL)
		return (NULL);
	size = ft_linecounter(str, c);
	res = memory_giver(str, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	str_number = 0;
	while (str_number < size)
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
			res[str_number][j++] = str[i++];
		res[str_number][j] = '\0';
		str_number++;
	}
	return (res);
}
