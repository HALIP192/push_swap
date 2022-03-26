/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:42:06 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/26 22:24:21 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ligit(t_data *data)
{
	int	i;
	int	j;

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

int	go_more(t_data *data, int32_t *a1)
{
	if (!check_ligit(data))
		return (error(data, a1));
	ft_sort(a1, data->size_a);
	ft_renum(a1, data->a, data->size_a);
	free(a1);
	start_check(data);
	return (1);
}

void	ft_sort(int32_t *a, int size)
{
	int		i;
	int		j;
	size_t	b;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (a[j] < a[i])
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
			j++;
		}
		i++;
	}
}

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int32_t	ft_atoi(char *str)
{
	int32_t	result;
	char	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*(str)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if (result < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + (*(str++) - '0');
	}
	return (result * (int32_t)sign);
}
