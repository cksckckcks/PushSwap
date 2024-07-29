/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:51:08 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:03:37 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*new_stack(char c)
{
	stack	*ret;

	ret = (stack *)malloc(sizeof(stack));
	ret->head = NULL;
	ret->tail = NULL;
	ret->size = 0;
	ret->name = c;
	return (ret);
}

int	*array_allocate(int size)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * size);
	if (!ret)
		print_error();
	return (ret);
}
