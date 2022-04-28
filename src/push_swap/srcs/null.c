/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:32:52 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:20:06 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	null_new(t_state *new)
{
	new->stack_a = NULL;
	new->stack_b = NULL;
	new->instructions = NULL;
	new->last_instr = NULL;
	new->next = NULL;
}

void	null_states(t_state *state)
{
	state->instructions = NULL;
	state->last_instr = NULL;
	state->next = NULL;
}

t_state	*n_solution(t_state *tmp_state, t_state *solution)
{
	while (tmp_state)
	{
		if (!solution || count_instructions(tmp_state->instructions) \
		< count_instructions(solution->instructions))
			solution = tmp_state;
		tmp_state = tmp_state->next;
	}
	return (solution);
}
