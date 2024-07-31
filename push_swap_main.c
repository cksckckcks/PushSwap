/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:49:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:12:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_input(t_stack **stc, char **input, int size, int sign)
{
	int	i;
	int	*arr;

	arr = array_allocate(size);
	i = 0 + sign;
	while (i < size)
	{
		if (check_digit(input[i]))
		{
			stack_push_back(stc, char_to_integer(input[i]), -1);
			arr[i - sign] = char_to_integer(input[i]);
			input_dup_check(arr, i - sign, arr[i - sign]);
			i++;
		}
		else
		{
			free(arr);
			return (NULL);
		}
	}
	return (arr);
}

int	check_input_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void	free_input(char	**input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

void	start_push_swap(t_stack **a, t_stack **b, int **arr, int size)
{
	quick_sort(arr, 0, size - 1);
	node_index_setting(a, (*arr), size);
	push_swap(a, b, 0, size);
	free((*arr));
	free_stacks(a, b);
}

int	main(int argc, char **argv)
{
	int		tmp_size;
	int		*tmp_arr;
	char	**tmp_input;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		print_error();
	a = new_stack('a');
	b = new_stack('b');
	tmp_size = argc - 1;
	if (argc == 2)
	{
		tmp_input = ft_split(argv[1], ' ');
		tmp_size = check_input_size(tmp_input);
		tmp_arr = put_input(&a, tmp_input, tmp_size, 0);
		free_input(tmp_input);
	}
	else
		tmp_arr = put_input(&a, argv, argc, 1);
	if (tmp_arr == NULL)
		free_and_error(&a, &b);
	if (check_input_sort(tmp_arr, tmp_size))
		exit(0);
	start_push_swap(&a, &b, &tmp_arr, tmp_size);
}
