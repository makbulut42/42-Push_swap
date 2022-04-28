/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:07:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:37:01 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	count_instructions(t_instruction *instr)
{
	size_t	nb;

	nb = 0;
	while (instr)
	{
		nb++;
		instr = instr->next;
	}
	return (nb);
}

size_t	pick_solution(t_program *prg, t_state *states)
{
	t_state	*solution;
	t_state	*tmp_state;

	solution = NULL;
	tmp_state = states->next;
	solution = n_solution(tmp_state, solution);
	if (!solution)
		solution = states;
	if (solution->instructions)
	{
		execute_instructions(solution->instructions, \
		&prg->stack_a, &prg->stack_b, prg->debug);
		prg->instr = copy_instructions(solution->instructions);
		if (!prg->instr)
		{
			free_states(states);
			return (1);
		}
	}
	return (0);
}

int	realign_and_fill_a(t_program *prg)
{
	t_instruction	*tmp;

	if (prg->stack_b.size > 1 && align_stack_b(prg))
		return (1);
	while (prg->stack_b.size)
	{
		if (prg->stack_b.array[0] > prg->stack_a.array[prg->stack_a.size -1] || \
		(prg->stack_b.array[0] < prg->stack_a.array[0] && \
		prg->stack_a.array[0] < prg->stack_a.array[prg->stack_a.size - 1]))
			tmp = add_instruction(&prg->instr, "pa");
		else
			tmp = add_instruction(&prg->instr, "rra");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	if (align_stack_a(prg))
		return (1);
	return (0);
}

int	resolve(t_program *prg)
{
	t_state		*states;
	t_state		states1;

	states = new_empty_state(&prg->stack_a, &prg->stack_b, \
	prg->stack_a.max_size, &states1);
	if (!states)
		return (1);
	if (prg->stack_a.size > 5 && (create_states_resolution(&states) \
	|| large_resolve(states)))
		return (1);
	if (pick_solution(prg, states))
		return (1);
	free_states(states);
	if (bruteforse_order_a(prg))
		return (1);
	if (realign_and_fill_a(prg))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_program	prg;

	if (--ac < 1 || (!ft_strcmp(av[1], "-v") && ac == 1))
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(av[1], "-v"))
	{
		prg.debug = 1;
		if (init_stacks(--ac, &av[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}	
	else if (init_stacks(ac, &av[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	prg.instr = NULL;
	if (is_stack_ordered(&prg.stack_a, 0) && resolve(&prg))
	{
		free_instructions(prg.instr);
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	print_instructions(prg.instr);
	free_prg(&prg);
	return (0);
}
