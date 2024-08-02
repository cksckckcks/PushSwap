/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_control.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:49:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:12:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stc)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stc) == NULL)
		return ;
	tmp = (*stc)->head;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->chil;
		free(tmp2);
	}
	free(*stc);
	(*stc) = NULL;
}

void	free_and_error(t_stack **a, t_stack **b)
{
	free_stacks(a, b);
	print_error();
}

void	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}
