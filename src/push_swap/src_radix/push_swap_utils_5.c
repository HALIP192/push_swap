/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:52:35 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/26 21:09:53 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_data *data)
{
	int	bit_nums;
	int	i;
	int	step;

	step = 0;
	bit_nums = find_pow(data);
	while (bit_nums > 0)
	{
		i = 0;
		while (i != data->size_a)
		{
			if ((*data->a_head << (31 - step)) >> 31 == 0)
				pb(data);
			else
			{
				ra(data);
				i++;
			}
		}
		back_a(data);
		bit_nums--;
		step++;
	}
}

void	sort3_fora(t_data *data)
{
	if (*data->a_head < *(data->a_head - 1)
		&& *data->a_root > *(data->a_head - 1))
		return ;
	if (*data->a_head > *(data->a_head - 1))
	{
		if (*(data->a_head - 1) > *data->a_root)
		{
			sa(data);
			rra(data);
		}
		else if (*data->a_head < *data->a_root)
			sa(data);
		else
			ra(data);
	}
	else if (*data->a_head > *data->a_root)
		rra(data);
	else
	{
		rra(data);
		sa(data);
	}
}

void	kostil(t_data *data, int cnt)
{
	int	i;

	i = cnt;
	while (i--)
		ra(data);
	pa(data);
	i = 0;
	while (i++ != cnt)
		rra(data);
}

static void	push_to_a(t_data *data)
{
	int	i;
	int	cnt;

	i = data->size_a - 1;
	cnt = 0;
	while (i >= 0)
	{
		if (data->a[i] > *data->b_head)
			break ;
		i--;
		cnt++;
	}
	if (cnt > data->size_a / 2)
	{
		i = (cnt - data->size_a) * (-1);
		while (i--)
			rra(data);
		pa(data);
		i = (cnt - data->size_a) * (-1);
		while (i--)
			ra(data);
	}
	else
		kostil(data, cnt);
}

void	sort_from3to5(t_data *data)
{
	if (data->size_a == 3)
		return (sort3_fora(data));
	while (data->size_a > 3)
		pb(data);
	sort3_fora(data);
	while (data->size_b > 0)
	{
		if (*data->b_head > *data->a_root)
		{
			pa(data);
			ra(data);
		}
		else if (*data->b_head < *data->a_head)
			pa(data);
		else
		{
			push_to_a(data);
		}
	}
}
