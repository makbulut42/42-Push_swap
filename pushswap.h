/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/24 09:02:10 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define _YELLOW	"\x1b[33m"
# define _END		"\x1b[0m"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_stack
{
	int				*array;
	size_t			size;
	size_t			max_size;
}					t_stack;

typedef struct		s_instruction
{
	char			*line;
	void			*next;
	void			*prev;
}					t_instruction;

typedef struct		s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
	int				debug;
}					t_program;

int	ft_strcmp(const char *s1, const char *s2);
int	init_stacks(int ac, char *av[], t_stack *stack_a, t_stack *stack_b);
int	ft_atoi(const char *str, int *num);
int stack_contains(t_stack *stack, int num);
size_t ft_strlen(const char *str);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int	get_max_size_nbr_stack(t_stack *stack);
void	write_n_char(int n, char c);
void	ft_putnbr(int n);
int	size_nbr(int n);

#endif