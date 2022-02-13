 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/10 17:37:27 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

static void	start_check(t_data *data)
{
	if (is_sorted(data->a, data->size_a) || data->size_a == 1)
		return ;
	data->b_head = NULL;
	data->b_root = NULL;
	printf("%d\n", data->size_a);
	if (data->size_a == 2)
		ra(data);
	else if (data->size_a > 2 && data->size_a < 6)
		sort_from3TO5(data);
	else
		sort_all(data);
}	

static int	start_parse(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		*a1;

	i = 1;
	data = (t_data *)malloc(sizeof(t_data));
	a1 = (int *)malloc(sizeof(int) * (argc - 1));
	data->a = (int *)malloc(sizeof(int) * (argc - 1));
	data->b = (int *)malloc(sizeof(int) * (argc - 1));
	data->size_a = argc - 1;
	if (!data || !a1 || !data->a || !data->b)
		return (0);
	while (i < argc)
	{
		a1[i - 1] = ft_atoi(argv[i]);
		//printf("%d\n",a1[i - 1]);
		data->a[i - 1] = a1[i - 1];
		i++;
	}
	data->a_head = data->a + argc - 2;
	data->a_root = data->a;
	ft_sort(a1, data->size_a);
	ft_renum(a1, data->a, data->size_a);
	free(a1);
	start_check(data);
	return (1);
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc <= 0 || !start_parse(argc, argv))
		exit(0);
	return (0);
}
