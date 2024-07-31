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

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*par;
	struct s_node	*chil;
}	t_node;

typedef struct s_stack
{
	char	name;
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	three_val_sort(t_stack **stc, int size);
void	divide_three_bucket(t_stack **a, t_stack **b, int left, int right);
void	push_swap(t_stack **a, t_stack **b, int left, int right);
void	print_error(void);
void	stack_push_front(t_stack **stc, int n, int idx);
void	stack_push_back(t_stack **stc, int n, int idx);
void	stack_front_move(t_stack **a, t_stack **b, int size);
void	swap(int **arr, int index1, int index2);
void	quick_sort(int **arr, int left, int right);
void	node_index_setting(t_stack **stc, int *arr, int size);
void	swap_stack(t_stack **stc);
void	push_stack(t_stack **stc1, t_stack **stc2);
void	rotate_stack(t_stack **stc);
void	reverse_rotate_stack(t_stack **stc);
void	reverse_rotate_stacks(t_stack **a, t_stack **b, int size);
void	divide_three_bucket2(t_stack **a, t_stack **b, int left, int right);
void	push_swap2(t_stack **a, t_stack **b, int left, int right);
void	free_input(char	**input);
void	free_and_error(t_stack **a, t_stack **b);
void	input_dup_check(int *arr, int idx, int n);
void	free_stacks(t_stack **a, t_stack **b);
int		stack_pop_front(t_stack **stc, int *save);
int		stack_pop_back(t_stack **stc, int *save);
int		check_digit(char *str);
int		char_to_integer(char *str);
int		check_input_sort(int *input, int size);
int		*array_allocate(int size);
int		*put_input(t_stack **stc, char **input, int size, int sign);
t_stack	*new_stack(char c);
void	push_swap3(t_stack **a, t_stack **b, int left, int right);
void	divide_three_bucket3(t_stack **a, t_stack **b, int left, int right);
#endif