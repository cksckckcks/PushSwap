/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:52:56 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:23:47 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i])
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * sign);
}
