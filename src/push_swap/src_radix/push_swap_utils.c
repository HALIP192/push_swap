/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:38 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/19 18:12:33 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_a(t_data *data)
{
    int i;
    int buf;

	while (data->size_b)
		pa(data);
}

int    ft_max(int32_t *mas, int size)
{
    int max;
    int i;

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

/*void	check_b(t_data *data, int num) {
    int i;
    int buf;
    int max;

    i = 0;
    max = -1;
    if (data->size_b < 2)
        return ;
    while (i < data->size_b) {
        if (data->b[i] > num && (max == -1 || data->b[max] > data->b[i]))
            max = i;
        i++;
    }
    if (max >= data->size_b / 2 && max != data->size_b)
    {
        buf = (max - data->size_b) * (-1);
        while (buf--)
            rb(data);
    }
    else if (max != -1)
        while (max--)
            rrb(data);
    else if (max == -1)
    {
        i = ft_max(data->b, data->size_b);
        if (i >= data->size_b / 2  && i != 0)
        {
            buf = (i - data->size_b) * (-1);
            while (buf-- > 0)
                rb(data);
        }
        else if (i != 0)
            while (i--)
                rrb(data);
    }
}

int		*find_nums(t_data *data, int headChunk, int numsofchunks)
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
		if (data->a[data->size_a - i - 1] <= size / numsofchunks * headChunk
			&& data->a[data->size_a - i - 1] > size / numsofchunks * (headChunk - 1)
            && hold[0] == -1)
			hold[0] = i;
		if (data->a[i] <= size / numsofchunks * headChunk
			&& data->a[i] > size  / numsofchunks * (headChunk - 1)
            && hold[1] == -1)
			hold[1] = i + 1;
		i++;
        if (hold[0] > -1 && hold[1] > - 1)
            break ;
	}
	return (hold);
}*/

static int	ft_pow(int powed, int st)
{
	int	buff;

	buff = powed;
	while (st-- > 1)
		powed *= buff;
	return (powed);
}

static int	find_pow(t_data *data)
{
	int	p_ow;
	int	num;

	num = data->a[ft_max(data->a, data->size_a) - 1];
	while (ft_pow(2, p_ow) - 1 < num)
		p_ow++;
	return (p_ow);
}

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

void	sort3_forA(t_data *data)
{
    if (*data->a_head < *(data->a_head - 1) && *data->a_root > *(data->a_head - 1))
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

static void push_to_a(t_data *data)
{
    int i;
    int cnt;

    i = data->size_a - 1;
    cnt = 0;
    while (i >= 0)
    {
        if (data->a[i] > *data->b_head)
            break;
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
    {
        i = cnt;
        while (i--)
            ra(data);
        pa(data);
        i = 0;
        while (i++ != cnt)
            rra(data);
    }
}

void sort_from3TO5(t_data *data)
{
	int i = 0;
	/*while (i < data->size_a)
		printf("%d\n", data->a[i++]);*/
	if (data->size_a == 3)
		return (sort3_forA(data));
	while (data->size_a > 3)
		pb(data);
	sort3_forA(data);
	//write(1, "\n", 1);
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
            /*while (*data->b_head > *data->a_head)
                ra(data);
            pa(data);
            while (*data->a_head > *data->a_root)
                rra(data);*/
            push_to_a(data);
        }
	}
/*	while (i < data->size_a)
		printf("%d\n", data->a[i++]);*/
}

/*void	shift_topush(t_data *data, int choose)
{
	int *i;
	int	b;
    int c;
	if (!data->b_head || !data->b_root)
        return ;
	if (choose == 1 && (data->size_a + data->s
ize_b) > data->size_b)
	{
		i = data->b_head + 1;
		b = *i;
		while (i <= &data->b[data->size_b - 1])
		{
			b = *(i + 1);
			*(i + 1) = *i;
			i++;
		}
		if (data->b_root == &data->b[data->size_b - 1])
			data->b_root = data->b;
		else
			data->b_root++;
        data->size_b++;
	}
	else if (choose == 0 && (data->size_a + data->size_b) > data->size_a)
	{
		i = data->a_head + 1;
        b = *i;
		while (i <= &data->a[data->size_a - 1])
        {
            c = *i;

		}
		if (data->a_root == &data->a[data->size_a - 1])
			data->a_root = data->a;
		else
			data->a_root++;
        data->size_a++;
	}
}*/

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
        *data->b_head++;
    }
    data->size_b++;
    data->size_a--;
    data->a_head--;
    write(1, "pb\n", 3);
    /*int size;

    size = data->size_a+ data->size_b;
	//shift_topush(data, 1);
	if (data->size_a < 1)
		return ;
	if (data->b_head == &data->b[size - 1] )
	{
		data->b[0] = *data->a_head;
		data->b_head = &data->b[0];
	}
	else if (data->b_head == NULL)
	{
		*(data->b) = *data->a_head;
		data->b_head = data->b;
        data->b_root = data->b;
	}
	data->size_b++;
	if (data->a_head == data->a)
		data->a_head = &data->a[data->size_a - 1];
	else
		data->a_head--;
	data->size_a--;
	write(1, "pb\n", 3);*/
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
	/*if (data->size_b < 1)
		return ;
	//shift_topush(data, 0);
	if (data->a_head + 1 > &data->a[data->size_a - 1])
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
	write(1, "pa\n", 3);*/
}

void	rb(t_data *data)
{
	int	last;
	int	buff;
	int	*cur;

	if (data->size_b == 0)
		return ;
	last = data->b[0];
	cur  = data->b;
	while (cur <= data->b_head)
	{
		buff = *cur;
		*cur = last;
		last = buff;
        cur++;
	}
	data->b[0] = last;
    write(1, "rb\n", 3);
	/*if (data->size_b == 0)
		return ;
	data->b_root = data->b_head;
	if (data->b_head - 1 < data->b)
		data->b_head = &data->b[data->size_b - 1];
	else
		data->b_head = data->b_head - 1;
	write(1, "rb\n", 3);*/
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
	/*if (data->size_a == 0)
		return ;
	data->a_root = data->a_head;
	if (data->a_head - 1 < data->a)
		data->a_head = &data->a[data->size_a - 1];
	else
		data->a_head = data->a_head - 1;
	write(1, "ra\n", 3);*/
}

void	rrb(t_data *data)
{
    int last;
    int *cur;
    int buff;

    cur = data->b_head;
    last = *data->b_head;
    while (cur >= data->b)
    {
        buff = *cur;
        *cur = last;
        last  = buff;
        cur--;
    }
    *data->b_head = last;
    write(1, "rrb\n", 4);
	/*if (data->size_b == 0)
		return ;
	data->b_head = data->b_root;
	if (data->b_root + 1 > &data->b[data->size_b - 1])
		data->b_root = data->b;
	else
		data->b_root = data->b_root + 1;
	write(1, "rrb\n" , 4);*/
}

void	rra(t_data *data)
{
    int last;
    int *cur;
    int buff;

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
	/*data->a_head = data->a_root;
	if (data->a_root + 1 > &data->a[data->size_a - 1])
		data->a_root = data->a;
	else
		data->a_root = data->a_root + 1;
	write(1, "rra\n", 4);*/
}

void	sb(t_data *data)
{
	if (data->size_b == 0)
		return ;
	int	buff;

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
	if (data->size_a == 0)
		return ;
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

int		is_sorted(int32_t *a, int size)
{
	int i;

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
	int i;
	int j;

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
                break;
            }
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

int32_t	ft_atoi(char *str)
{
	int32_t		result;
	char		sign;

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
