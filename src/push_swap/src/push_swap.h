/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:16:14 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/14 23:51:30 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	*a_head;
	int	*a_root;
	int	*b_head;
	int	*b_root;
}t_data;

int		malloc_error(t_data *data, int *a1);
int		ft_atoi(char *mas);
int		main(int argc, char **argv);
void	back_a(t_data *data);
void	check_b(t_data *data, int num);
int		*find_nums(t_data *data, int headChunk, int numsofchunks);
void	sort_all(t_data *data);
void	sort3_forA(t_data *data);
void	sort_from3TO5(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
void	rb(t_data *data);
void	ra(t_data *data);
void	rrb(t_data *data);
void	rra(t_data *data);
void	sb(t_data *data);
void	sa(t_data *data);
int		is_sorted(int *a, int size);
void	ft_renum(int *a1, int *a, int size);
int		ft_atoi(char *str);
void	ft_sort(int *a, int size);
void	shift_topush(t_data *data, int choose);
int		ft_max(int *mas, int size);

#endif
