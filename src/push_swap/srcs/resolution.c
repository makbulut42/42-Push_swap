/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:57:11 by makbulut         ###   ########.fr       */
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
		else if (i < 0)
		{
			new = new_state_instruction(states, *states, "ra");
			tmp = add_n_instructions(&new->instructions, "ra", DEPTH + i);
		}
		else if (i > 0)
		{
			new = new_state_instruction(states, *states, "rra");
			tmp = add_n_instructions(&new->instructions, "rra", i - 1);
		}
		execute_instructions(tmp, new->stack_a, new->stack_b, 0);
		if (!new || (!tmp && i && i != -DEPTH && i != 1))
			return (1);
	}
	return (0);
}

t_instruction	*rotate_a(t_state *state, size_t min[2], size_t min_mvt[2])
{
	t_instruction	*instr;

	if (min[0] <= min[1] && min_mvt[0] <= state->stack_b->size / 2)
		instr = add_instruction(&state->instructions, "rr");
	else if (min[0] < min[1] && min_mvt[0] > state->stack_b->size / 2)
		instr = add_instruction(&state->instructions, "ra");
	else if (min_mvt[1] > state->stack_b->size / 2)
		instr = add_instruction(&state->instructions, "rrr");
	else
		instr = add_instruction(&state->instructions, "rra");
	return (instr);
}

t_instruction	*rotate(t_state *state)
{
	t_instruction	*instr;
	size_t			mvt[2];
	size_t			min[2];
	size_t			min_mvt[2];

	mvt[0] = closer_pos_to_inf(state->stack_a->array[0], state->stack_b);
	min[0] = less_mvt_at_begin(mvt[0], &min_mvt[0], \
	state->stack_a, state->stack_b);
	min[1] = less_mvt_at_end(mvt[0], &min_mvt[1], \
	state->stack_a, state->stack_b);
	if (mvt[0] > state->stack_b->size / 2)
		mvt[1] = state->stack_b->size - mvt[0];
	else
		mvt[1] = mvt[0];
	if (state->stack_a->size > 1 && (min[0] <= mvt[1] || min[1] <= mvt[1]))
		instr = rotate_a(state, min, min_mvt);
	else if (mvt[0] > state->stack_b->size / 2)
		instr = add_instruction(&state->instructions, "rrb");
	else
		instr = add_instruction(&state->instructions, "rb");
	return (instr);
}

int	large_resolve(t_state *states)
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
			execute_instructions(tmp, tmp_state->stack_a, \
			tmp_state->stack_b, 0);
		}
		tmp_state = tmp_state->next;
	}
	return (0);
}
