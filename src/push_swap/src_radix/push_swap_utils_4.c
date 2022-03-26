/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:49:37 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/26 21:08:26 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	if (data->size_a < 1)
		return ;
	if (!data->b_head || !data->b_root)
	{
		data->b_head = data->b;
		*data->b = *(data->a_head);
		data->b_root = data->b;
	}
	else
	{
		*(data->b_head + 1) = *data->a_head;
		data->b_head++;
	}
	data->size_b++;
	data->size_a--;
	data->a_head--;
	write(1, "pb\n", 3);
}

void	pa(t_data *data)
{
	if (data->size_b < 1)
		return ;
	*(data->a_head + 1) = *data->b_head;
	data->a_head++;
	data->size_a++;
	data->size_b--;
	data->b_head--;
	write(1, "pa\n", 3);
}

void	rb(t_data *data)
{
	int	last;
	int	buff;
	int	*cur;

	if (data->size_b == 0)
		return ;
	last = data->b[0];
	cur = data->b;
	while (cur <= data->b_head)
	{
		buff = *cur;
		*cur = last;
		last = buff;
		cur++;
	}
	data->b[0] = last;
	write(1, "rb\n", 3);
}

void	ra(t_data *data)
{
	int	last;
	int	*cur;
	int	buff;

	cur = data->a;
	last = data->a[0];
	while (cur <= data->a_head)
	{
		buff = *cur;
		*cur = last;
		last = buff;
		cur++;
	}
	data->a[0] = last;
	write(1, "ra\n", 3);
}

void	rrb(t_data *data)
{
	int	last;
	int	*cur;
	int	buff;

	cur = data->b_head;
	last = *data->b_head;
	while (cur >= data->b)
	{
		buff = *cur;
		*cur = last;
		last = buff;
		cur--;
	}
	*data->b_head = last;
	write(1, "rrb\n", 4);
}
