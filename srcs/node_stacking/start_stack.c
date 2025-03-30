/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 12:48:43 by agnesgar          #+#    #+#             */
/*   Updated: 2024-11-24 12:48:43 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoli(const char *nbr)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = (result * 10) + (nbr[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			return (LONG_MAX);
		i++;
	}
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		free_errors(stack);
	new_node->next = NULL;
	new_node->nbr = value;
	new_node->cheapest = 0;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	start_stack_a(t_stack_node **stack_a, char **argv)
{
	long	value;
	int		i;

	if (!stack_a || !argv)
		return ;
	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_errors(stack_a);
		value = ft_atoli(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			free_errors(stack_a);
		if (error_duplicate(*stack_a, (int)value))
			free_errors(stack_a);
		append_node(stack_a, (int)value);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ready2push(t_stack_node **node, t_stack_node *targt, char stck)
{
	while (*node != targt)
	{
		if (stck == 'a')
		{
			if (targt->above_median)
				ra(node, false);
			else
				rra(node, false);
		}
		else if (stck == 'b')
		{
			if (targt->above_median)
				rb(node, false);
			else
				rrb(node, false);
		}
	}
}
