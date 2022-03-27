/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:56:17 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/24 11:53:01 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char *ft_strdup_char(const char *str, char stop)
{
	int	i;
	char *pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	if (!(pt = malloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int fill_stack_arg(char *arg, t_stack *stack, size_t *stack_nb)
{
	int num;
	char *str;
	
	while (*arg)
	{	
		while (*arg == ' ')
			arg++;
		if (!*arg)
			break;
		str = ft_strdup_char(arg, ' ');
		if (ft_atoi(str, &num))
		{
			free(str);
			return (1);
		}
		free (str);
		if (stack_contains(stack, num))
			return (1);
		stack->array[(*stack_nb)++] = num;
		stack->size++;
		while (*arg && *arg != ' ')
			arg++;
	}
	return (0);
}

int fill_stack(int ac, char **av, t_stack *stack)
{
	size_t i;
	size_t j;
	char *ptr;
	
	i = 0;
	j = 0;
	while (i < (size_t) ac)
	{
		ptr = av[i];
		if (fill_stack_arg(ptr, stack, &j))
			return (1);
		i++;
	}
	return (0);
}

size_t	count_stack_size(int ac, char **av)
{
	size_t i;
	size_t j;
	size_t size;
	
	size = 0;
	i = 0;
	while (i < (size_t)ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!j || av[i][j -1] == ' ') && av[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	init_stacks(int ac, char *av[], t_stack *stack_a, t_stack *stack_b)
{
	size_t	stack_size;

	stack_size = count_stack_size(ac, av);
	if (!(stack_a->array = malloc(sizeof(int) * stack_size)))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	if (!(stack_b->array = malloc(sizeof(int) * stack_size)))
	{
		free(stack_a->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	stack_a->size = 0;
	stack_b->size = 0;
	if (fill_stack(ac, av, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
