/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:07:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/24 13:11:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	// if(is_stack_ordered(&prg.stack_a, ASC) && resolve(&prg))
	// {
	// 	printf("aaaaâ");
	// }
	return (0);	
}