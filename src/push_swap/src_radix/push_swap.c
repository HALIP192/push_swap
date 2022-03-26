/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/27 00:24:02 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

int	error(t_data *data, int32_t *a1)
{
	free_data(data);
	free(a1);
	write(2, "Error\n", 6);
	return (0);
}

void	start_check(t_data *data)
{
	if (is_sorted(data->a, data->size_a) || data->size_a == 1)
		return ;
	data->b_head = NULL;
	data->b_root = NULL;
	if (data->size_a == 2)
		ra(data);
	else if (data->size_a > 2 && data->size_a < 6)
		sort_from3to5(data);
	else
		sort_all(data);
	free_data(data);
}

int	start_parse(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int32_t	*a1;

	i = argc - 1;
	data = (t_data *)malloc(sizeof(t_data));
	a1 = (int32_t *)malloc(sizeof(int32_t) * (argc - 1));
	data->a = (int32_t *)malloc(sizeof(int32_t) * (argc - 1));
	data->b = (int32_t *)malloc(sizeof(int32_t) * (argc - 1));
	data->size_a = argc - 1;
	data->size_b = 0;
	if (!data || !a1 || !data->a || !data->b)
		return (error(data, a1));
	while (i > 0)
	{
		a1[argc - i - 1] = ft_atoi(argv[i]);
		data->a[argc - i - 1] = a1[argc - i - 1];
		i--;
	}
	data->a_head = data->a + argc - 2;
	data->a_root = data->a;
	return (go_more(data, a1));
}

int	main(int argc, char **argv)
{
	char	**argv_1;

	if (argc <= 0 || argc < 2)
		exit(0);
	if (argc > 2 && !start_parse(argc, argv))
		return (0);
	if (argc == 2)
	{
		argv_1 = ft_split(argv[1], ' ');
		if (!start_parse2(ft_linecounter(argv[1], ' '), argv_1))
			return (0);
	}
	return (0);
}
