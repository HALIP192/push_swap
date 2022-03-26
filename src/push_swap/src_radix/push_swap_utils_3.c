/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:47:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/26 20:49:25 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	last;
	int	*cur;
	int	buff;

	cur = data->a_head;
	last = *data->a_head;
	while (cur >= data->a)
	{
		buff = *cur;
		*cur = last;
		last = buff;
		cur--;
	}
	*data->a_head = last;
	write(1, "rra\n", 4);
}

void	sb(t_data *data)
{
	int	buff;

	if (data->size_b == 0)
		return ;
	buff = *data->b_head;
	if (data->b_head == data->b)
	{
		*data->b_head = data->b[data->size_b - 1];
		data->b[data->size_b - 1] = buff;
	}
	else
	{
		*data->b_head = *(data->b_head - 1);
		*(data->b_head - 1) = buff;
	}
	write(1, "sb\n", 3);
}

void	sa(t_data *data)
{
	int	buff;

	if (data->size_a == 0)
		return ;
	buff = *data->a_head;
	if ((data->a_head - 1) < data->a)
	{
		*data->a_head = data->a[data->size_a - 1];
		data->a[data->size_a - 1] = buff;
	}
	else
	{
		*data->a_head = *(data->a_head - 1);
		*(data->a_head - 1) = buff;
	}
	write(1, "sa\n", 3);
}

int	is_sorted(int32_t *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] < a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_renum(int32_t *a1, int32_t *a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a[i] == a1[j])
			{
				a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}
