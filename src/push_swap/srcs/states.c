/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:57:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:20:29 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_state	*new_empty_state(t_stack *stack_a, t_stack *stack_b, \
size_t max_size, t_state *state)
{
	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	if (!stack_a)
		state->stack_a = new_empty_stack(max_size);
	if (stack_a)
		state->stack_a = copy_stack(stack_a);
	else if (!(state->stack_a))
	{
		free(state);
		return (NULL);
	}
	if (!stack_b)
		state->stack_b = new_empty_stack(max_size);
	if (stack_b)
		state->stack_b = copy_stack(stack_b);
	else if (!(state->stack_b))
	{
		free_stack(state->stack_a);
		free(state);
		return (NULL);
	}
	null_states(state);
	return (state);
}

void	free_states(t_state *states)
{
	t_state			*tmp;
	t_state			*next;

	tmp = states;
	while (tmp)
	{
		next = tmp->next;
		free_stack(tmp->stack_a);
		free_stack(tmp->stack_b);
		free_instructions(tmp->instructions);
		free(tmp);
		tmp = next;
	}
}

t_state	*add_state(t_state **states, t_state *state_from)
{
	t_state		*tmp;
	t_state		*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	null_new(new);
	new->stack_a = copy_stack(state_from->stack_a);
	new->stack_b = copy_stack(state_from->stack_b);
	new->instructions = copy_instructions(state_from->instructions);
	if (!(new->stack_a) ||!(new->stack_b) || (state_from->instructions && \
	!(new->instructions)))
	{
		free_states(new);
		return (NULL);
	}
	tmp = *states;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*states = new;
	return (new);
}

t_state	*new_state_instruction(t_state **states, t_state *old_state,
char *line)
{
	t_state			*state;
	t_instruction	*instr;

	state = add_state(states, old_state);
	if (!state)
		return (NULL);
	instr = add_instruction(&state->instructions, line);
	if (!instr)
	{
		free_states(state);
		return (NULL);
	}
	state->last_instr = instr;
	execute_instructions(instr, state->stack_a, state->stack_b, 0);
	return (state);
}
