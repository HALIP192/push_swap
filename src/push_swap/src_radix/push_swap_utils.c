/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:38 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/27 00:24:22 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_a(t_data *data)
{
	while (data->size_b)
		pa(data);
}

int	ft_max(int32_t *mas, int size)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (mas[max] < mas[i])
			max = i;
		i++;
	}
	return (max + 1);
}

static int32_t	ft_pow(int powed, int st)
{
	int32_t	buff;

	buff = powed;
	while (st-- > 1)
		powed *= buff;
	return (powed);
}

int	find_pow(t_data *data)
{
	int		p_ow;
	int32_t	num;

	p_ow = 1;
	num = data->a[ft_max(data->a, data->size_a) - 1];
	while (ft_pow(2, p_ow) - 1 < num)
		p_ow++;
	return (p_ow);
}
