/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/04/28 06:45:27 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define _YELLOW	"\x1b[34m"
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

t_stack			*copy_stack(t_stack	*stack);
t_state			*new_empty_state(t_stack *stack_a, \
				t_stack *stack_b, size_t maxsize, t_state *state);
t_stack			*new_empty_stack(size_t max_size);
t_state			*new_state_instruction(t_state **states, \
				t_state *old_state, char *line);
t_state			*add_state(t_state	**states, t_state *state_from);
t_instruction	*add_instruction(t_instruction **instructions, char *line);
t_instruction	*add_n_instructions(t_instruction	**instructions, \
				char *line, size_t n);
t_instruction	*copy_and_concat_instructions(t_instruction **instr, \
				t_instruction *new);
t_instruction	*copy_instructions(t_instruction *instructions);
char			*ft_strdup(char *str);
size_t			ft_strlen(const char *str);
size_t			closer_pos_to_inf(int nb, t_stack *stack);
size_t			less_mvt_at_end(size_t minimal_mvt, \
				size_t *min_mvt, t_stack *stack_a, t_stack *stack_b);
size_t			less_mvt_at_begin(size_t minimal_mvt, \
				size_t *min_mvt, t_stack *stack_a, t_stack *stack_b);
int				large_resolve(t_state *states);
int				ft_strcmp(const char *s1, const char *s2);
int				is_stack_ordered(t_stack *stack, int order);
int				size_nbr(int n);
int				create_states_resolution(t_state **states);
int				can_pb(t_stack	*stack_a, t_stack *stack_b);
int				bruteforse_order_a(t_program *prg);
int				init_stacks(int ac, char *av[], \
				t_stack *stack_a, t_stack *stack_b);
int				ft_atoi(const char *str, int *num);
int				stack_contains(t_stack *stack, int num);
int				get_max_size_nbr_stack(t_stack *stack);
int				align_stack_a(t_program *prg);
int				bruteforce_choice_a(t_state **new_states, t_state *tmp, \
				size_t	pos[2], t_stack *stack_b);
int				check_bruteforce_solution(t_state *states, t_state **result);
int				align_stack_b(t_program *prg);
void			swap_stack(t_stack	*stack);
void			free_states(t_state *states);
void			rotate_stack(t_stack *stack);
void			free_instructions(t_instruction	*instructions);
void			free_stack(t_stack *stack);
void			ft_putnbr(int n);
void			write_n_char(int n, char c);
void			free_prg(t_program	*prg);
void			execute_instructions(t_instruction *instr, \
				t_stack *stack_a, t_stack *stack_b, int debug);
void			push_stack(t_stack *stack1, t_stack *stack2);
void			calcul_align_b(size_t *pos, size_t *mvt, t_stack *stack_b);
void			reverse_rotate_stack(t_stack *stack);
void			print_instructions(t_instruction *instr);
void			print_instruction(t_instruction *instr);
void			print_stacks(t_stack *stack_a, t_stack *stack_b);
void			null_new(t_state *new);
void			null_states(t_state *state);
size_t			count_instructions(t_instruction *instr);
t_state			*n_solution(t_state *tmp_state, t_state *solution);

#endif