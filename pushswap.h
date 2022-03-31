/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/31 16:28:34 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define _YELLOW	"\x1b[33m"
# define _END		"\x1b[0m"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define DEPTH	5

# define ASC	0
# define DESC 1

typedef struct s_stack
{
	int				*array;
	size_t			size;
	size_t			max_size;
}					t_stack;

typedef struct s_instruction
{
	char			*line;
	void			*next;
	void			*prev;
}					t_instruction;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
	int				debug;
}					t_program;

typedef struct s_state
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_instruction	*instructions;
	t_instruction	*last_instr;
	void			*next;
}					t_state;

int			ft_strcmp(const char *s1, const char *s2);
int			init_stacks(int ac, char *av[], t_stack *stack_a, t_stack *stack_b);
int			ft_atoi(const char *str, int *num);
int			stack_contains(t_stack *stack, int num);
size_t		ft_strlen(const char *str);
void		print_stacks(t_stack *stack_a, t_stack *stack_b);
int			get_max_size_nbr_stack(t_stack *stack);
void		write_n_char(int n, char c);
void		ft_putnbr(int n);
int			size_nbr(int n);
int			is_stack_ordered(t_stack *stack, int order);
t_stack		*copy_stack(t_stack	*stack);
t_state		*new_empty_state(t_stack *stack_a, t_stack *stack_b, size_t maxsize);
t_stack		*new_empty_stack(size_t max_size);
char	*ft_strdup(char *str);
t_state		*new_state_instruction(t_state **states, t_state *old_state, char *line);
t_instruction	*add_instruction(t_instruction **instructions, char *line);
t_instruction	*copy_instructions(t_instruction *instructions);
t_state	*add_state(t_state	**states, t_state *state_from);
void	execute_instructions(t_instruction *instr, t_stack *stack_a, t_stack *stack_b, int debug);
void	free_stack(t_stack *stack);
void	free_instructions(t_instruction	*instructions);
void	free_prg(t_program	*prg);
void	push_stack(t_stack *stack1, t_stack *stack2);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	swap_stack(t_stack	*stack);
t_instruction	*add_n_instructions(t_instruction	**instructions, char *line, size_t n);
void	print_instruction(t_instruction *instr);
int	create_states_resolution(t_state **states);

#endif