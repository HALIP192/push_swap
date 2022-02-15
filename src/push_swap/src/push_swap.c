 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/15 00:31:15 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

static int	error(t_data *data, int *a1)
{
	free_data(data);
	free(a1);
	write(2, "Error\n", 6);
	return (0);
}

static void	start_check(t_data *data)
{
	if (is_sorted(data->a, data->size_a) || data->size_a == 1)
		return ;
	data->b_head = NULL;
	data->b_root = NULL;
	//printf("%d\n", data->size_a);
	if (data->size_a == 2)
		ra(data);
	else if (data->size_a > 2 && data->size_a < 6)
		sort_from3TO5(data);
	else
		sort_all(data);
    free_data(data);
}	

static int	check_ligit(t_data *data, int *a1)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (data->size_a < 1)
		return (0);
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->a[i] == data->a[j])
				return (0);
            j++;
		}
        i++;
	}
	return (1);
}

static int	go_more(t_data *data, int *a1)
{
	if (!check_ligit(data, a1))
		return (error(data, a1));
	ft_sort(a1,data->size_a);
	ft_renum(a1, data->a, data->size_a);
	free(a1);
	start_check(data);
	return (1);
}

static int	start_parse(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		*a1;

	i = argc - 1;
	data = (t_data *)malloc(sizeof(t_data));
	a1 = (int *)malloc(sizeof(int) * (argc - 1));
	data->a = (int *)malloc(sizeof(int) * (argc - 1));
	data->b = (int *)malloc(sizeof(int) * (argc - 1));
	data->size_a = argc - 1;
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

int main(int argc, char **argv)
{
	int i = 0;

	if (argc <= 0 || !start_parse(argc, argv))
		exit(0);
	return (0);
}
