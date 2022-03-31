/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:07:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/31 14:55:44 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	resolve(t_program *prg)
{
	t_state		*states;

	if (!(states = new_empty_state(&prg->stack_a, &prg->stack_b, prg->stack_a.max_size)))
		return (1);
	if (prg->stack_a.size > 5 && (create_states_resolution(&states) || large_resolve(states)))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_program	prg;

	if(--ac < 1 || (!ft_strcmp(av[1], "-v") && ac == 1))
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(av[1], "-v"))
	{
		prg.debug = 1;
		if(init_stacks(--ac, &av[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}	
	else if (init_stacks(ac, &av[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	prg.instr = NULL;
	if(is_stack_ordered(&prg.stack_a, ASC) && resolve(&prg))
	{
		printf("aaaaâ");
	}
	return (0);	
}