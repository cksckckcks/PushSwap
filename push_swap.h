/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:53:35 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 16:53:36 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int			val;
	int			idx;
	struct node	*par;
	struct node	*chil;
}	node;

typedef struct stack
{
	char	name;
	int		size;
	node	*head;
	node	*tail;
}	stack;

void	three_val_sort(stack **stc, int size);
void	divide_three_bucket(stack **a, stack **b, int left, int right);
void	push_swap(stack **a, stack **b, int left, int right);
void	print_error(void);
void	stack_push_front(stack **stc, int n, int idx);
void	stack_push_back(stack **stc, int n, int idx);
void	stack_front_move(stack **a, stack **b, int size);
void	swap(int **arr, int index1, int index2);
void	quick_sort(int **arr, int left, int right);
void	node_index_setting(stack **stc, int *arr, int size);
void	swap_stack(stack **stc);
void	push_stack(stack **stc1, stack **stc2);
void	rotate_stack(stack **stc);
void	reverse_rotate_stack(stack **stc);
void	reverse_rotate_stacks(stack **a, stack **b, int size);
int		stack_pop_front(stack **stc, int *save);
int		stack_pop_back(stack **stc, int *save);
int		check_digit(char *str);
int		ft_atoi(char *str);
int		*array_allocate(int size);
stack	*new_stack(char c);

#endif