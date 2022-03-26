/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:16:14 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/27 00:23:49 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdint.h"

typedef struct s_data
{
	int32_t	*a;
	int32_t	*b;
	int		size_a;
	int		size_b;
	int32_t	*a_head;
	int32_t	*a_root;
	int32_t	*b_head;
	int32_t	*b_root;
}t_data;

int32_t		find_pow(t_data *data);
int			start_parse(int argc, char **argv);
int			start_parse2(int argc, char **argv);
void		start_check(t_data *data);
int			error(t_data *data, int32_t *a1);
void		free_data(t_data *data);
int			check_ligit(t_data *data);
int			go_more(t_data *data, int32_t *a1);
int			ft_atoi(char *mas);
int			main(int argc, char **argv);
void		back_a(t_data *data);
void		sort_all(t_data *data);
void		sort3_forA(t_data *data);
void		sort_from3to5(t_data *data);
void		pb(t_data *data);
void		pa(t_data *data);
void		rb(t_data *data);
void		ra(t_data *data);
void		rrb(t_data *data);
void		rra(t_data *data);
void		sb(t_data *data);
void		sa(t_data *data);
int			is_sorted(int32_t *a, int size);
void		ft_renum(int32_t *a1, int32_t *a, int size);
int32_t		ft_atoi(char *str);
void		ft_sort(int32_t *a, int size);
int			ft_max(int32_t *mas, int size);
int			ft_isspace(int c);
int			ft_linecounter(char *str, char c);
char		**memory_giver(char *str, char c);
int			get_letters(char *str, int *i, char c);
char		**ft_split(char *str, char c);

#endif
