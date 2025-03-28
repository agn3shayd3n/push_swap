/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 12:03:59 by agnesgar          #+#    #+#             */
/*   Updated: 2024-11-24 12:03:59 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> /* printing commands */
# include <limits.h> /* min and max macros */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* error handling */
int				syntax_error(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

/* initiation of stack */
char			**ft_split(char *s, char c);
void			start_stack_a(t_stack_node **stack_a, char **argv);

/* initiation of nodes */
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			current_index(t_stack_node *stack);
void			is_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			ready2push(t_stack_node **stack, t_stack_node *top, char name);

/* utils for stacking */
bool			is_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/* basic commands */

// swap
void			sa(t_stack_node	**a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
// rotate
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
// rotate reverse
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* full algorithm */
void			sort_three(t_stack_node **stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			turk_algorithm(t_stack_node **a, t_stack_node **b);

#endif
