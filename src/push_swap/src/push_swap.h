/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:16:14 by ntitan            #+#    #+#             */
/*   Updated: 2022/02/07 21:31:30 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "unistd.h"

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
}t_data

int		ft_atoi(char *mas);
int		main(int argc, char **argv);

#endif
