/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:38 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/10 17:58:41 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_a(t_data *data)
{
	while (*data->b_head != data->size_b)
		rrb(data);
	while (data->size_b)
		pa(data);
}

void	check_b(t_data *data, int num)
{
	int i;

	i = data->size_b - 1;
	while (i >= 0)
	{
		if (data->b[i] > num)
			break;
		i--;
	}
	i = data->size_b - 1 - i;
	if (i > data->size_b / 2)
	{
		i = data->size_b - i + 1;
		while (i--)
			rrb(data);
	}
	else
		while (i--)
			rb(data);
}

int		*find_nums(t_data *data, int headChunk)
{
	int i;
	int	*hold;
	int	size;

	size = data->size_a + data->size_b;
	i = 0;
	hold = (int *)malloc(sizeof(int) * 2);
	if (!hold)
		return(NULL);
	hold[0] = -1;
	hold[1] = -1;

	while (i < data->size_a)
	{
		if (data->a[data->size_a - i - 1] <= size / 5 * headChunk 
			&& data->a[data->size_a - i - 1] > size / 5 * (headChunk - 1))
			hold[0] = i;
		if (data->a[i] <= size / 5 * headChunk
			&& data->a[i] > size  / 5 * (headChunk - 1))
			hold[1] = i + 1;
		i++;
	}
	return (hold);
}

void	sort_all(t_data *data)
{
	int	numsOfChunks;
	int	*hold;
	int	headChunk;

	numsOfChunks = (data->size_a + data->size_b) / 3;
	headChunk = 1;
	while (headChunk <= numsOfChunks)
	{
		hold = find_nums(data, headChunk);
		if (data->a[data->size_a - hold[0] - 1] == data->a[hold[1] - 1])
			headChunk++;
		if (hold[0] <= hold[1])
			while (hold[0]--)
				ra(data);
		else
			while (hold[1]--)
				rra(data);
		check_b(data, *data->a_head);
		pb(data);
		free(hold);
	}
	back_a(data);
}

void	sort3_forA(t_data *data)
{
	if (*data->a_head > *(data->a_head - 1))
	{
		if (*(data->a_head - 1) > *data->a_root)
		{
			sa(data);
			rra(data);
		}
		else if (*(data->a_head - 1) < *data->a_root)
			sa(data);
		else
			ra(data);
	}
	else if (*data->a_head > *data->a_root)
		rra(data);
	else
	{
		sa(data);
		ra(data);
	}
}

void sort_from3TO5(t_data *data)
{
	int i = 0;
	while (i < data->size_a)
		printf("%d\n", data->a[i++]);
	if (data->size_a == 3)
		return (sort3_forA(data));
	while (data->size_a > 3)
		pb(data);
	sort3_forA(data);
	while (data->size_b > 0)
	{
		if (*data->b_head < *data->a_root)
		{
			while (*data->b_head > *data->a_head)
				ra(data);
			pa(data);
			while (*data->a_head > *data->a_root)
				rra(data);
		}
		else
		{
			pa(data);
			ra(data);
		}
	}
	i = 0;
	while (i <= data->size_a)
		printf("%d\n", data->a[i++]);
}


void	pb(t_data *data)
{
	if (data->size_a < 1)
		return ;
	if (data->b_head == &data->b[data->size_b - 1] && data->b_root > data->b)
	{
		data->b[0] = *data->a_head;
		data->b_head = &data->b[0];
	}
	else
	{
		*(data->b_head + 1) = *data->a_head;
		data->b_head += 1;
	}
	data->size_b++;
	if (data->a_head == data->a)
		data->a_head = &data->a[data->size_a - 1];
	else
		data->a_head--;
	data->size_a--;
	write(1, "pb\n", 3);   
}

void	pa(t_data *data)
{
	if (data->size_b < 1)
		return ;
	if (data->a_head + 1 > &data->a[data->size_a - 1] && data->a_root > data->a)
	{
		data->a[0] = *data->b_head;
		data->a_head = &data->a[0];
	}
	else
	{
		*(data->a_head + 1) = *data->b_head;
		data->a_head += 1;
	}
	data->size_a++;
	if(data->b_head - 1 < data->b)
		data->b_head = &data->b[data->size_b - 1];
	else
		data->b_head = data->b_head - 1;
	data->size_b--;
	write(1, "pa\n", 3);
}

void	rb(t_data *data)
{
	data->b_root = data->b_head;
	if (data->b_head - 1 < data->b)
		data->b_head = &data->b[data->size_b - 1];
	else
		data->b_head = data->b_head - 1;
	write(1, "rb\n", 3);
}

void	ra(t_data *data)
{
	data->a_root = data->a_head;
	if (data->a_head - 1 < data->a)
		data->a_head = &data->a[data->size_a - 1];
	else
		data->a_head = data->a_head - 1;
	write(1, "ra\n", 3);
}

void	rrb(t_data *data)
{
	data->b_head = data->b_root;
	if (data->b_root + 1 > &data->b[data->size_b - 1])
		data->b_root = data->b;
	else
		data->b_root = data->b_root + 1;
	write(1, "rrb\n" , 4);
}

void	rra(t_data *data)
{
	data->a_head = data->a_root;
	if (data->a_root + 1 > &data->a[data->size_a - 1])
		data->a_root = data->a;
	else
		data->a_root = data->a_root + 1;
	write(1, "rra\n", 4);
}

void	sb(t_data *data)
{
	int	buff;

	buff = *data->b_head;
	if (data->b_head - 1 < data->b)
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
	int buff;

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

int		is_sorted(int *a, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] >= a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_renum(int *a1, int *a, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a1[i] == a[j])
				a[j] = i + 1;
			j++;
		}
		i++;
	}
}
static	int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(char *str)
{
	int		result;
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
	return (result * (int)sign);
}

void	ft_sort(int *a, int size)
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
				a[j] = a[i];
				a[i] = b;
			}
			j++;
		}
		i++;
	}
}
