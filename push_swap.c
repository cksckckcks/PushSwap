/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:26:19 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:08:41 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_val_sort(stack **stc, int size)
{
	if (size < 2)
		return ;
	if ((*stc)->head->val > (*stc)->head->chil->val)
		swap_stack(stc);
	if (size == 3)
	{
		rotate_stack(stc);
		if ((*stc)->head->val > (*stc)->head->chil->val)
			swap_stack(stc);
		reverse_rotate_stack(stc);
		if ((*stc)->head->val > (*stc)->head->chil->val)
			swap_stack(stc);
	}
}

void	divide_three_bucket(stack **a, stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;

	size = right - left;
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	i = 0;
	while (size-- && (*a)->head)
	{
		if ((*a)->head->idx < pivot1)
			push_stack(b, a);
		else if ((*a)->head->idx >= pivot1 && (*a)->head->idx < pivot2)
		{
			push_stack(b, a);
			rotate_stack(b);
		}
		else
			rotate_stack(a);
	}
}
#include <stdio.h>
void	divide_three_bucket2(stack **a, stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;

	size = right - left;
	pivot1 = left + size / 3;
	pivot2 = left + size / 3 * 2;
	i = 0;
	while (size-- && (*a)->head)
	{
		if ((*a)->head->idx < pivot1)
			rotate_stack(a);
		else if ((*a)->head->idx >= pivot1 && (*a)->head->idx < pivot2)
		{
			push_stack(b, a);
			rotate_stack(b);
		}
		else
			push_stack(b, a);
	}
}

void	push_swap2(stack **a, stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = right - left;
	pivot1 = left + size / 3;
	pivot2 = left + size / 3 * 2;
	divide_three_bucket2(a, b, left, right);
	push_swap(b, a, pivot2, right);
	reverse_rotate_stacks(a, b, pivot1 - left);
	push_swap(b, a, pivot1, pivot2);
	stack_front_move(b, a, pivot1 - left);
	push_swap(b, a, left, pivot1);
}

void	push_swap(stack **a, stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = right - left;
	if (size <= 3)
	{
		three_val_sort(a, size);
		return ;
	}
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	divide_three_bucket(a, b, left, right);
	reverse_rotate_stacks(a, b, right - pivot2);
	push_swap(a, b, pivot2, right);
	push_swap2(b, a, pivot1, pivot2);
	push_swap2(b, a, left, pivot1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*tmp_arr;
	stack	*a;
	stack	*b;

	if (argc < 2)
		print_error();
	a = new_stack('a');
	b = new_stack('b');
	tmp_arr = array_allocate(argc - 1);
	i = 0;
	while (++i < argc)
	{
		if (check_digit(argv[i]))
		{
			stack_push_back(&a, ft_atoi(argv[i]), -1);
			tmp_arr[i - 1] = ft_atoi(argv[i]);
		}
		else
			print_error();
	}
	quick_sort(&tmp_arr, 0, argc - 2);
	node_index_setting(&a, tmp_arr, argc - 1);
	push_swap(&a, &b, 0, argc - 1);
	free(tmp_arr);
	exit(0);
}