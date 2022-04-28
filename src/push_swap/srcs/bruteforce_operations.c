/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:49:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:19:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotate_bruteforce_a(t_state **new_states, \
t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	size_t			j;
	t_instruction	*tmp_instr;

	tmp_instr = tmp->last_instr;
	j = 0;
	while (j++ < tmp->stack_a->size / 2 && tmp_instr && \
	(!ft_strcmp(tmp_instr->line, "ra") || !ft_strcmp(tmp_instr->line, "rr")))
		tmp_instr = tmp->last_instr->prev;
	if (!tmp->last_instr || ((ft_strcmp(tmp->last_instr->line, "rra") \
	&& ft_strcmp(tmp->last_instr->line, "rrr") && j < tmp->stack_a->size / 2)))
	{
		if (pos[0] <= stack_b->size / 2 && !tmp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_states, tmp, "rr"))
				return (1);
		}
		else if (!new_state_instruction(new_states, tmp, "ra"))
			return (1);
	}
	return (0);
}

int	reverse_rotate_bruteforce_a(t_state **new_states, \
t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	size_t			j;
	t_instruction	*tmp_instr;

	tmp_instr = tmp->last_instr;
	j = 0;
	while (j++ < tmp->stack_a->size / 2 && tmp_instr && \
	(!ft_strcmp(tmp_instr->line, "rra") || !ft_strcmp(tmp_instr->line, "rrr")))
		tmp_instr = tmp->last_instr->prev;
	if (!tmp->last_instr || ((ft_strcmp(tmp->last_instr->line, "ra") \
	&& ft_strcmp(tmp->last_instr->line, "rr") && j < tmp->stack_a->size / 2)))
	{
		if (pos[0] > stack_b->size / 2 && !tmp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_states, tmp, "rrr"))
				return (1);
		}
		else if (!new_state_instruction(new_states, tmp, "rra"))
			return (1);
	}
	return (0);
}

int	bruteforce_choice_a(t_state **new_states, \
t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	if (tmp->stack_b->size < 2 && (!tmp->last_instr || \
	ft_strcmp(tmp->last_instr->line, "pa")) && \
	!new_state_instruction(new_states, tmp, "pb"))
		return (1);
	if (tmp->stack_b->size > 0 && (!tmp->last_instr || \
	ft_strcmp(tmp->last_instr->line, "pb")) && \
	!new_state_instruction(new_states, tmp, "pa"))
		return (1);
	if (!tmp->last_instr || (ft_strcmp(tmp->last_instr->line, "sa") \
	&& ft_strcmp(tmp->last_instr->line, "sb") \
	&& ft_strcmp(tmp->last_instr->line, "ss")))
	{
		if (!new_state_instruction(new_states, tmp, "sa"))
			return (1);
		if (tmp->stack_b->size > 1 && \
		!new_state_instruction(new_states, tmp, "sb"))
			return (1);
		if (tmp->stack_b->size > 1 && \
		!new_state_instruction(new_states, tmp, "ss"))
			return (1);
	}
	if (rotate_bruteforce_a(new_states, tmp, pos, stack_b))
		return (1);
	return (reverse_rotate_bruteforce_a(new_states, tmp, pos, stack_b));
}
