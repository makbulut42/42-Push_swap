/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:28:53 by makbulut           #+#    #+#             */
/*   Updated: 2022/04/19 06:06:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_stack_ordered(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] >= stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == num)
			return (1);
	}
	return (0);
}

int	init_instructions(t_program *prg)
{
	int			ret;
	char		buff[1];

	prg->instr = NULL;
	ret = get_instruction(&prg->instr);
	while (ret > 0)
		ret = get_instruction(&prg->instr);
	if (ret < 0)
	{
		buff[0] = ' ';
		while (buff[0] && read(STDIN_FILENO, &buff, 1))
			;
		free_instructions(prg->instr);
		free(prg->stack_a.array);
		free(prg->stack_b.array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_program		prg;

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
	if (init_instructions(&prg))
		return (1);
	if (prg.debug)
		print_instructions(prg.instr);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	execute_instructions(prg.instr, &prg.stack_a, &prg.stack_b, prg.debug);
	if (is_stack_ordered(&prg.stack_a) || prg.stack_b.size)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (free_prg(&prg));
}
