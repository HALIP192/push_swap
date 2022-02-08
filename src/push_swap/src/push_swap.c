/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/09 00:48:18 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

static void	fr2(t_data *data)
{
	ra(data);
}

static void	start_check(t_data *data)
{
	if (is_sorted(data) || data->size_a == 1)
		return ;
	data->b_head = data->b;
	data->b_root = data->b;
	if (data->size_a == 2)
		ra(data);
	else if (data->size_a > 2 && data->size_a < 100)
		sort_from3TO99(data);
	else if (data->size->a > 100 && data->size_a < 500)
		sort_from100(data, 5);
}	

static int	start_parse(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	a1 = (int *)malloc(sizeof(int) * (argc - 1));
	data->a = (int *)malloc(sizeof(int) * (argc - 1));
	data->b = (int *)malloc(sizeof(int) * (argc - 1));
	data->size_a = argc - 1;
	if (!a || !a1 || !data->a || !data->b)
		return (0);
	while (i < argc - 1)
	{
		a1[i] = ft_atoi(argv[i]);
		data->a[i] = a1[i];
		i++;
	}
	data->a_head = a + argc - 2;
	data->a_root = a;
	ft_sort(a1, data->size);
	ft_renum(a1, data);
	free(a1);
	start_check(data);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc <= 0 || !start_parse(argc, argv))
		exit(0);
	
	return (0);
}
