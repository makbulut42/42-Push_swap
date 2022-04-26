/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:02:50 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/26 06:13:48 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pushswap.h"

void	print_numbers_stacks(int max_size, int max_size_nbr[2],
t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = -1;
	while (++i < max_size)
	{
		write(STDOUT_FILENO, "	", 1);
		if ((int)(stack_a->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[0] - \
			size_nbr(stack_a->array[stack_a->size - max_size + i]), ' ');
		if ((int)(stack_a->size - max_size + i) >= 0)
			ft_putnbr(stack_a->array[stack_a->size - max_size + i]);
		else
			write_n_char(max_size_nbr[0], ' ');
		write(STDOUT_FILENO, " ", 1);
		if ((int)(stack_b->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[1] - \
			size_nbr(stack_b->array[stack_b->size - max_size + i]), ' ');
		if ((int)(stack_b->size - max_size + i) >= 0)
			ft_putnbr(stack_b->array[stack_b->size - max_size + i]);
		else
			write_n_char(max_size_nbr[1], ' ');
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	print_bottom_stack(int max_size_nbr[2])
{
	write(STDOUT_FILENO, "	", 1);
	write_n_char(max_size_nbr[0], '_');
	write(STDOUT_FILENO, " ", 1);
	write_n_char(max_size_nbr[1], '_');
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "	", 1);
	write_n_char(max_size_nbr[0] - 1, ' ');
	write(STDOUT_FILENO, "a ", 2);
	write_n_char(max_size_nbr[1] - 1, ' ');
	write(STDOUT_FILENO, "b", 2);
	write(STDOUT_FILENO, "\n", 1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	max_size_nbr[2];
	int	max_size;

	max_size = stack_a->size;
	if (stack_b->size > stack_a->size)
		max_size = stack_b->size;
	write(STDOUT_FILENO, _YELLOW, ft_strlen(_YELLOW));
	write(STDOUT_FILENO, "stacks\n", 7);
	write(STDOUT_FILENO, _END, ft_strlen(_END));
	max_size_nbr[0] = get_max_size_nbr_stack(stack_a);
	max_size_nbr[1] = get_max_size_nbr_stack(stack_b);
	print_numbers_stacks(max_size, max_size_nbr, stack_a, stack_b);
	print_bottom_stack(max_size_nbr);
}

void	print_instruction(t_instruction *instr)
{
	write(STDOUT_FILENO, instr->line, ft_strlen(instr->line));
	write(STDOUT_FILENO, "\n", 1);
}

void	print_instructions(t_instruction *instr)
{
	while (instr)
	{
		print_instruction(instr);
		instr = instr->next;
	}
}
// int main(void)
// {
// 	int max_size = 10;
// 	int max_size_nbr[2];
// 	t_stack *a;
// 	t_stack *b;
// 	print_numbers_stacks(max_size_nbr, max_size_nbr, &a, &b)
// }
