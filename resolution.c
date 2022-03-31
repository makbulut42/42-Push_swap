/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/31 16:38:29 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	create_states_resolution(t_state **states)
{
	int				i;
	t_instruction	*tmp;
	t_state			*new;

	i = -DEPTH - 1;
	while (++i < DEPTH)
	{
		tmp = NULL;
		if (!i)
			new = new_state_instruction(states, *states, "pb");
		else if(i < 0)
		{
			new = new_state_instruction(states, *states, "ra");
			tmp = add_n_instructions(&new->instructions, "ra", DEPTH + i);
		}
		execute_instructions(tmp, new->stack_a, new->stack_b, 0);
		if (!new || (!tmp && i != -DEPTH && i != 1))
			return (1);
	}
	return (0);
}

int	large_resolve(t_state	*states)
{
	t_instruction	*tmp;
	t_state			*tmp_state;

	tmp_state = states->next;
	while (tmp_state)
	{
		while (tmp_state->stack_a->size > 5)
		{
			if (can_pb(tmp_state->stack_a, tmp_state->stack_b))
				tmp = add_instruction(&tmp_state->instructions, "pb");
			else
				tmp = rotate(tmp_state);
			if (!tmp)
			{
				free_states(states);
				return (1);
			}
			execute_instructions(tmp, tmp_state->stack_a, tmp_state->stack_b, 0);
		}
		tmp_state  = tmp_state->next;
	}
	return (0);
}
