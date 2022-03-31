/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:51:19 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/31 16:27:48 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_instruction	*add_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*tmp;
	t_instruction	*new;

	if (!(new = malloc(sizeof(t_instruction))))
		return (NULL);
	if (!(new->line = ft_strdup(line)))
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	while(tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
		*instructions = new;
	return (new);
}

t_instruction	*copy_instructions(t_instruction *instructions)
{
	t_instruction	*new;
	
	new = NULL;
	while (instructions)
	{
		if(!(add_instruction(&new, instructions->line)))
		{
			free_instructions(new);
			return(NULL);
		}
		instructions = instructions->next;
	}
	return (new);
}

void	execute_instructions(t_instruction *instr, t_stack *stack_a, t_stack *stack_b, int debug)
{
	while (instr)
	{
		if (debug)
			print_instruction(instr);
		if (!ft_strcmp(instr->line, "sa") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_b);
		if (!ft_strcmp(instr->line, "sb") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_b);
		if (!ft_strcmp(instr->line, "pa"))
			push_stack(stack_a, stack_b);
		if (!ft_strcmp(instr->line, "pb"))
			push_stack(stack_b, stack_a);
		if(!ft_strcmp(instr->line, "ra") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rb") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_b);
		if (!ft_strcmp(instr->line, "rra") || ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rrb") || ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_b);
		if (debug)
			print_instruction(instr);
		instr = instr->next;
	}
}

t_instruction	*add_n_instructions(t_instruction	**instructions, char *line, size_t n)
{
	t_instruction	*start;

	start = NULL;
	if (n > 0)
	{
		if (!(start = add_instruction(instructions, line)))
			return (NULL);
		n--;
		while (n > 0)
		{
			if (!(add_instruction(instructions, line)))
			{
				free_instructions(start);
				return (NULL);
			}
			n--;
		}
	}
	return (start);
}